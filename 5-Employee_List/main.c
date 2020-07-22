#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TCar
{
    struct TCar *m_Next;
    char *m_Model;
} TCAR;

typedef struct TEmployee
{
    struct TEmployee *m_Next;
    struct TCar *m_Car;
    char *m_Name;
} TEMPLOYEE;

typedef struct TOffice
{
    TEMPLOYEE *m_Emp;
    TCAR *m_Car;
} TOFFICE;

typedef struct
{
    TCAR car;
    int index;
} INDEXED_CAR;

typedef struct
{
    TCAR *new_car;
} CARS;

TEMPLOYEE *makeEmployee(const char *name)
{
    TEMPLOYEE *employee = (TEMPLOYEE *)calloc(1, sizeof(TEMPLOYEE));
    employee->m_Name = strdup(name);
    return employee;
}

void addEmployee2Office(TOFFICE *office, TEMPLOYEE *employee)
{
    employee->m_Next = office->m_Emp;
    office->m_Emp = employee;
}

TCAR *makeCar(const char *model)
{
    INDEXED_CAR *car = (INDEXED_CAR *)calloc(1, sizeof(INDEXED_CAR));
    car->car.m_Model = strdup(model);
    return (TCAR *)car;
}

void addCar2Office(TOFFICE *office, TCAR *car)
{
    car->m_Next = office->m_Car;
    office->m_Car = car;
}

void freeEmployee(TEMPLOYEE *employee)
{
    if (employee != NULL)
    {
        free(employee->m_Name);
        free(employee);
    }
}

void freeEmployees(TEMPLOYEE *employees)
{
    while (employees != NULL)
    {
        TEMPLOYEE *object = employees;
        employees = employees->m_Next;

        freeEmployee(object);
    }
}

void freeCar(TCAR *car)
{
    if (car != NULL)
    {
        free(car->m_Model);
        free(car);
    }
}

void freeCars(TCAR *cars)
{
    while (cars != NULL)
    {
        TCAR *object = cars;
        cars = cars->m_Next;

        freeCar(object);
    }
}

size_t countCars(TCAR *cars)
{
    size_t amount = 0;
    while (cars != NULL)
    {
        ++amount;
        cars = cars->m_Next;
    }

    return amount;
}

TCAR *cloneCars(TCAR *cars, CARS *carsMap)
{
    TCAR *newCars = NULL;
    TCAR *car = NULL;
    for (int i = 0; cars != NULL; cars = cars->m_Next, ++i)
    {
        carsMap[i].new_car = makeCar(cars->m_Model);

        if (car == NULL)
        {
            car = carsMap[i].new_car;
            newCars = car;
        }
        else
        {
            car->m_Next = carsMap[i].new_car;
            car = carsMap[i].new_car;
        }

        INDEXED_CAR *tmpCar = (INDEXED_CAR *)cars;
        tmpCar->index = i;
    }

    return newCars;
}

TCAR *getCar(TCAR *car, CARS *carsMap, int position)
{
    return carsMap[position].new_car;
}

TEMPLOYEE *cloneEmployees(TEMPLOYEE *employees, CARS *cars)
{
    TEMPLOYEE *newEmployees = NULL;
    TEMPLOYEE *employee = NULL;
    for (; employees != NULL; employees = employees->m_Next)
    {
        TEMPLOYEE *newEmployee = makeEmployee(employees->m_Name);
        if (employee == NULL)
        {
            employee = newEmployee;
            newEmployees = newEmployee;
        }
        else
        {
            employee->m_Next = newEmployee;
            employee = newEmployee;
        }

        INDEXED_CAR *tmpCar = (INDEXED_CAR *)employees->m_Car;
        if (tmpCar != NULL)
        {
            newEmployee->m_Car = getCar(employees->m_Car, cars, tmpCar->index);
        }
    }

    return newEmployees;
}

TOFFICE *initOffice()
{
    return (TOFFICE *)calloc(1, sizeof(TOFFICE));
}

void addEmployee(TOFFICE *office,
                 const char *name)
{
    TEMPLOYEE *employee = makeEmployee(name);
    addEmployee2Office(office, employee);
}

void addCar(TOFFICE *office,
            const char *model)
{
    TCAR *car = makeCar(model);
    addCar2Office(office, car);
}

TOFFICE *cloneOffice(TOFFICE *office)
{
    size_t amount = countCars(office->m_Car);
    CARS *carsMap = (CARS *)calloc(amount, sizeof(CARS));

    TOFFICE *newOffice = initOffice();
    newOffice->m_Car = cloneCars(office->m_Car, carsMap);
    newOffice->m_Emp = cloneEmployees(office->m_Emp, carsMap);

    free(carsMap);
    return newOffice;
}

void freeOffice(TOFFICE *office)
{
    freeEmployees(office->m_Emp);
    freeCars(office->m_Car);
    free(office);
}

int main(int argc, char *argv[])
{
    TOFFICE *a, *b;
    char tmp[100];

    assert(sizeof(TOFFICE) == 2 * sizeof(void *));
    assert(sizeof(TEMPLOYEE) == 3 * sizeof(void *));
    assert(sizeof(TCAR) == 2 * sizeof(void *));
    a = initOffice();
    addEmployee(a, "Peter");
    addEmployee(a, "John");
    addEmployee(a, "Joe");
    addEmployee(a, "Maria");
    addCar(a, "Skoda Octavia");
    addCar(a, "VW Golf");
    a->m_Emp->m_Car = a->m_Car;
    a->m_Emp->m_Next->m_Next->m_Car = a->m_Car->m_Next;
    a->m_Emp->m_Next->m_Next->m_Next->m_Car = a->m_Car;
    assert(a->m_Emp && !strcmp(a->m_Emp->m_Name, "Maria") && a->m_Emp->m_Car == a->m_Car);
    assert(a->m_Emp->m_Next && !strcmp(a->m_Emp->m_Next->m_Name, "Joe") && a->m_Emp->m_Next->m_Car == NULL);
    assert(a->m_Emp->m_Next->m_Next && !strcmp(a->m_Emp->m_Next->m_Next->m_Name, "John") && a->m_Emp->m_Next->m_Next->m_Car == a->m_Car->m_Next);
    assert(a->m_Emp->m_Next->m_Next->m_Next && !strcmp(a->m_Emp->m_Next->m_Next->m_Next->m_Name, "Peter") && a->m_Emp->m_Next->m_Next->m_Next->m_Car == a->m_Car);
    assert(a->m_Emp->m_Next->m_Next->m_Next->m_Next == NULL);
    assert(a->m_Car && !strcmp(a->m_Car->m_Model, "VW Golf"));
    assert(a->m_Car->m_Next && !strcmp(a->m_Car->m_Next->m_Model, "Skoda Octavia"));
    assert(a->m_Car->m_Next->m_Next == NULL);
    b = cloneOffice(a);
    strncpy(tmp, "Moe", sizeof(tmp));
    addEmployee(a, tmp);
    strncpy(tmp, "Victoria", sizeof(tmp));
    addEmployee(a, tmp);
    strncpy(tmp, "Peter", sizeof(tmp));
    addEmployee(a, tmp);
    strncpy(tmp, "Citroen C4", sizeof(tmp));
    addCar(a, tmp);
    b->m_Emp->m_Next->m_Next->m_Next->m_Car = b->m_Car->m_Next->m_Next;
    assert(a->m_Emp && !strcmp(a->m_Emp->m_Name, "Peter") && a->m_Emp->m_Car == NULL);
    assert(a->m_Emp->m_Next && !strcmp(a->m_Emp->m_Next->m_Name, "Victoria") && a->m_Emp->m_Next->m_Car == NULL);
    assert(a->m_Emp->m_Next->m_Next && !strcmp(a->m_Emp->m_Next->m_Next->m_Name, "Moe") && a->m_Emp->m_Next->m_Next->m_Car == NULL);
    assert(a->m_Emp->m_Next->m_Next->m_Next && !strcmp(a->m_Emp->m_Next->m_Next->m_Next->m_Name, "Maria") && a->m_Emp->m_Next->m_Next->m_Next->m_Car == a->m_Car->m_Next);
    assert(a->m_Emp->m_Next->m_Next->m_Next->m_Next && !strcmp(a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Name, "Joe") && a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Car == NULL);
    assert(a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "John") && a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Next->m_Car == a->m_Car->m_Next->m_Next);
    assert(a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "Peter") && a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Car == a->m_Car->m_Next);
    assert(a->m_Emp->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
    assert(a->m_Car && !strcmp(a->m_Car->m_Model, "Citroen C4"));
    assert(a->m_Car->m_Next && !strcmp(a->m_Car->m_Next->m_Model, "VW Golf"));
    assert(a->m_Car->m_Next->m_Next && !strcmp(a->m_Car->m_Next->m_Next->m_Model, "Skoda Octavia"));
    assert(a->m_Car->m_Next->m_Next->m_Next == NULL);
    assert(b->m_Emp && !strcmp(b->m_Emp->m_Name, "Maria") && b->m_Emp->m_Car == b->m_Car);
    assert(b->m_Emp->m_Next && !strcmp(b->m_Emp->m_Next->m_Name, "Joe") && b->m_Emp->m_Next->m_Car == NULL);
    assert(b->m_Emp->m_Next->m_Next && !strcmp(b->m_Emp->m_Next->m_Next->m_Name, "John") && b->m_Emp->m_Next->m_Next->m_Car == b->m_Car->m_Next);
    assert(b->m_Emp->m_Next->m_Next->m_Next && !strcmp(b->m_Emp->m_Next->m_Next->m_Next->m_Name, "Peter") && b->m_Emp->m_Next->m_Next->m_Next->m_Car == NULL);
    assert(b->m_Emp->m_Next->m_Next->m_Next->m_Next == NULL);
    assert(b->m_Car && !strcmp(b->m_Car->m_Model, "VW Golf"));
    assert(b->m_Car->m_Next && !strcmp(b->m_Car->m_Next->m_Model, "Skoda Octavia"));
    assert(b->m_Car->m_Next->m_Next == NULL);
    freeOffice(a);
    freeOffice(b);
    return 0;
}