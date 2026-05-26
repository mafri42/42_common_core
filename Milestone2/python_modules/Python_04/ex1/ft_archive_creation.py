import sys


def archive_creation() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{sys.argv[1]}'")
        try:
            file = open(sys.argv[1])
            contenuto = file.read()
            print("---")
            print(f"\n{contenuto}")
            print("\n---")
            file.close()
            print(f"File '{sys.argv[1]}' closed.")
        except FileNotFoundError as e:
            print(f"Error opening file '{sys.argv[1]}': {e}")
        except PermissionError as e:
            print(f"Error opening file '{sys.argv[1]}': {e}")
        else:
            print("\nTransform data:\n---")
            data = open(sys.argv[1], "r")
            cont = data.read()
            cont = cont.replace("\n", "#\n")
            print(f"\n{cont}")
            print("---")
            new = input("Enter new file name (or empty):")
            if new == "":
                print("Not saving data.")
            else:
                print(f"Saving data to '{new}'")
                new_file = open(new, "x")
                new_file.write(cont)
                new_file.close()
                print(f"Data saved in file '{new}'")


if __name__ == "__main__":
    archive_creation()
