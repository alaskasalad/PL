# ============================================================
# Employee.py
# Author: Caitlin Box
# PID: 5280694
# Description:
# Defines the Employee class used to represent and manage
# employee records in the Employee Performance Tracking System.
# ============================================================

class Employee:
    # Represents a single employee with attributes like id, name, department

    def __init__(self, idNum: int, name: str, dept: str, age: int, score: float, salary: int):
        # Initializes employee attributes
        self.idNum = idNum
        self.name = name
        self.dept = dept
        self.age = age
        self.score = score
        self.salary = salary

    @staticmethod
    def createEmployee(record: str):
        # Parses a comma-separated record string and returns an Employee object.
        fields = record.strip().split(",")
        # Convert numeric fields to appropriate types
        return Employee(
            int(fields[0]),
            fields[1],
            fields[2],
            int(fields[3]),
            float(fields[4]),
            int(fields[5])
        )

    def rating(self) -> str:
        # Returns the performance rating based on score
        if self.score > 90:
            return "Excellent"
        elif self.score > 80:
            return "Good"
        elif self.score > 70:
            return "Fair"
        else:
            return "Bad"

    def __lt__(self, other):
        # Allows sorting employees by their ID number
        return self.idNum < other.idNum

    def __eq__(self, other):
        # Checks if two employees have identical attributes
        return (
            self.idNum == other.idNum and
            self.name == other.name and
            self.dept == other.dept and
            self.age == other.age and
            self.score == other.score and
            self.salary == other.salary
        )

    def __repr__(self) -> str:
        # Returns a formatted string representation of the employee
        return (f"Name:{self.name}\n"
                f"ID:{self.idNum}\n"
                f"Department:{self.dept}\n"
                f"Rating:{self.rating()}\n"
                f"Age:{self.age}\n"
                f"score:{self.score}\n"
                f"Salary:{self.salary}")
