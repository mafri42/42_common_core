from abc import ABC, abstractmethod
from typing import Any, Protocol


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class DataProcessor(ABC):
    def __init__(self, name: str) -> None:
        self._name = name
        self._store: list[str] = []
        self._total: int = 0
        self._count: int = 0

    def output(self, nb: int) -> list[tuple[int, str]]:
        res = []
        for _ in range(min(nb, len(self._store))):
            value = self._store.pop(0)
            i = self._count
            self._count += 1
            res.append((i, value))
        return (res)

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__("Numeric Processor")

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
                self._total += 1
        else:
            cast_str = str(data)
            self._store.append(cast_str)
            self._total += 1


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__("Text Processor")

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
                self._total += 1
        else:
            self._store.append(data)
            self._total += 1


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__("Log Processor")

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
            self._total += 1
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
                self._total += 1


class DataStream:
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for item in stream:
            handled = False
            for proc in self._processors:
                if proc.validate(item):
                    proc.ingest(item)
                    handled = True
                    break
            if not handled:
                print(f"DataStream error - Can't process"
                      f" element in stream: {item}")

    def print_processors_stats(self) -> None:
        print("\n== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
            return
        for proc in self._processors:
            tot = proc._total
            rem = len(proc._store)
            print(f"{proc._name}: total {tot} items processed,"
                  f" remaining {rem} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        if not self._processors:
            raise IndexError("No Processors")
        else:
            for proc in self._processors:
                data = proc.output(nb)
                if data:
                    plugin.process_output(data)


class CSVClass:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")
        result = ",".join(item[1] for item in data)
        print(result)


class JSONClass:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")
        res = ",".join(f'"item_{item[0]}": "{item[1]}"' for item in data)
        res = "{" + res + "}"
        print(res)


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===")
    print("\nInitialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()
    print("\nRegistering Processors")
    stream.register_processor(NumericProcessor())
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())
    print("\nSend first batch of data on stream: ['Hello world', "
          "[3.14, -1, 2.71], [{'log_level': 'WARNING', 'log_message':"
          " 'Telnet access! Use ssh instead'}, {'log_level': 'INFO',"
          " 'log_message': 'User wil is connected'}], 42, ['Hi', 'five']]")
    first_batch = [
        'Hello world',
        [3.14, -1, 2.71],
        [{'log_level': 'WARNING', 'log_message': 'Telnet access! '
         'Use ssh instead'}, {'log_level': 'INFO', 'log_message': 'User '
         'wil is connected'}],
        42,
        ['Hi', 'five']
    ]
    stream.process_stream(first_batch)
    stream.print_processors_stats()
    print("\nSend 3 processed data from each processor to a CSV plugin:")
    csv_plugin = CSVClass()
    stream.output_pipeline(3, csv_plugin)
    stream.print_processors_stats()
    print("\nSend another batch of data: [21, ['I love AI', 'LLMs are "
          " wonderful', 'Stay healthy'], [{'log_level': 'ERROR', 'log_message'"
          ": '500 server crash'}, {'log_level': 'NOTICE', 'log_message': "
          "'Certificate expires in 10 days'}], [32, 42, 64, 84, 128, 168], "
          "'World hello']")
    second_batch = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [{'log_level': 'ERROR', 'log_message': '500 server crash'
          }, {'log_level': 'NOTICE', 'log_message': 'Certificate expires'
              ' in 10 days'}],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ]
    stream.process_stream(second_batch)
    stream.print_processors_stats()
    print("\nSend 5 processed data from each processor to a JSON plugin:")
    json_plugin = JSONClass()
    stream.output_pipeline(5, json_plugin)
    stream.print_processors_stats()
