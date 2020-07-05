#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    char seguir = 's';
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            if(flag == 0)
            {
                controller_loadFromText("data.csv",listaEmpleados);
                flag = 1;
                system("pause");
            }
            else
            {
                printf("Ya se ha cargado la lista de empleados anteriormente\n");
                system("pause");
            }
            break;
        case 2:
            if( flag == 0)
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
                flag = 1;
                system("pause");
            }
            else
            {
                printf("Ya se ha cargado la lista de empleados anteriormente\n");
                system("pause");
            }
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            if( !ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados que editar\n");
            }
            system("pause");
            break;
        case 5:
            if( !ll_isEmpty(listaEmpleados))
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados que remover\n");
            }
            system("pause");
            break;
        case 6:
            if( !ll_isEmpty(listaEmpleados))
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados que listar\n");
            }
            system("pause");
            break;
        case 7:
            if( !ll_isEmpty(listaEmpleados))
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados que ordenar\n");
            }
            system("pause");

            break;
        case 8:
            if( !ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv",listaEmpleados);
                printf("Guardado exitoso\n");
            }
            else
            {
                printf("No hay empleados que guardar\n");
            }
            system("pause");
            break;
        case 9:
            if( !ll_isEmpty(listaEmpleados))
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
                printf("Guardado exitoso\n");
            }
            else
            {
                printf("No hay empleados que guardar\n");
            }
            system("pause");
            break;
        case 10:
            seguir = 'n';
            break;
        default:
            printf("Ha ingresado una opcion incorrecta. Reintente\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
