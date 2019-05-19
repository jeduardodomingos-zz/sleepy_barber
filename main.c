#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <pthread.h>

#define DEFAULT_PAUSE 1
#define MILLISECOND 1000

struct chair {
    int chairNumber;
    int isBusy;
};

struct barber {
    int barberNumber;
    int isBusy;
};

typedef struct chair chairStructure;
typedef struct barber barberStructure;

void presentation();
int getMaxChairNumber();
int getProcessNumberToEntry();

int main() {
    chairStructure *avaliableChairs;
    barberStructure*avaliableBarbers;

    pthread_t threadOne;
    pthread_t threadTwo;

    presentation();

    avaliableChairs = (chairStructure*) malloc(sizeof(chairStructure) * getMaxChairNumber()); //O usuário definirá quantas cadeiras de espera estarão disponíveis
    avaliableBarbers = (barberStructure*) malloc(sizeof(barberStructure) * 2); //haverão dois Barbeiros (Thread Disponíveis);

    
    return 0;
}

void presentation(){
    system("cls");
    Sleep(DEFAULT_PAUSE * MILLISECOND);
    printf("----------------------- Seja bem vindo a simulacao de gerenciamento de processos ---------------------");
    printf("\n\n");
    printf("---------------------------- Simulacao do problema do barbeiro sonolento -----------------------------");
    printf("\n\n");
    Sleep(DEFAULT_PAUSE * MILLISECOND);
    system("cls");
}

int getMaxChairNumber(){
    int chairs = 0;

    printf("Qual sera o numero de cadeiras disponiveis ?\n");
    printf("R:");
    scanf("%d", &chairs);

    return chairs;
};

int getProcessNumberToEntry(){
    int processes = 0;

    system("cls");
    printf("Qual o numero de processos que deverao ser atendidos ?\n");
    printf("R: ");
    scanf("%d", &processes);

    return processes;
}