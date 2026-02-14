#include <iostream>
#include <fstream>
#include "employee.h"

using namespace std;

int main() {
    Employee e(100);

    ifstream fin("employee.txt");
    int id;
    string name, desg;
    float salary;

    if (fin.is_open()) {
        while (fin >> id >> name >> desg >> salary) {
            e.newEmployee(id, name, desg, salary);
        }
        fin.close();
    }

    int choice;

    while (true) {
        cout << "\n====== Employee Payroll System ======\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Salary / Designation\n";
        cout << "5. Display Employees (Ascending ID)\n";
        cout << "6. Highest & Lowest Paid Employee\n";
        cout << "7. Count Employees by Designation\n";
        cout << "8. Display Employees within Salary Range\n";
        cout << "9. Copy Payroll Tree\n";
        cout << "10. Height of Employee Tree\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        float low, high;

        switch (choice) {

        case 1:
            cout << "Enter ID Name Designation Salary: ";
            cin >> id >> name >> desg >> salary;
            e.newEmployee(id, name, desg, salary);
            break;

        case 2:
            cout << "Enter Employee ID to remove: ";
            cin >> id;
            e.Remove(id);
            break;

        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            if (e.Search(0, id))
                cout << "Employee Found\n";
            else
                cout << "Employee Not Found\n";
            break;

        case 4:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter New Designation and Salary: ";
            cin >> desg >> salary;
            e.Update(id, desg, salary);
            break;

        case 5:
            cout << "\nID\tName\tDesignation\tSalary\n";
            e.Display();
            break;

        case 6:
            e.HighestLowest();
            break;

        case 7:
            cout << "Enter Designation: ";
            cin >> desg;
            e.CountByDesignation(desg);
            break;

        case 8:
            cout << "Enter Salary Range (low high): ";
            cin >> low >> high;
            e.DisplaySalaryRange(low, high);
            break;

        case 9: {
            Employee copy = e.Copy();
            cout << "\nCopied Payroll Tree:\n";
            copy.Display();
            break;
        }

        case 10:
            cout << "Tree Height: " << e.Height() << endl;
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

   ofstream fout("employee_updated.txt");   
   if (fout.is_open()) {
       e.SaveToFile(fout, 0);
       fout.close();
   }


    cout << "\nData saved to employee_updated.txt\n";
    cout << "Program exited successfully.\n";

    return 0;
}

