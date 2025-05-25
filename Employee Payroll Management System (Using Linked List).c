/*You are developing an Employee Payroll Management System using a singly linked list to store
and manage employee salary details. The system should allow the following operations:
1. Add a new employee's salary details (insert at the end).
2. Remove an employee by their Employee ID (deletion).
3. Search for an employee by their Employee ID (traversing and comparing).
4. Display all employees sorted by Employee ID.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int emp_id;
    char name[100];
    int salary;
    struct employee* next;
};

struct employee* head = NULL;


int id_exists(int id) {
    struct employee* temp = head;
    while (temp != NULL) {
        if (temp->emp_id == id) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void add_new_employee() {
    struct employee* newEmp = (struct employee*)malloc(sizeof(struct employee));

    int id;
    while (1) {
        printf("Enter Employee ID: ");
        scanf("%d", &id);
        if (id_exists(id)) {
            printf("Error: Employee ID %d already exists. Please enter a unique ID.\n", id);
        } else {
            newEmp->emp_id = id;
            break;
        }
    }

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", newEmp->name);

    printf("Enter Salary: ");
    scanf("%d", &newEmp->salary);

    newEmp->next = NULL;

    if (head == NULL) {
        head = newEmp;
    } else {
        struct employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmp;
    }

    printf("Employee added.\n");
}

void remove_employee() {
    int id;
    printf("Enter the employee ID to remove: ");
    scanf("%d", &id);

    struct employee* temp = head;
    struct employee* prev = NULL;

    while (temp != NULL && temp->emp_id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee not found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Employee has been removed.\n");
}

void search_employee() {
    int id, found = 0;
    printf("Enter the employee ID to search: ");
    scanf("%d", &id);

    struct employee* temp = head;
    while (temp != NULL) {
        if (temp->emp_id == id) {
            printf("\nEmployee Found!\n");
            printf("ID: %d\nName: %s\nSalary: %d\n", temp->emp_id, temp->name, temp->salary);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

void display_all_employees() {
    if (head == NULL) {
        printf("No employee records available.\n");
        return;
    }


    struct employee* i;
    struct employee* j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->emp_id > j->emp_id) {
                int temp_id = i->emp_id;
                int temp_salary = i->salary;
                char temp_name[100];
                strcpy(temp_name, i->name);

                i->emp_id = j->emp_id;
                i->salary = j->salary;
                strcpy(i->name, j->name);

                j->emp_id = temp_id;
                j->salary = temp_salary;
                strcpy(j->name, temp_name);
            }
        }
    }

    printf("\nList of Employees (Sorted by ID):\n");
    struct employee* temp = head;
    while (temp != NULL) {
        printf("ID: %d || Name: %s || Salary: %d\n", temp->emp_id, temp->name, temp->salary);
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\nEmployee Payroll Management System\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_new_employee();
                break;
            case 2:
                remove_employee();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                display_all_employees();
                break;
            case 5:
                printf("\nExiting the system!\n");
                break;
            default:
                printf("\nERROR! Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}
