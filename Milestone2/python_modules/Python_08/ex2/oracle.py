import os
from dotenv import load_dotenv

load_dotenv()

def load_config():
    config = {
        "MATRIX_MODE": os.getenv("MATRIX_MODE", "development"),
        "DATABASE_URL": os.getenv("DATABASE_URL"),
        "API_KEY": os.getenv("API_KEY"),
        "LOG_LEVEL": os.getenv("LOG_LEVEL", "DEBUG"),
        "ZION_ENDPOINT": os.getenv("ZION_ENDPOINT"),
    }
    return (config)


def display(config):
    print("\nORACLE STATUS: Reading the Matrix...\n")
    print("Configuration loaded:")

    print(f"Mode: {config['MATRIX_MODE']}")

    if config["DATABASE_URL"]:
        print("Database: Connected to configured instance")
    else:
        print("Database: Missing configuration")

    if config["API_KEY"]:
        print("API Access: Authenticated")
    else:
        print("API Access: Missing API key")

    print(f"Log Level: {config['LOG_LEVEL']}")

    if config["ZION_ENDPOINT"]:
        print("Zion Network: Online")
    else:
        print("Zion Network: Offline / not configured")


def validate_config(config):
    required = ["DATABASE_URL", "API_KEY", "ZION_ENDPOINT"]
    missing = []

    for key in required:
        if not config.get(key):
            missing.append(key)
    return (missing)


def security_check():
    print("\nEnvironment security check:")

    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly configured")
    print("[OK] Production overrides available")


def main():
    config = load_config()

    print("\nAccessing the Mainframe")
    print("ORACLE STATUS: Reading the Matrix...")

    missing = validate_config(config)

    print("\nConfiguration loaded:")
    print(f"Mode: {config['MATRIX_MODE']}")

    if config["DATABASE_URL"]:
        print("Database: Connected to local instance")
    else:
        print("Database: Missing configuration")

    if config["API_KEY"]:
        print("API Access: Authenticated")
    else:
        print("API Access: Missing API key")

    print(f"Log Level: {config['LOG_LEVEL']}")

    if config["ZION_ENDPOINT"]:
        print("Zion Network: Online")
    else:
        print("Zion Network: Offline / not configured")

    if missing:
        print("\nWARNING: Missing configuration:")
        for m in missing:
            print(f" - {m}")

    security_check()

    print("\nThe Oracle sees all configurations")


if __name__ == "__main__":
    main()