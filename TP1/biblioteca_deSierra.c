#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_deSierra.h"


int menu(float opx, float opy, int f1, int f2){

    int opcion;

    system("cls");
    printf("----Menu de opciones----\n\n");
    if (f1 == 1){
        printf("1- Ingresar 1er operando (A = %.2f)\n", opx);
    }
    else {
        printf("1- Ingresar 1er operando (A = x)\n");
    }
    if (f1 == 1){
        printf("2- Ingresar 2do operando (B = %.2f)\n", opy);
    }
    else {
        printf("2- Ingresar 2do operando (B = y)\n");
    }
    printf("3- Calcular todas las operaciones\n");
    printf("4- Informar resultados\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;
}

float sumar( float x, float y)
{
    float resul;
    resul = (float) x + y;
    return resul;
}

float restar( float x, float y)
{
    float resul;
    resul = (float) x - y;
    return resul;
}

float dividir( float x, float y)
{
    float resul;

    resul = (float) x / y;

    return resul;
}

float multiplicar ( float x, float y)
{
    float resul;

    resul = (float) x * y;

    return resul;
}

int factorial (float num)
{
    double factNum = 1;

    for (int i = 1; i <= num; i++)
    {
        factNum = factNum * i;
    }
    return factNum;
}
