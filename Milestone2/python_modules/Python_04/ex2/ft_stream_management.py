import sys


def stream_management() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
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
        except (FileNotFoundError, PermissionError) as e:
            print(
                f"[STDERR] Error opening file '{sys.argv[1]}': {e}",
                file=sys.stderr
            )
        else:
            print("\nTransform data:\n---")
            data = open(sys.argv[1], "r")
            cont = data.read()
            cont = cont.replace("\n", "#\n")
            data.close()
            print(f"\n{cont}")
            print("---")
            print("Enter new file name (or empty): ", end="", flush=True)
            new = sys.stdin.readline().strip()
            if new == "":
                print("Not saving data.")
            else:
                try:
                    print(f"Saving data to '{new}'")
                    new_file = open(new, "w")
                    new_file.write(cont)
                    new_file.close()
                    print(f"Data saved in file '{new}'")
                except (FileNotFoundError, PermissionError) as e:
                    print(
                            f"[STDERR] Error opening file '{new}': {e}",
                            file=sys.stderr
                        )
                    print("Data not saved.")


if __name__ == "__main__":
    stream_management()
