#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"




int printEmployees(Employee* list, int len)
{
    int flag = -1;
    system("cls");
    printf("\n****Listado de empleados****\n");
    printf("    Id        Name    LastName   Salary   Sector\n\n");

    for(int i=0; i < len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            mostrarEmpleado(list[i]);
            flag = 0;
        }
    }
    if (flag == -1)
    {
        printf("No hay empleados que listar\n");
    }
    return flag;
}
void mostrarEmpleado(Employee x)
{
    printf("\n   %d   %10s   %10s      %6.2f   %d\n",  x.id,  x.name,  x.lastname,  x.salary, x.sector );
}
int sortEmployees(Employee* list, int len, int order)
{
    int retorno = -1;
    Employee auxEmpleado;

    printf("Insert order:  (0 = DOWN || 1 = UP)\n");
    scanf("%d", &order);

    if ( order == 1)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j=i+1; j < len; j++)
            {
                if( (strcmp(list[i].lastname, list[j].lastname) > 0) ||
                        ((strcmp(list[i].lastname, list[j].lastname) == 0) && list[i].sector < list[j].sector))
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;
                }
            }
        }
    }
    else if ( order == 0)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j=i+1; j < len; j++)
            {
                if( (strcmp(list[i].lastname, list[j].lastname) < 0) ||
                        ((strcmp(list[i].lastname, list[j].lastname) == 0) && list[i].sector > list[j].sector))
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;
                }
            }
        }
    }
    retorno = 0;
    printEmployees(list, len);
    system("pause");

    return retorno;
}
int initEmployees(Employee* list, int len)
{
    int retorno = -1;
    for(int i=0; i < len; i++)
    {
        list[i].isEmpty =1;
        retorno = 0;
    }
    return retorno;
}
int searchFree(Employee* list, int len)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int findEmployeeById(Employee* list, int len, int id)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {

        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int addEmployees(Employee* list, int len, int id, char* name,char lastName[], float salary, int sector)
{
    //int longitud = STRING_LEN;
    int todoOk = 0;
    int indice = searchFree(list, len);
    Employee auxEmpleado;

    system("cls");
    printf("***Add Employee***\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxEmpleado.id = id;

        printf("Ingrese name: ");
        fflush(stdin);
        gets(name);
        strlwr(name);
        name[0] = toupper(name[0]);
        strncpy(auxEmpleado.name, name, 50);

        printf("Ingrese lastname: ");
        fflush(stdin);
        gets(lastName);
        strlwr(lastName);
        lastName[0] = toupper(lastName[0]);
        strncpy(auxEmpleado.lastname, lastName, 50);

        printf("Ingrese salary: ");
        fflush(stdin);
        scanf("%f", &salary);
        auxEmpleado.salary = salary;

        printf("Ingrese sector: ");
        fflush(stdin);
        scanf("%d", &sector);
        auxEmpleado.sector = sector;

        auxEmpleado.isEmpty = 0;

        list[indice] = auxEmpleado;
        todoOk = -1;
    }

    return todoOk;
}
int removeEmployee(Employee* list, int len, int id)
{
    int retorno = 0;
    int indice;
    char confirma;

    system("cls");
    printf("***Remove Employee***\n\n");
    printf("Enter Id: ");
    scanf("%d", &id);

    indice = findEmployeeById(list, len, id);

    if(   indice == -1   )
    {

        printf("No employee record with id: %d\n", id);
    }
    else
    {
        mostrarEmpleado(list[indice]);

        printf("\nConfirm BAJA?: (s/n)\n");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            list[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
            retorno = -1;
        }
        else
        {
            printf("The operation has been canceled\n");
        }
    }
    return retorno;
}
int modifyEmployee(Employee* list, int len)
{
    int retorno = -1;
    int id;
    int indice;
    char confirma;
    char nuevoNombre[STRING_LEN];
    char nuevoApellido[STRING_LEN];
    int nuevoSector;
    float nuevoSueldo;

    system("cls");
    printf("***Modify Employee***\n\n");
    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = findEmployeeById(list, len, id);

    if(   indice == -1   )
    {

        printf("No employee record with id: %d\n", id);
    }
    else
    {
        mostrarEmpleado(list[indice]);

        printf("Enter the type of data you want to modify: ");
        switch(menuDatos())
        {
        case 1:
            printf("\nModify the name?: (s/n)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if( confirma == 's')
            {
                printf("Enter the new name: ");
                gets(nuevoNombre);
                fflush(stdin);

                strcpy(list[indice].name, nuevoNombre);
                printf("The name has been successfully updated\n\n");
            }
            else
            {
                printf("The operation has been canceled\n\n");
            }
            break;
        case 2:
            printf("\nModify the lastname?: (s/n)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if( confirma == 's')
            {
                printf("Enter the new lastname: ");
                gets(nuevoApellido);
                fflush(stdin);

                strcpy(list[indice].lastname, nuevoApellido);
                printf("The lastname has been successfully updated\n\n");
            }
            else
            {
                printf("The operation has been canceled\n\n");
            }
            break;
        case 3:
            printf("\nModify the salary?: (s/n)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if( confirma == 's')
            {
                printf("Enter the new salary: ");
                scanf("%f", &nuevoSueldo);

                list[indice].salary = nuevoSueldo;
                printf("The salary has been successfully updated\n\n");
            }
            else
            {
                printf("The operation has been canceled\n\n");
            }
            break;
        case 4:
            printf("\nModify the sector?: (s/n)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if( confirma == 's')
            {
                printf("Enter the new sector: ");
                scanf("%d", &nuevoSector);

                list[indice].sector = nuevoSector;
                printf("The sector has been successfully updated\n\n");
            }
            else
            {
                printf("The operation has been canceled\n\n");
            }
            break;

        default:
            printf("It is not a valid parameter\n\n");
            break;
        }
    }
    retorno = 0;
    return retorno;
}

int menu()
{

    int opcion;

    system("cls");
    printf("***Gestion de Empleados***\n\n");
    printf("1. Alta Empleado\n");
    printf("2. Modificar Empleado\n");
    printf("3. Baja Empleado\n");
    printf("4. Informes\n");
    printf("5. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int menuDatos()
{
    int opcion;

    system("cls");
    printf("***Parametros***\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Sueldo\n");
    printf("4. Sector\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int informes()
{
    int opcion;

    system("cls");
    printf("***Informes de Empleados***\n\n");
    printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("2. Total y promedio de los salarios. Empleados que superan el salario promedio\n");
    printf("3. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
void informesEmpleados(Employee* list, int len)
{
    char seguir = 's';
    int order = 0;
    do
    {
        switch(informes())
        {
        case 1:
            sortEmployees(list, len, order);
            break;
        case 2:
            totalPromedioSalarios(list, len);
            break;
        case 3:
            seguir = 'n';
            break;
        }
    }
    while (seguir == 's');
}
int totalPromedioSalarios(Employee* list, int len)
{
    int retorno = -1;
    float acumulador = 0;
    int contadorSueldos = 0;
    int cantMayorPromedio = 0;
    float promedio;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            acumulador+= list[i].salary;
            contadorSueldos++;
        }
    }

    promedio = (float) acumulador/ contadorSueldos;

    for(int i=0; i < len; i++)
    {
        if(list[i].salary > promedio)
        {
            cantMayorPromedio++;
            retorno = 0;
        }
    }
    if(contadorSueldos >0)
    {
        printf("El total de salarios de la empresa es: %.2f\n\n", acumulador);
        printf("El promedio de salarios es: %.2f\n", promedio);
        printf("Empleados que superan el salario promedio: %d\n", cantMayorPromedio);
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        system("pause");
    }

    system("pause");
    return retorno;
}
