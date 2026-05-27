import sys


def ancient_text() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>\n")
    else:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file '{sys.argv[1]}'")
        try:
            file = open(sys.argv[1])
            contenuto = file.read()
            print("---")
            print(f"\n{contenuto}")
            print("\n---")
            file.close()
            print(f"File '{sys.argv[1]}' closed.")
        except (FileNotFoundError, PermissionError) as e:
            print(f"Error opening file '{sys.argv[1]}': {e}\n")


if __name__ == "__main__":
    ancient_text()


# python3 ft_ancient_text.py /etc/shadow per password, linux
