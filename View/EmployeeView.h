#ifndef EMPLOYEEVIEW_H
#define EMPLOYEEVIEW_H

#include "../model/Employee.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

class EmployeeView {
public:
    void showMenu();
    void showAllEmployees(const vector<Employee>& employees);
    void showEmployee(const Employee& employee);
    void showMessage(const string& message);
    void showError(const string& error);
    
    Employee getEmployeeInput();
    int getEmployeeIdInput();
    Employee getUpdatedEmployeeInput(const Employee& oldEmployee);
    
    void clearScreen();
    void waitForEnter();
};

#endif