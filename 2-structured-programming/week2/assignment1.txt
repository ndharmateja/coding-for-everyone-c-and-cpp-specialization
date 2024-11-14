#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Department
{
    HR,
    Sales,
    Research,
    Software,
    Executive
};
typedef enum Department Department;

typedef struct
{
    Department department;
    int annual_salary;
    unsigned long ssn;
} Employee;

// Function that generates salary based on department
int generate_annual_salary(Department department)
{
    int base_salary, max_offset = 50000;

    switch (department)
    {
    case HR:
        base_salary = 100000;
        break;
    case Sales:
        base_salary = 200000;
        break;
    case Research:
        base_salary = 150000;
        break;
    case Software:
        base_salary = 250000;
        break;
    case Executive:
        base_salary = 350000;
        break;
    default:
        break;
    }

    return base_salary + (rand() % max_offset);
}

// Function to print an employee
void print_employee(Employee *employee)
{
    char *department;
    switch (employee->department)
    {
    case HR:
        department = "HR";
        break;
    case Sales:
        department = "Sales";
        break;
    case Research:
        department = "Research";
        break;
    case Software:
        department = "Software";
        break;
    case Executive:
        department = "Executive";
        break;
    default:
        break;
    }

    printf("Employee Details: ");
    printf("{Department: %s, ", department);
    printf("Annual Salary: $%d, ", employee->annual_salary);
    printf("Social Security Number: %lu}\n", employee->ssn);
}

int main(void)
{
    // Reset random seed
    srand(time(0));

    // Define and print employees
    Employee e1 = {HR, generate_annual_salary(HR), 5551112233};
    print_employee(&e1);

    Employee e2 = {Sales, generate_annual_salary(Sales), 6978639511};
    print_employee(&e2);

    Employee e3 = {Research, generate_annual_salary(Research), 3121366827};
    print_employee(&e3);

    Employee e4 = {Software, generate_annual_salary(Software), 4693251905};
    print_employee(&e4);

    Employee e5 = {Software, generate_annual_salary(Software), 3307588554};
    print_employee(&e1);

    Employee e6 = {Executive, generate_annual_salary(Executive), 9863063104};
    print_employee(&e6);

    Employee e7 = {HR, generate_annual_salary(HR), 9863063104};
    print_employee(&e7);

    Employee e8 = {Research, generate_annual_salary(Research), 9863063104};
    print_employee(&e8);

    Employee e9 = {Executive, generate_annual_salary(Executive), 9863063104};
    print_employee(&e9);

    Employee e10 = {Software, generate_annual_salary(Software), 3194533004};
    print_employee(&e10);

    return 0;
}
