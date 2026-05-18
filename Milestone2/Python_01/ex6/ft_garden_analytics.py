#!/usr/bin/python3
class Plant:
    def __init__(self, name: str, height: float, days: int, growth: float) -> None:
        self.name = name
        self.height = height
        self.days = days
        self.growth = growth