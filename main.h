//
// Created by Juan Eduardo Domingo on 21/05/2019.
//

#ifndef SLEEPY_BARBER_MAIN_H
#define SLEEPY_BARBER_MAIN_H

struct customer {
    int customerNumber;
    int isWaiting;
    int isAttend;
    int alreadyAttended;
    struct customer* next;
};

typedef struct customer customerStructure;
typedef struct customer* pCustomerStructure;

/*Especial return Types*/
customerStructure* createCustomer();

/*Int return Types*/
int emptyCustomerList(customerStructure **customers);
int setMaxChairNumber(int *chairs);
int countWaitingCustomers(customerStructure **customers);
int countAttendCustomers(customerStructure **customers);
int countAlreadyAttendCustomers(customerStructure **customers);
int countTotalCustomers(customerStructure **customers);
int navigationMenu(customerStructure *customers);

/*Without return types*/
void writeInLogFile(char operation[200], int customerNumber);
void *processCustomer(void *args);
void operationResume(customerStructure *customers);
void includeCustomer(customerStructure **customers, customerStructure *newCustomer, int availableChairs);
void presentation();

#endif //SLEEPY_BARBER_MAIN_H
