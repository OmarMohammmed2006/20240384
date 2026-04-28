#include "EmployeeView.h"

using namespace std;

void EmployeeView::showMenu() {
    cout << "\n========================================" << endl;
    cout << "     EMPLOYEE MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "1. Add New Employee" << endl;
    cout << "2. View All Employees" << endl;
    cout << "3. Search Employee by ID" << endl;
    cout << "4. Update Employee" << endl;
    cout << "5. Delete Employee" << endl;
    cout << "6. Save Data to File" << endl;
    cout << "7. Load Data from File" << endl;
    cout << "8. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

void EmployeeView::showAllEmployees(const vector<Employee>& employees) {
    if (employees.empty()) {
        showMessage("No employees found!");
        return;
    }

    cout << "\n========================================" << endl;
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Department"
         << setw(15) << "Position"
         << setw(10) << "Salary" << endl;
    cout << "========================================" << endl;

    for (const auto& emp : employees) {
        cout << left << setw(10) << emp.getId()
             << setw(20) << emp.getName()
             << setw(15) << emp.getDepartment()
             << setw(15) << emp.getPosition()
             << "$" << setw(9) << emp.getSalary() << endl;
    }
    cout << "========================================" << endl;
    cout << "Total Employees: " << employees.size() << endl;
}

void EmployeeView::showEmployee(const Employee& employee) {
    cout << "\n--- Employee Details ---" << endl;
    employee.display();
}

void EmployeeView::showMessage(const string& message) {
    cout << "\n[INFO] " << message << endl;
}

void EmployeeView::showError(const string& error) {
    cout << "\n[ERROR] " << error << endl;
}

Employee EmployeeView::getEmployeeInput() {
    Employee emp;
    int id;
    string name, dept, pos;
    double salary;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n--- Enter Employee Details ---" << endl;
    cout << "Employee ID: ";
    cin >> id;
    cin.ignore();

    cout << "Name: ";
    getline(cin, name);

    cout << "Department: ";
    getline(cin, dept);

    cout << "Position: ";
    getline(cin, pos);

    cout << "Salary: $";
    cin >> salary;

    emp.setId(id);
    emp.setName(name);
    emp.setDepartment(dept);
    emp.setPosition(pos);
    emp.setSalary(salary);

    return emp;
}

int EmployeeView::getEmployeeIdInput() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;
    return id;
}

Employee EmployeeView::getUpdatedEmployeeInput(const Employee& oldEmployee) {
    Employee emp = oldEmployee;
    string input;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n--- Update Employee Details (press Enter to keep current value) ---" << endl;
    cout << "Current Name: " << oldEmployee.getName() << endl;
    cout << "New Name: ";
    getline(cin, input);
    if (!input.empty()) emp.setName(input);

    cout << "Current Department: " << oldEmployee.getDepartment() << endl;
    cout << "New Department: ";
    getline(cin, input);
    if (!input.empty()) emp.setDepartment(input);

    cout << "Current Position: " << oldEmployee.getPosition() << endl;
    cout << "New Position: ";
    getline(cin, input);
    if (!input.empty()) emp.setPosition(input);

    cout << "Current Salary: $" << oldEmployee.getSalary() << endl;
    cout << "New Salary: $";
    getline(cin, input);
    if (!input.empty()) emp.setSalary(stod(input));

    return emp;
}

void EmployeeView::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void EmployeeView::waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}