#include "EmployeeController.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

EmployeeController::EmployeeController() {
    view = make_unique<EmployeeView>();
}

bool EmployeeController::isValidId(int id) const {
    if (id <= 0) return false;
    return findEmployeeIndex(id) == -1;
}

int EmployeeController::findEmployeeIndex(int id) const {
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void EmployeeController::addEmployee() {
    Employee emp = view->getEmployeeInput();
    
    if (!isValidId(emp.getId())) {
        view->showError("Employee ID already exists or is invalid!");
        return;
    }
    
    employees.push_back(emp);
    view->showMessage("Employee added successfully!");
}

void EmployeeController::viewAllEmployees() {
    view->showAllEmployees(employees);
    view->waitForEnter();
}

void EmployeeController::searchEmployee() {
    if (employees.empty()) {
        view->showError("No employees in the system!");
        view->waitForEnter();
        return;
    }
    
    int id = view->getEmployeeIdInput();
    int index = findEmployeeIndex(id);
    
    if (index != -1) {
        view->showEmployee(employees[index]);
    } else {
        view->showError("Employee not found!");
    }
    
    view->waitForEnter();
}

void EmployeeController::updateEmployee() {
    if (employees.empty()) {
        view->showError("No employees in the system!");
        view->waitForEnter();
        return;
    }
    
    int id = view->getEmployeeIdInput();
    int index = findEmployeeIndex(id);
    
    if (index != -1) {
        Employee updatedEmp = view->getUpdatedEmployeeInput(employees[index]);
        employees[index] = updatedEmp;
        view->showMessage("Employee updated successfully!");
    } else {
        view->showError("Employee not found!");
    }
    
    view->waitForEnter();
}

void EmployeeController::deleteEmployee() {
    if (employees.empty()) {
        view->showError("No employees in the system!");
        view->waitForEnter();
        return;
    }
    
    int id = view->getEmployeeIdInput();
    int index = findEmployeeIndex(id);
    
    if (index != -1) {
        employees.erase(employees.begin() + index);
        view->showMessage("Employee deleted successfully!");
    } else {
        view->showError("Employee not found!");
    }
    
    view->waitForEnter();
}

void EmployeeController::saveToFile(const string& filename) {
    if (employees.empty()) {
        view->showError("No data to save!");
        view->waitForEnter();
        return;
    }
    
    ofstream file(filename);
    if (!file.is_open()) {
        view->showError("Could not open file for writing!");
        return;
    }
    
    for (const auto& emp : employees) {
        file << emp.toString() << endl;
    }
    
    file.close();
    view->showMessage("Data saved successfully to " + filename);
    view->waitForEnter();
}

void EmployeeController::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        view->showError("Could not open file for reading!");
        view->waitForEnter();
        return;
    }
    
    employees.clear();
    string line;
    
    while (getline(file, line)) {
        if (!line.empty()) {
            Employee emp = Employee::fromString(line);
            employees.push_back(emp);
        }
    }
    
    file.close();
    view->showMessage("Data loaded successfully from " + filename + 
                     " (" + to_string(employees.size()) + " records)");
    view->waitForEnter();
}

void EmployeeController::run() {
    int choice;
    const string dataFile = "employees.txt";
    
    do {
        view->clearScreen();
        view->showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                view->clearScreen();
                addEmployee();
                break;
            case 2:
                view->clearScreen();
                viewAllEmployees();
                break;
            case 3:
                view->clearScreen();
                searchEmployee();
                break;
            case 4:
                view->clearScreen();
                updateEmployee();
                break;
            case 5:
                view->clearScreen();
                deleteEmployee();
                break;
            case 6:
                view->clearScreen();
                saveToFile(dataFile);
                break;
            case 7:
                view->clearScreen();
                loadFromFile(dataFile);
                break;
            case 8:
                view->showMessage("Thank you for using Employee Management System!");
                break;
            default:
                view->showError("Invalid choice! Please try again.");
                view->waitForEnter();
        }
        
    } while (choice != 8);
}