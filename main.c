#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <pthread.h>
#include <time.h>
#include "main.h"

#define DEFAULT_PAUSE 1
#define ATTEND_PAUSE 1
#define MILLISECOND 1000

//Para as variáveis inteiras utilizadas como booleanas, consideremos 1 para TRUE e 0 para FALSE

int main() {
    int selectedOption = 0;
    int availableChairNumber = 0;
    int finishedThread = 0;

    customerStructure *customers = NULL;

    pthread_t threadOne;

    presentation();
    initializeSessionLog();
    setMaxChairNumber(&availableChairNumber); //O usuário definirá quantos slots de espera estarão disponíveis

    pthread_create(&threadOne, NULL, processCustomer, (void*) &customers);
    pthread_join(threadOne, (void*)&finishedThread);

    while(selectedOption != 3){
        selectedOption = navigationMenu(customers);

        system("cls");

        if(finishedThread == 0){
            finishedThread = 999999999;
            pthread_kill(threadOne, 1);
            pthread_create(&threadOne, NULL, processCustomer, (void*) &customers);
            pthread_join(threadOne, (void*)&finishedThread);
        }else if(finishedThread != 999999999){
            finishedThread = 999999999;
            pthread_kill(threadOne, 1);
            pthread_create(&threadOne, NULL, processCustomer, (void*) &customers);
            pthread_join(threadOne, (void*)&finishedThread);
            writeInLogFile("ERRO AO EXECUTAR THREAD PROCESSO REINICIADO", 0);
        }

        switch (selectedOption){
            case 1:
                includeCustomer(&customers, createCustomer(&customers),availableChairNumber);
                break;
            case 2:
                operationResume(customers);
                break;
            case 3:
                system("cls");
                printf("A execuca do sistema esta sendo finalizada");
                Sleep(DEFAULT_PAUSE * MILLISECOND);
                break;
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

customerStructure* createCustomer(customerStructure **customers){
    customerStructure *newCustomer;

    newCustomer = (customerStructure*) malloc(sizeof(customerStructure));

    newCustomer->customerNumber =  countTotalCustomers(customers) + 1;
    newCustomer->alreadyAttended = 0;
    newCustomer->isAttend = 0;
    newCustomer->isWaiting = 1;
    newCustomer->next = NULL;

    return newCustomer;
}

int emptyCustomerList(customerStructure **customers){
    if((*customers) == NULL){
        return 1;
    }else{
        return 0;
    }
}

void includeCustomer(customerStructure **customers, customerStructure *newCustomer, int availableChairs){

    customerStructure *auxCustomer = (*customers);

    if(countWaitingCustomers(&auxCustomer) >= availableChairs){
        writeInLogFile("NAO POSSUIA SLOTS DE ESPERA DISPONIVEIS, O MESMO SE RETIROU SEM SER PROCESSADO", newCustomer->customerNumber);
        return;
    }else{
        if(emptyCustomerList(&auxCustomer) == 1){
            *customers = newCustomer;
        }else{
            if(auxCustomer->next == NULL){
                auxCustomer->next = newCustomer;
                (*customers) = auxCustomer;
            }else{
                while(auxCustomer->next != NULL){
                    auxCustomer = auxCustomer->next;
                }

                auxCustomer->next = newCustomer;

            }
        }
    }
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

int countWaitingCustomers(customerStructure **customers) {
    customerStructure *auxCustomers;
    int waitingCustomers = 0;

    if(customers == NULL){
        auxCustomers = NULL;
    }else{
        auxCustomers = (*customers);
    }

    if(emptyCustomerList(&auxCustomers) == 1){
        return waitingCustomers;
    }else{
        while(auxCustomers != NULL){
            if(auxCustomers->isWaiting == 1){
                waitingCustomers++;
            }

            auxCustomers = auxCustomers->next;
        }
    }

    return waitingCustomers;
}

int countAttendCustomers(customerStructure **customers){
    customerStructure *auxCustomers;
    int attendCustomers = 0;

    if(customers == NULL){
        auxCustomers = NULL;
    }else{
        auxCustomers = (*customers);
    }

    if(emptyCustomerList(&auxCustomers) == 1){
        return attendCustomers;
    }else{
        while(auxCustomers != NULL){
            if(auxCustomers->isAttend == 1){
                attendCustomers++;
            }

            auxCustomers = auxCustomers->next;
        }
    }

    return attendCustomers;
}

int countAlreadyAttendCustomers(customerStructure **customers){
    customerStructure *auxCustomers;
    int alreadyAttendCustomers = 0;

    if(customers == NULL){
        auxCustomers = NULL;
    }else{
        auxCustomers = (*customers);
    }

    if(emptyCustomerList(&auxCustomers) == 1){
        return alreadyAttendCustomers;
    }else{
        while(auxCustomers != NULL){
            if(auxCustomers->alreadyAttended == 1){
                alreadyAttendCustomers++;
            }

            auxCustomers = auxCustomers->next;
        }
    }

    return alreadyAttendCustomers;
}

int countTotalCustomers(customerStructure **customers){
    customerStructure *auxCustomers;
    int totalCustomers = 0;

    if(customers == NULL){
        auxCustomers = NULL;
    }else{
        auxCustomers = (*customers);
    }


    if(emptyCustomerList(&auxCustomers) == 1){
        return totalCustomers;
    }else{
        while(auxCustomers != NULL){
            totalCustomers++;
            auxCustomers = auxCustomers->next;
        }
    }

    return totalCustomers;
}

int navigationMenu(customerStructure *customers){
    int selectedOption = 0;

    printf("-------------------------------------- Menu de Navegacao -----------------------------------\n\n");
    printf((countAttendCustomers(&customers) > 0 ? "----------------------------- Existem processos em execucao -----------------------------" : "----------------------------- Nao existem processos em execucao -----------------------------"));
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

    archiveReference = fopen("c:\\log\\sleepy_barber.log", "a");

    if(archiveReference == NULL){
        printf("\n\nErro ao realizar abertura do arquivo para escrita.");
        return;
    }

    strcat(message, __DATE__);
    strcat(message, " ");
    strcat(message, "Cliente de Numero: ");
    strcat(message, customer);
    strcat(message, " ");
    strcat(message, operation);
    strcat(message, "\n");

    fprintf(archiveReference, "%s", message);

    fclose(archiveReference);
}

void initializeSessionLog(){
    FILE *archiveReference;

    archiveReference = fopen("C:\\log\\sleepy_barber.log", "a");

    fprintf(archiveReference, "%s","\n\n########################################################## Log de Nova Execução ##########################################################\n\n");

    fclose(archiveReference);
}

void *processCustomer(void *args){
    customerStructure **customers = (customerStructure**) args;

    customerStructure *auxCustomer = (*customers);

    if(countWaitingCustomers(&auxCustomer) == 0 && countAttendCustomers(&auxCustomer) == 0){
        writeInLogFile("BARBEIRO OSCIOSO - DORMINDO", 0);
        auxCustomer = (*customers);
    }else{
        while(countWaitingCustomers(&auxCustomer) > 0){
            if(auxCustomer->alreadyAttended != 1) {
                if (auxCustomer->isAttend != 1) {
                    auxCustomer->isAttend = 1;
                    auxCustomer->isWaiting = 0;
                    writeInLogFile("EM ATENDIMENTO", auxCustomer->customerNumber);
                    Sleep(ATTEND_PAUSE * MILLISECOND);
                    auxCustomer->isAttend = 0;
                    auxCustomer->alreadyAttended = 1;
                    writeInLogFile("CONCLUIDO", auxCustomer->customerNumber);
                }
            }

            auxCustomer = auxCustomer->next;

            if (auxCustomer == NULL) {
                auxCustomer = (*customers);
            }
        }
    }


}

void operationResume(customerStructure *customers){
    system("cls");
    printf("\n\n------------------------- Resumo da operação -------------------------\n\n");
    printf("Processos aguardando: %d\n", countWaitingCustomers(&customers));
    printf("\nProcessos em atendimento: %d\n", countAttendCustomers(&customers));
    printf("\nProcessos finalizados: %d\n", countAlreadyAttendCustomers(&customers));
    Sleep(DEFAULT_PAUSE * MILLISECOND);
    system("cls");
}


