#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

using namespace std;

// Structure to hold employee data
struct Employee {
    int id; // Unique employee ID
    string firstName;
    string lastName;
    int age;
    string gender; // e.g., "M", "F", "Other"
    string date;   // Date of joining/birth (stored as string for simplicity)
};

// Global vector to store all employees and the next available ID
extern vector<Employee> employees;
extern int nextEmployeeId;

#endif
