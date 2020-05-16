#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
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

        if(utn_getNombre(name, 51, "\nEnter name: ", "\nInvalid name, retype: ", 50)==0)
        {
            strlwr(name);
            name[0] = toupper(name[0]);
            strncpy(auxEmpleado.name, name, 50);
        }

        if(utn_getNombre(lastName, 51, "\nEnter lastname: ", "\nInvalid lastname, retype: ", 50)== 0)
        {
            strlwr(lastName);
            lastName[0] = toupper(lastName[0]);
            strncpy(auxEmpleado.lastname, lastName, 50);
        }

        if(utn_getNumeroFlotante(&salary,"\nEnter salary: ", "\nInvalid Salary, retype: ", 1, 500000, 50)== 0)
        {
            auxEmpleado.salary = salary;
        }

        if(utn_getNumero(&sector,"\nEnter the sector number: ", "\nInvalid number. Retype: ",1, 10, 50)== 0)
        {
            auxEmpleado.sector = sector;
        }

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
                if(utn_getNombre(nuevoNombre, 51, "\nEnter new name: ", "\nInvalid name, retype: ", 50)==0)
                {
                    strlwr(nuevoNombre);
                    nuevoNombre[0] = toupper(nuevoNombre[0]);
                }
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
                if(utn_getNombre(nuevoApellido, 51, "\nEnter new lastname: ", "\nInvalid lastname, retype: ", 50)==0)
                {
                    strlwr(nuevoApellido);
                    nuevoNombre[0] = toupper(nuevoApellido[0]);
                }

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
                if(utn_getNumeroFlotante(&nuevoSueldo,"\nEnter  new salary: ", "\nInvalid Salary, retype: ", 1, 500000, 50)== 0)
                {
                    list[indice].salary = nuevoSueldo;
                }
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
                if(utn_getNumero(&nuevoSector,"\nEnter the sector number: ", "\nInvalid number. Retype: ",1, 10, 50)== 0)
                {
                    list[indice].sector = nuevoSector;
                }
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
        default:
            printf("Invalid option. Retype: ");
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

int esNumerica(char* cadena, int limite)
{
    int retorno = 1;
    int i;
    for(i=0; i<limite && cadena[i] != '\0'; i++)
    {
        if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
        {
            continue;
        }
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }

    }

    return retorno;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
            getString(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atoi(bufferString) ;

    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    do
    {
        printf("%s",mensaje);
        if(	getInt(&bufferInt) == 0 &&
                bufferInt >= minimo &&
                bufferInt <= maximo)
        {
            retorno = 0;
            *pResultado = bufferInt;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }
    while(reintentos>=0);

    return retorno;
}
int getString(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            if(strlen(bufferString) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }
    return retorno;
}

int esFlotante(char* cadena)
{
    int i=0;
    int retorno = 1;
    int contadorPuntos=0;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(i=0 ; cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                if(cadena[i] == '.' && contadorPuntos == 0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,	float minimo, float maximo, int reintentos)
{
    float bufferFloat;
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
        if(	getString(buffer,sizeof(buffer))==0 &&
                esNombre(buffer,sizeof(buffer)) &&
                strlen(buffer)<longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

int esNombre(char* cadena,int longitud)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
                    (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
                strlen(bufferString) < longitud )
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }
    return retorno;
}
