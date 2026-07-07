from datetime import datetime
from enum import Enum

from pydantic import BaseModel, Field, ValidationError, model_validator


class Rank(str, Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate_mission_rules(self) -> "SpaceMission":
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with M")

        has_leader = any(
            member.rank in (Rank.COMMANDER, Rank.CAPTAIN)
            for member in self.crew
        )

        if not has_leader:
            raise ValueError(
                "Mission must have at least one Commander or Captain"
            )

        if self.duration_days > 365:
            experienced_count = sum(
                member.years_experience >= 5
                for member in self.crew
            )

            if experienced_count < len(self.crew) / 2:
                raise ValueError(
                    "Long missions need 50% experienced crew"
                )

        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")

        return self


def main() -> None:
    print("Space Mission Validation")
    print("=" * 40)

    crew_members = [
        CrewMember(
            member_id="C001",
            name="Sarah Connor",
            rank=Rank.COMMANDER,
            age=42,
            specialization="Mission Command",
            years_experience=15,
        ),
        CrewMember(
            member_id="C002",
            name="John Shepard",
            rank=Rank.CAPTAIN,
            age=38,
            specialization="Navigation",
            years_experience=10,
        ),
        CrewMember(
            member_id="C003",
            name="Alice Vega",
            rank=Rank.OFFICER,
            age=29,
            specialization="Engineering",
            years_experience=6,
        ),
    ]

    mission = SpaceMission(
        mission_id="M2026_MARS",
        mission_name="Mars Exploration Alpha",
        destination="Mars",
        launch_date=datetime.now(),
        duration_days=500,
        crew=crew_members,
        budget_millions=2500.0,
    )

    print("Valid mission created:")
    print(f"Mission ID: {mission.mission_id}")
    print(f"Mission Name: {mission.mission_name}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Crew size: {len(mission.crew)}")
    print(f"Budget: ${mission.budget_millions} million")

    print("=" * 40)

    try:
        bad_crew = [
            CrewMember(
                member_id="C004",
                name="Bob Ray",
                rank=Rank.OFFICER,
                age=25,
                specialization="Science",
                years_experience=2,
            )
        ]

        SpaceMission(
            mission_id="M9999",
            mission_name="Broken Mission",
            destination="Moon",
            launch_date=datetime.now(),
            duration_days=800,
            crew=bad_crew,
            budget_millions=500.0,
        )

    except ValidationError as error:
        print("Expected validation error:")
        print(error)


if __name__ == "__main__":
    main()
