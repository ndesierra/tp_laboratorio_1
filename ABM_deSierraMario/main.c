#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"

#define LEN 1000
#define STRING_LEN 51

int main()
{
    char seguir = 's';
    char confirma;
    int id = 1;
    char name[STRING_LEN];
    char lastname[STRING_LEN];
    float salary = 0;
    int sector = 0;
    Employee lista [LEN];
    int flag1 = -1;

    initEmployees(lista, LEN);

    do
    {
        switch(menu())
        {
        case 1:
            if(addEmployees(lista, LEN, id, name, lastname, salary, sector) == -1)
            {
                id++;
                flag1 = 0;
            }
            break;
        case 2:
            if (flag1 == 0)
            {
                modifyEmployee(lista, LEN);
            }
            else
            {
                printf("Primero debe efectuar el alta de un empleado\n");
                system("pause");
            }
            break;
        case 3:
            if (flag1 == 0)
            {
                removeEmployee(lista, LEN, id);
            }
            else
            {
                printf("Primero debe efectuar el alta de un empleado\n");
                system("pause");
            }
            break;
        case 4:
            if (flag1 == 0)
            {
                informesEmpleados(lista, LEN);
            }
            else
            {
                printf("Primero debe efectuar el alta de un empleado\n");
                system("pause");
            }
            break;
        case 5:
            printf("Confirma Salida? (s/n) \n");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);

            if (confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
    }
    while (seguir == 's');

    return 0;
}
