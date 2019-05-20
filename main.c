#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <pthread.h>
#include <time.h>

#define DEFAULT_PAUSE 1
#define ATTEND_PAUSE 2
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

void includeCustomer(customerStructure **customers);
void presentation();
int setMaxChairNumber(int *chairs);
int countWaitingCustomers(customerStructure *customers);
int countAttendCustomers(customerStructure *customers);
int countAlreadyAttendCustomers(customerStructure *customers);
int countTotalCustomers(customerStructure *customers);
int navigationMenu(customerStructure *customers);
void writeInLogFile(char operation[200], int customerNumber);
void * processCustomer(void *args);
void operationResume(customerStructure *customers);

int main() {
    int selectedOption = 0;
    int availableChairNumber = 0;

    customerStructure *customers = NULL;

    pthread_t threadOne;
    pthread_t threadTwo;

    presentation();
    setMaxChairNumber(&availableChairNumber); //O usuário definirá quantos slots de espera estarão disponíveis

    pthread_create(&threadOne, NULL, processCustomer, (void*) customers);
    pthread_create(&threadTwo, NULL, processCustomer, (void*) customers);

    pthread_join(threadOne, NULL);
    pthread_join(threadTwo, NULL);

    while(selectedOption != 3){
        selectedOption = navigationMenu(customers);

        switch (selectedOption){
            case 1:
                includeCustomer(&customers);
                break;
            case 2:
                operationResume(customers);
                break;
            case 3:
                system("cls");
                printf("A execução do sistema está sendo finalizada");
                Sleep(DEFAULT_PAUSE * MILLISECOND);
            default:
                system("cls");
                printf("Opcao invalida ...");
                Sleep(DEFAULT_PAUSE * MILLISECOND);
                break;
        }
    }

    free(customers);

    return 0;
}

void includeCustomer(customerStructure **customers, int availableChairs){
    customerStructure newCustomer;

    newCustomer.customerNumber = countTotalCustomers(*customers) + 1;
    newCustomer.alreadyAttended = 0;
    newCustomer.isAttend = 0;
    newCustomer.isWaiting = 0;

    if(countWaitingCustomers(*customers) >= availableChairs){
        
    }

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

int setMaxChairNumber(int *chairs) {
    printf("Qual sera o numero de cadeiras disponiveis ?\n");
    printf("R:");
    scanf("%d", chairs);
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

int navigationMenu(customerStructure *customers){
    int selectedOption = 0;

    printf("-------------------------------------- Menu de Navegacao -----------------------------------\n\n");
    printf((countAttendCustomers(customers) > 0 ? "----------------------------- Existem processos em execucao -----------------------------" : "----------------------------- Nao existem processos em execucao -----------------------------"));
    printf("\n\n1 - Adicionar um novo Cliente a fila");
    printf("\n2 - Exibir status das execucoes atuais");
    printf("\n3 - Sair");
    printf("\nR: ");

    scanf("%d", &selectedOption);

    return selectedOption;
}

void writeInLogFile(char operation[200], int customerNumber){
    char message[500];
    char customer[10];
    FILE *archiveReference;

    itoa(customerNumber, customer, sizeof(customer) * 2);

    archiveReference = fopen("c:/log/sleepy_barber.log", "w");

    if(archiveReference == NULL){
        printf("\n\nErro ao realizar abertura do arquivo para escrita.");
        return;
    }

    strcat(message, __DATE__);
    strcat(message, " ");
    strcat(message, "Cliente de Numero: ");
    strcat(message, customer);
    strcat(message, operation);
    strcat(message, "\n");

    fprintf(archiveReference, "%s", message);

    fclose(archiveReference);
}

void *processCustomer(void *args){
    customerStructure *customers = (customerStructure*) args;

    if(customers != NULL){
        if(countWaitingCustomers(customers) > 0){
            for(int i = 0; i < (sizeof(customers) / sizeof(customerStructure)); i++){
                if(customers[i].alreadyAttended != 1){
                    customers[i].isAttend = 1;
                    customers[i].isWaiting = 0;
                    writeInLogFile("EM ATENDIMENTO", customers[i].customerNumber);
                    Sleep(ATTEND_PAUSE * MILLISECOND);
                }else{
                    continue;
                }
            }
        }
    }
}

void operationResume(customerStructure *customers){
    system("cls");
    printf("\n\n------------------------- Resumo da operação -------------------------\n\n");
    printf("Processos aguardando: %d\n", countWaitingCustomers(customers));
    printf("\nProcessos em atendimento: %d\n", countAttendCustomers(customers));
    printf("\nProcessos finalizados: %d\n", countAlreadyAttendCustomers(customers));
    Sleep(DEFAULT_PAUSE * MILLISECOND);
    system("cls");
}


