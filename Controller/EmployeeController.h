#ifndef EMPLOYEECONTROLLER_H
#define EMPLOYEECONTROLLER_H

#include "../model/Employee.h"
#include "../View/EmployeeView.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class EmployeeController {
private:
    vector<Employee> employees;
    unique_ptr<EmployeeView> view;
    
    bool isValidId(int id) const;
    int findEmployeeIndex(int id) const;
    
public:
    EmployeeController();
    
    void addEmployee();
    void viewAllEmployees();
    void searchEmployee();
    void updateEmployee();
    void deleteEmployee();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    
    void run();
};

#endif