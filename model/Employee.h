#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    double salary;
    string position;

public:
    // Constructors
    Employee();
    Employee(int id, const string& name, const string& department,
             double salary, const string& position);

    // Getters
    int getId() const;
    string getName() const;
    string getDepartment() const;
    double getSalary() const;
    string getPosition() const;

    // Setters
    void setId(int id);
    void setName(const string& name);
    void setDepartment(const string& department);
    void setSalary(double salary);
    void setPosition(const string& position);

    // Display employee info
    void display() const;

    // Convert to string for file storage
    string toString() const;

    // Create from string (for file loading)
    static Employee fromString(const string& data);
};

#endif