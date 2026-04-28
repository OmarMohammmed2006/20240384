#include "Employee.h"
#include <sstream>

using namespace std;

Employee::Employee() : id(0), name(""), department(""), salary(0.0), position("") {}

Employee::Employee(int id, const string& name, const string& department,
                   double salary, const string& position)
    : id(id), name(name), department(department), salary(salary), position(position) {}

int Employee::getId() const { return id; }
string Employee::getName() const { return name; }
string Employee::getDepartment() const { return department; }
double Employee::getSalary() const { return salary; }
string Employee::getPosition() const { return position; }

void Employee::setId(int id) { this->id = id; }
void Employee::setName(const string& name) { this->name = name; }
void Employee::setDepartment(const string& department) { this->department = department; }
void Employee::setSalary(double salary) { this->salary = salary; }
void Employee::setPosition(const string& position) { this->position = position; }

void Employee::display() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Department: " << department << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: $" << salary << endl;
    cout << "------------------------" << endl;
}

string Employee::toString() const {
    stringstream ss;
    ss << id << "," << name << "," << department << "," << salary << "," << position;
    return ss.str();
}

Employee Employee::fromString(const string& data) {
    stringstream ss(data);
    string token;
    Employee emp;

    getline(ss, token, ',');
    emp.id = stoi(token);

    getline(ss, emp.name, ',');
    getline(ss, emp.department, ',');

    getline(ss, token, ',');
    emp.salary = stod(token);

    getline(ss, emp.position, ',');
    
    return emp;
}