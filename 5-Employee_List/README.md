The task is to implement a set of functions to handle linked lists. An office is implemented as a structure with two linked lists. The first linked list stores the employees, the second list represents the cars. Each employee is represented by name and a link to his/her assigned car. A car is represented by its model name. Given that structures, the functions are used to initialize a new office, add a new employee, add a new car, copy the office, and dispose the office.

TEMPLOYEE
    is a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure represents one employee. The employees are organized in a single linked list. The structure has the following fields:

        -m_Next - a link to the next employee in the list. The last employee in the list must set m_Next to the NULL value.
        -m_Car - is a link to the assigned car. The link is either NULL (meaning the employee does not have any car assigned), or it references some element in the car linked list.
        -m_Name - an ASCIIZ (zero terminated) employee name.

TCAR
    is a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure represents one car. The car are organized in a single linked list. The structure has the following fields:

        -m_Next - a link to the next car in the list. The last car in the list must set m_Next to the NULL value.
        -m_Model - an ASCIIZ (zero terminated) car model name.

TOFFICE
    is a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure represents one office, the structure contains two fields:

        -m_Emp - a pointer to the first employee in the linked list of employees,
        -m_Car - a pointer to the first car in the linked list of cars.

initOffice ()
    the function creates a new office. The structure is to be dynamically allocated and a pointer to that structure is to be returned. Both lists in the newly created office must be initialized as empty.
    
addEmployee ( office, name )
    the function creates a new employee and places the new employee at the first position of the employee list. The parameters are name - name of the new employee and office - the office to place the employee to. The function is responsible for the allocation of the employee structure, moreover it must initialize the fields. The newly listed employee does not have any car assigned, i.e. m_Car must be set to NULL.
    
addCar ( office, model )
    the function creates a new car and places the new car at the first position of the car list. The parameters are model - the model name of the car and office - the office to place the car to. The function is responsible for the allocation of the car structure, moreover it must initialize the fields.
    
freeOffice ( office )
    the function frees all resources allocated by the given office (i.e. both employee and car linked lists plus the structure that represents the office),
    
cloneOffice ( office )
    the function creates an independent copy of the given office. The newly created office must preserve the employees, the cars, the order of employees, the order of the cars, and the assigned cars. Caution: the newly created list must be independent, thus the links to the cars must be updated to refer to the corresponding elements in the newly created office. Return value is a pointer that points to the newly allocated (and filled) office structure. 
