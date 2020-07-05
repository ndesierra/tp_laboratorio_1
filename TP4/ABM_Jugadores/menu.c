#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opcion;

    system("cls");
    printf("**** Menu de jugadores **** \n\n");
    printf("1.  Alta de jugador\n");
    printf("2.  Modificar datos de jugador\n");
    printf("3.  Baja de jugador\n");
    printf("4.  Listar jugadores\n");
    printf("5.  Ordenar jugadores\n");
    printf("6.  Guardar los datos de los jugadores\n");
    printf("7.  Generar copia de seguridad\n");
    printf("8.  Salir\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menuModificaciones()
{
    int opcion;
    system("cls");
    printf("\n**** Menu de modificaciones ****\n\n");
    printf("1.  Modificar apellido\n");
    printf("2.  Modificar posicion\n");
    printf("3.  Modificar valor\n");
    printf("4.  Salir.\n");

    printf("\nIngrese opcion:  ");
    scanf("%d", &opcion);

    return opcion;
}

int menuOrdenamiento()
{
    int opcion;
    system("cls");
    printf("\n**** Menu de Ordenamiento ****\n\n");
    printf("1.  Ordenar por id\n");
    printf("2.  Ordenar por apellido\n");
    printf("3.  Ordenar por posicion\n");
    printf("4.  Ordenar por valor\n");
    printf("5.  Salir.\n");

    printf("\nIngrese opcion:  ");
    scanf("%d", &opcion);

    return opcion;
}
