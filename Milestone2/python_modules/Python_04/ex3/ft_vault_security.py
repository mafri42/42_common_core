from typing import Tuple


def secure_archive(file_name: str, action: str = 'read',
                   content: str = '') -> Tuple[bool, str]:
    try:
        if action == 'read':
            with open(file_name, "r") as file:
                content = file.read()
            return (True, content)
        elif action == 'write':
            with open(file_name, "w") as file:
                file.write(content)
            return (True, 'Content successfully written to file')
        return (False, 'Invalid action')
    except (FileNotFoundError, PermissionError) as e:
        return (False, str(e))


if __name__ == "__main__":
    print("=== Cyber Archives Security ===")
    print("\nUsing 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file"))
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/shadow"))
    print("\nUsing 'secure_archive' to read from a regular file:")
    res = secure_archive("ancient_fragment.txt")
    print(res)
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new.txt", "write", res[1]))
