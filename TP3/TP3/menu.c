#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opcion;

    system("cls");
    printf("**** Menu de empleados **** \n\n");
    printf("1.   Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2.   Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3.   Alta de empleado\n");
    printf("4.   Modificar datos de empleado\n");
    printf("5.   Baja de empleado\n");
    printf("6.   Listar empleados\n");
    printf("7.   Ordenar empleados\n");
    printf("8.   Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9.   Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10.  Salir\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menuModificaciones()
{
    int opcion;
    system("cls");
    printf("\n**** Menu de modificaciones ****\n\n");
    printf("1.  Modificar nombre\n");
    printf("2.  Modificar horas trabajadas\n");
    printf("3.  Modificar sueldo\n");
    printf("4.  Salir.\n");

    printf("Ingrese opcion:  ");
    scanf("%d", &opcion);

    return opcion;
}

int menuOrdenamiento()
{
    int opcion;
    system("cls");
    printf("\n**** Menu de Ordenamiento ****\n\n");
    printf("1.  Ordenar por Id\n");
    printf("2.  Ordenar por nombre\n");
    printf("3.  Ordenar por horas trabajadas\n");
    printf("4.  Ordenar por sueldo\n");
    printf("5.  Salir.\n");

    printf("Ingrese opcion:  ");
    scanf("%d", &opcion);

    return opcion;
}
