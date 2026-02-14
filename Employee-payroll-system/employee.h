#include <string>

struct emp {
    int emp_id;
    std::string emp_name;
    std::string emp_desg;
    float emp_salary;
};

class Employee {
    emp *A;
    int n;

    void inorder(int);
    int height(int);
    void copyTree(emp *, int);
    void salaryRange(int, float, float);
    void countDesg(int, std::string, int &);
    void maxMinSalary(int, float &, float &);

public:
    Employee(int);
    void newEmployee(int, std::string, std::string, float);
    bool Search(int, int);
    void Display();
    void Remove(int);
    void Update(int, std::string, float);
    void HighestLowest();
    void CountByDesignation(std::string);
    void DisplaySalaryRange(float, float);
    Employee Copy();
    int Height();
    void SaveToFile(std::ofstream &, int);
};

