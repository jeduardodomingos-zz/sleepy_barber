#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <pthread.h>

#define DEFAULT_PAUSE 1
#define MILLISECOND 1000

//Para as variáveis inteiras utilizadas como booleanas, consideremos 1 para TRUE e 0 para FALSE

struct chair {
    int chairNumber;
    int isBusy;
};

struct barber {
    int barberNumber;
    int isBusy;
};

struct customer {
    int customerNumber;
    int isWaiting;
    int isAttend;
    int alreadyAttended
};


typedef struct chair chairStructure;
typedef struct barber barberStructure;
typedef struct customer customerStructure;


void presentation();
int getMaxChairNumber();
int getProcessNumberToEntry();
int getProcessNumberToEntry();
int countWaitingCustomers(customerStructure *customers);
int countAttendCustomers(customerStructure *customers);
int countAlreadyAttendCustomers(customerStructure *customers);
int countTotalCustomers(customerStructure *customers);

int main() {
    chairStructure *availableChairs = NULL;
    barberStructure *availableBarbers = NULL;
    customerStructure *customers = NULL;

    pthread_t threadOne;
    pthread_t threadTwo;

    presentation();

    availableChairs = (chairStructure *) malloc(sizeof(chairStructure) * getMaxChairNumber()); //O usuário definirá quantos slots de espera estarão disponíveis
    availableBarbers = (barberStructure *) malloc(sizeof(barberStructure) * 2); //haverão duas threads disponíveis (Simulando os Barbeiros)


    free(availableChairs);
    free(availableBarbers);
    free(customers);

    return 0;
}

void includeCustomer(customerStructure **customers){
    customerStructure newCustomer;

    newCustomer.customerNumber = countTotalCustomers(*customers);
    newCustomer.alreadyAttended = 0;
    newCustomer.isAttend = 0;
    newCustomer.isWaiting = 0;

    if((*customers) == NULL){
        *customers = malloc(sizeof(customerStructure));
    }else{
        *customers = realloc(customers, sizeof(*customers) + sizeof(customerStructure));
    }

    *customers[(sizeof(*customers) / sizeof(customerStructure)) - 1] = newCustomer;
}

void presentation() {
    system("cls");
    Sleep(DEFAULT_PAUSE * MILLISECOND);
    printf("----------------------- Seja bem vindo a simulacao de gerenciamento de processos ---------------------");
    printf("\n\n");
    printf("---------------------------- Simulacao do problema do barbeiro sonolento -----------------------------");
    printf("\n\n");
    Sleep(DEFAULT_PAUSE * MILLISECOND);
    system("cls");
}

int getMaxChairNumber() {
    int chairs = 0;

    printf("Qual sera o numero de cadeiras disponiveis ?\n");
    printf("R:");
    scanf("%d", &chairs);

    return chairs;
}

int getProcessNumberToEntry() {
    int processes = 0;

    system("cls");
    printf("Qual o numero de processos que deverao ser atendidos ?\n");
    printf("R: ");
    scanf("%d", &processes);

    return processes;
}

int countWaitingCustomers(customerStructure *customers) {
    int waitingCustomers = 0;

    for (int i = 0; i < (sizeof(customers) / sizeof(customerStructure)); i++) {
        if (customers[i].isWaiting) {
            waitingCustomers++;
        }
    }

    return waitingCustomers;
}

int countAttendCustomers(customerStructure *customers){
    int attendCustomers = 0;

    for (int i = 0; i < (sizeof(customers) / sizeof(customerStructure)); i++) {
        if (customers[i].isAttend) {
            attendCustomers++;
        }
    }

    return attendCustomers;
}

int countAlreadyAttendCustomers(customerStructure *customers){
    int alreadyAttendCustomers = 0;

    for (int i = 0; i < (sizeof(customers) / sizeof(customerStructure)); i++) {
        if (customers[i].alreadyAttended) {
            alreadyAttendCustomers++;
        }
    }

    return alreadyAttendCustomers;
}

int countTotalCustomers(customerStructure *customers){
    int totalCustomers = 0;

    for (int i = 0; i < (sizeof(customers) / sizeof(customerStructure)); i++) {
        totalCustomers++;
    }

    return totalCustomers;
}