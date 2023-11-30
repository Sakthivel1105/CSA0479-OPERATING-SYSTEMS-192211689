#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    int file_descriptor, n;
    Employee employee;
    off_t offset;

    // Create a random access file for employee details
    file_descriptor = open("employee_details.dat", O_CREAT | O_RDWR, 0666);
    if (file_descriptor == -1) {
        perror("Failed to create random access file");
        exit(1);
    }

    // Write employee details to the random access file
    for (n = 0; n < MAX_EMPLOYEES; n++) {
        employee.id = n + 1;
        sprintf(employee.name, "Employee %d", employee.id);
        employee.salary = 50000.00 + n * 1000.00;

        offset = (off_t)n * sizeof(employee);
        lseek(file_descriptor, offset, SEEK_SET);
        write(file_descriptor, &employee, sizeof(employee));
    }

    // Read employee details from the random access file
    offset = (off_t)(MAX_EMPLOYEES / 2) * sizeof(employee);
    lseek(file_descriptor, offset, SEEK_SET);
    read(file_descriptor, &employee, sizeof(employee));

    printf("Employee details: ID = %d, Name = %s, Salary = %.2f\n", employee.id, employee.name, employee.salary);

    // Close the random access file
    close(file_descriptor);

    return 0;
}