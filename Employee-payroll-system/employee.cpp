#include <iostream>
#include <climits>
#include <fstream>
#include "employee.h"

using namespace std;

Employee::Employee(int s) {
    n = s;
    A = new emp[n];
    for (int i = 0; i < n; i++)
        A[i].emp_id = INT_MIN;
}

// Insert
void Employee::newEmployee(int id, string name, string desg, float salary) {
    int i = 0;
    while (i < n) {
        if (A[i].emp_id == INT_MIN) {
            A[i] = {id, name, desg, salary};
            return;
        }
        if (id < A[i].emp_id)
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
}

// Inorder traversal
void Employee::inorder(int i) {
    if (i >= n || A[i].emp_id == INT_MIN) return;
    inorder(2 * i + 1);
    cout << A[i].emp_id << "\t" << A[i].emp_name << "\t"
         << A[i].emp_desg << "\t" << A[i].emp_salary << endl;
    inorder(2 * i + 2);
}

void Employee::Display() {
    inorder(0);
}

// Search
bool Employee::Search(int i, int id) {
    if (i >= n || A[i].emp_id == INT_MIN) return false;
    if (A[i].emp_id == id) return true;
    if (id < A[i].emp_id)
        return Search(2 * i + 1, id);
    return Search(2 * i + 2, id);
}

// Remove (delete)
void Employee::Remove(int id) {
    for (int i = 0; i < n; i++) {
        if (A[i].emp_id == id) {
            A[i].emp_id = INT_MIN;
            return;
        }
    }
}

// Update
void Employee::Update(int id, string desg, float salary) {
    for (int i = 0; i < n; i++) {
        if (A[i].emp_id == id) {
            A[i].emp_desg = desg;
            A[i].emp_salary = salary;
            return;
        }
    }
}

// Highest & Lowest salary
void Employee::maxMinSalary(int i, float &mx, float &mn) {
    if (i >= n || A[i].emp_id == INT_MIN) return;
    mx = max(mx, A[i].emp_salary);
    mn = min(mn, A[i].emp_salary);
    maxMinSalary(2 * i + 1, mx, mn);
    maxMinSalary(2 * i + 2, mx, mn);
}

void Employee::HighestLowest() {
    float mx = -1e9, mn = 1e9;
    maxMinSalary(0, mx, mn);
    cout << "Highest Salary: " << mx << endl;
    cout << "Lowest Salary: " << mn << endl;
}

// Count designation
void Employee::countDesg(int i, string d, int &c) {
    if (i >= n || A[i].emp_id == INT_MIN) return;
    if (A[i].emp_desg == d) c++;
    countDesg(2 * i + 1, d, c);
    countDesg(2 * i + 2, d, c);
}

void Employee::CountByDesignation(string d) {
    int c = 0;
    countDesg(0, d, c);
    cout << "Count of " << d << " = " << c << endl;
}

// Salary range
void Employee::salaryRange(int i, float l, float h) {
    if (i >= n || A[i].emp_id == INT_MIN) return;
    if (A[i].emp_salary >= l && A[i].emp_salary <= h)
        cout << A[i].emp_id << "\t" << A[i].emp_name << endl;
    salaryRange(2 * i + 1, l, h);
    salaryRange(2 * i + 2, l, h);
}

void Employee::DisplaySalaryRange(float l, float h) {
    salaryRange(0, l, h);
}

// Copy tree
void Employee::copyTree(emp *B, int i) {
    if (i >= n) return;
    B[i] = A[i];
    copyTree(B, 2 * i + 1);
    copyTree(B, 2 * i + 2);
}

Employee Employee::Copy() {
    Employee e(n);
    copyTree(e.A, 0);
    return e;
}

// Height
int Employee::height(int i) {
    if (i >= n || A[i].emp_id == INT_MIN) return 0;
    return 1 + max(height(2 * i + 1), height(2 * i + 2));
}

int Employee::Height() {
    return height(0);
}

// inorder save
void Employee::SaveToFile(std::ofstream &fout, int i) {
    if (i >= n || A[i].emp_id == INT_MIN) return;

    SaveToFile(fout, 2 * i + 1);

    fout << A[i].emp_id << " "
         << A[i].emp_name << " "
         << A[i].emp_desg << " "
         << A[i].emp_salary << endl;

    SaveToFile(fout, 2 * i + 2);
}


