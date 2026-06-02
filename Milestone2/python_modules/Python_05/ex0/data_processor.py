#!/usr/bin/env python3
from typing import Any, List
from abc import ABC, abstractmethod

class DataProcessor(ABC):

    def __init__(self):
        self._data = []
        self._next_rank = 0

    @abstractmethod
    def ingest(self, data: Any) -> None:
        """Process data and return result description"""
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Validate if data is appropriate for this processor"""
        pass

    def output(self) -> tuple[int, str]:
        if not self._data:
            raise Exception("No data available")
        rank, value = self._data[0]
        self._data.pop(0)
        return (rank, value)

class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        """Validate that data is a list of numbers"""
        if not isinstance(data, List[int | float]):
            return False
        for num in data:
            if not isinstance(num, (int, float)):
                return False
        return True
    
    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise Exception("Invalid data")
        if isinstance(data, list):
            for item in data:
                self._data.append((self._next_rank, str(item)))
                self._next_rank += 1
        else:
            self._data.append((self._next_rank, str(data)))
            self._next_rank += 1
        

class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        """Validate that data is a string"""
        return isinstance(data, str)

class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        """Validate that data is a string"""
        return isinstance(data, str)

if __name__ == "__main__":
    