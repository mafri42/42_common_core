from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._store: list[str] = []
        self._total: int = 0
        self._count: int = 0

    def output(self) -> tuple[int, str]:
        value = self._store.pop(0)
        rank = self._count
        self._count += 1
        return (rank, value)

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)) and not isinstance(data, bool):
            return True
        if isinstance(data, (list)):
            for x in data:
                if not isinstance(x, (int, float)) or isinstance(x, bool):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for i in data:
                cast_str = str(i)
                self._store.append(cast_str)
        else:
            cast_str = str(data)
            self._store.append(cast_str)


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (str)):
            return True
        if isinstance(data, list):
            for x in data:
                if not isinstance(x, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for i in data:
                self._store.append(i)
        else:
            self._store.append(data)


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            for key, value in data.items():
                if not isinstance(key, str) or not isinstance(value, str):
                    return False
            return True
        if isinstance(data, list):
            for i in data:
                if not isinstance(i, dict):
                    return False
                for key, value in i.items():
                    if not isinstance(key, str) or not isinstance(value, str):
                        return False
            return True
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, dict):
            res = ""
            first = True
            for value in data.values():
                if first:
                    res += value
                    first = False
                else:
                    res += ":" + value
            self._store.append(res)
        elif isinstance(data, list):
            for i in data:
                res = ""
                first = True
                for value in i.values():
                    if first:
                        res += value
                        first = False
                    else:
                        res += ":" + value
                self._store.append(res)


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    print("\nTesting Numeric Processor...")
    num = 42
    num_proc = NumericProcessor()
    string = "Hello"
    string2 = "foo"
    print(f"Trying to validate input '{num}': {num_proc.validate(num)} ")
    print(f"Trying to validate input '{string}': {num_proc.validate(string)}")
    print(f"Test invalid ingestion of string '{string2}'"
          " without prior validation:")
    try:
        num_proc.ingest(string2)  # type: ignore
    except ValueError as e:
        print(f"Got exception: {e}")
    data_list: list = [1, 2, 3, 4, 5]
    num_proc.ingest(data_list)
    print(f"Processing data: {data_list}")
    print("Extracting 3 value...")
    for _ in range(3):
        i, val = num_proc.output()
        print(f"Numeric value {i}: {val}")

    print("\nTesting Text Processor...")
    text_proc = TextProcessor()
    print(f"Trying to validate input '{num}': {text_proc.validate(num)} ")
    print(f"Trying to validate input '{string}': {text_proc.validate(string)}")
    text_list: list = ["Hello", "Nexus", "World"]
    text_proc.ingest(text_list)
    print(f"Processing data: {text_list}")
    print("Extracting 1 values...")
    for _ in range(1):
        i, val = text_proc.output()
        print(f"Text value {i}: {val}")

    print("\nTesting Log Processor...")
    log_proc = LogProcessor()
    print(f"Trying to validate input '{num}': {log_proc.validate(num)} ")
    print(f"Trying to validate input '{string}': {log_proc.validate(string)}")
    log_list: list = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ]
    log_proc.ingest(log_list)
    print(f"Processing data: {log_list}")
    print("Extracting 2 values...")
    for _ in range(2):
        i, val = log_proc.output()
        print(f"Log entry {i}: {val}")