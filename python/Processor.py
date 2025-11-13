# ============================================================
# Processor.py
# Author: Caitlin Box
# PID: 5280694
# Description:
# Manages the overall Employee Performance Tracking System.
# ============================================================

from Employee import Employee

class Processor:
    # Handles file processing, data storage, and user interactions

    def __init__(self, fname: str):
        # Initializes the processor and loads employee data
        self.fname = fname
        self.employees = {}
        try:
            self.readFile()
        except FileNotFoundError:
            print("cannot open file")
            exit()

    def readFile(self) -> None:
        # Reads employee data from file and organizes by department
        with open(self.fname, "r") as f:
            for line in f:
                if line.strip() == "":
                    continue
                emp = Employee.createEmployee(line)
                if emp.dept not in self.employees:
                    self.employees[emp.dept] = []
                self.employees[emp.dept].append(emp)
        # Sort each department by ID
        for dept in self.employees:
            self.employees[dept].sort()

    def printAllEmployees(self) -> None:
        # Prints all employees, sorted by department and ID
        for dept in sorted(self.employees.keys()):
            for emp in self.employees[dept]:
                print(emp)
        print("All employees are printed")

    def findEmployee(self, searched: str) -> list:
        """Searches for employees whose name contains the searched string (case-insensitive)."""
        result = []
        term = searched.lower()
        for dept in self.employees.values():
            for emp in dept:
                if term in emp.name.lower():
                    result.append(emp)
        return result

    def printSearchResult(self, searched: str) -> None:
        # Prints the search results using Employee.__repr__()
        found = self.findEmployee(searched)
        if not found:
            print("No result")
        else:
            print(f"{len(found)} employee/s found")
            for emp in found:
                print(emp)

    def calculate_department_average(self, department: str, criteria: str) -> float:
        # Calculates the average score or salary for a given department
        dept_emps = self.employees.get(department, [])
        if not dept_emps:
            return 0.0
        total = sum(getattr(emp, criteria) for emp in dept_emps)
        return round(total / len(dept_emps), 2)

    def departmentStats(self, dept: str) -> str:
        # Returns formatted department statistics
        dept_emps = self.employees.get(dept, [])
        if not dept_emps:
            return f"{dept} Department: No employees.\n"
        avg_score = self.calculate_department_average(dept, "score")
        avg_salary = self.calculate_department_average(dept, "salary")
        return (f"{dept} Department:\n"
                f"- Employees: {len(dept_emps)}\n"
                f"- Average Performance: {avg_score}\n"
                f"- Average Salary: {avg_salary}\n")

    def totalAvg(self, criteria: str) -> float:
        # Calculates the average of departmental averages (for score or salary)
        if not self.employees:
            return 0.0
        dept_avgs = [self.calculate_department_average(d, criteria) for d in self.employees]
        return round(sum(dept_avgs) / len(dept_avgs), 2)

    def generateReport(self) -> None:
        # Generates a company-wide report and saves it to report_<filename>
        total_employees = sum(len(v) for v in self.employees.values())
        avg_perf = self.totalAvg("score")
        avg_salary = self.totalAvg("salary")

        report_name = f"report_{self.fname}"
        with open(report_name, "w") as f:
            f.write("EMPLOYEE PERFORMANCE REPORT\n")
            f.write("=================\n")
            f.write(f"Generated from: {self.fname}\n\n")
            f.write("Company Statistics:\n")
            f.write(f"Total Employees: {total_employees}\n")
            f.write(f"Overall Average Performance: {avg_perf}\n")
            f.write(f"Average Salary: {avg_salary}\n\n")
            f.write("Department Breakdown\n")
            f.write("-------------\n")
            for dept in sorted(self.employees.keys()):
                f.write(self.departmentStats(dept) + "\n")
        print("Report generated")

    def menu(self) -> None:
        # Displays the interactive menu for user operations
        while True:
            print("Choice 1 For searching users")
            print("Choice 2 For generating report")
            print("Choice 3 For printing all employees")
            print("Choice 4 For exiting")
            print("Enter choice")
            choice = input().strip()

            if choice == "1":
                print("Enter searched string")
                term = input().strip()
                self.printSearchResult(term)
            elif choice == "2":
                self.generateReport()
            elif choice == "3":
                self.printAllEmployees()
            elif choice == "4":
                print("Done")
                break
            
# Main Execution Block
if __name__ == "__main__":
    print("Enter file name")
    fname = input().strip()
    employee_processor = Processor(fname)
    employee_processor.menu()
