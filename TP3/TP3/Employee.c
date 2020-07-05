#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"
#include "controller.h"
#include "menu.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    Employee* newEmployee;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if   ( (employee_setId(newEmployee, atoi(idStr)) == 0) ||
               (employee_setNombre(newEmployee, nombreStr) ==0) ||
               (employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) ==0)||
               (employee_setSueldo(newEmployee, atoi(sueldo)) == 0))
        {

            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;

    if ( this != NULL && id >0 && id <= 5000)
    {
        this-> id = id;
        retorno = 1;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 50)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = 0;

    if ( this != NULL && horasTrabajadas >0 && horasTrabajadas <= 2000 )
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;

    if ( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = 0;

    if ( this != NULL && sueldo >0 && sueldo <= 500000 )
    {
        this-> sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if ( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

void employee_delete(Employee* this )
{
    if ( this != NULL)
    {
        free(this);
    }
}

int employee_mostrar(Employee* this)
{
    int retorno = 0;
    int id;
    char nombre[50];
    int horas;
    int sueldo;

    if(this != NULL)
    {
        employee_getId(this, &id);
        employee_getNombre(this, nombre);
        employee_getHorasTrabajadas(this, &horas);
        employee_getSueldo(this, &sueldo);

        printf("%4d  %20s  %4d  %5d\n", id, nombre, horas, sueldo);
        retorno = 1;
    }
    return retorno;
}

int modificarEmployee(Employee* this)
{
    int retorno = 0;
    char salir = 'n';
    char nombre[50];
    int horasTrabajadas;
    int sueldo;

    system("cls");
    do
    {
        switch(menuModificaciones())
        {
        case 1:
            utn_getNombre(nombre, 50,"\nIngrese un nuevo nombre: ", "\nEl nombre solo puede contener letras y debe tener una longitud menor a 50\n",  10);
            employee_setNombre(this, nombre);
            printf("Modificacion exitosa\n\n");
            system("pause");
            retorno = 1;
            break;
        case 2:
            utn_getNumero(&horasTrabajadas, "\nIngrese una nueva cantidad de horas trabajadas: ", "\nLa cantidad de horas debe ser un numero del 1 al 2000\n", 1, 2000, 10);
            employee_setHorasTrabajadas(this, horasTrabajadas);
            printf("Modificacion exitosa\n\n");
            system("pause");
            retorno = 1;
            break;
        case 3:
            utn_getNumero(&sueldo, "\nIngrese el nuevo sueldo: ", "\nEl sueldo debe ser un numero entre 1 y 500000\n", 1, 500000, 3);
            employee_setSueldo(this, sueldo);
            printf("Modificacion exitosa\n\n");
            system("pause");
            retorno = 1;
            break;
        case 4:
            salir = 's';
            break;
        default:
            printf("Opcion invalida. Reintente\n");
            break;
        }
    }
    while(salir =='n');
    return retorno;
}

int buscarEmployeePorId(LinkedList* pArrayListEmployee, int id)
{
    int retorno = 0;
    int idAux;
    int tam;
    Employee* auxEmployee;

    if( pArrayListEmployee != NULL && id >0)
    {
        tam = ll_len(pArrayListEmployee);
        for(int i=0; i < tam; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if(employee_getId(auxEmployee, &idAux)  &&  idAux == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int obtenerId(int* id)
{
    *id = 1001;
    int retorno = 0;

    FILE* f;
    f = fopen("proxId.bin","rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        retorno = 1;
    }
    return retorno;
}

int actualizarId(int id)
{
    int proxId = id;
    proxId++;
    int retorno = 0;
    FILE* f;
    f = fopen("proxId.bin","wb");

    if(f != NULL)
    {
        fwrite(&proxId,sizeof(int),1,f);

        fclose(f);
        retorno = 1;
    }
    return retorno;
}

int ordenarEmployee(LinkedList* this)
{
    int retorno = 0;
    char salir = 'n';
    int orden;

    system("cls");
    do
    {
        switch(menuOrdenamiento())
        {
        case 1:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los empleados \n0. Ascendente\n1. Descendete\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarEmployeesPorId, orden);
            controller_ListEmployee(this);
            system("pause");
            retorno = 1;
            break;
        case 2:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los empleados \n0. Ascendente\n1. Descendete\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarEmployeesPorNombre, orden);
            controller_ListEmployee(this);
            system("pause");
            retorno = 1;
            break;
        case 3:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los empleados \n0. Ascendente\n1. Descendete\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarEmployeesPorHorasTrabajadas, orden);
            controller_ListEmployee(this);
            system("pause");
            retorno = 1;
            break;
        case 4:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los empleados \n0. Ascendente\n1. Descendete\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarEmployeesPorSueldo, orden);
            controller_ListEmployee(this);
            system("pause");
            retorno = 1;
            break;
        case 5:
            salir = 's';
            break;
        default:
            printf("Opcion invalida. Reintente\n");
            break;
        }
    }
    while(salir =='n');
    return retorno;
}

int ordenarEmployeesPorNombre(void* a, void* b)
{
    int orden = 0;
    char nombre1[50];
    char nombre2[50];

    if( a != NULL && b != NULL )
    {
        employee_getNombre(a, nombre1);
        employee_getNombre(b, nombre2);

        if (strcmp(nombre1, nombre2) > 0)
        {
            orden = 1;
        }
        else if(strcmp(nombre1, nombre2) < 0)
        {
            orden = -1;
        }
    }
    return orden;
}
int ordenarEmployeesPorHorasTrabajadas(void* a, void* b)
{
    int orden = 0;
    int horas1;
    int horas2;

    if( a != NULL && b != NULL )
    {
        employee_getHorasTrabajadas(a, &horas1);
        employee_getHorasTrabajadas(b, &horas2);

        if (horas1 < horas2)
        {
            orden = 1;
        }
        else if (horas1 > horas2)
        {
            orden = -1;
        }
    }
    return orden;
}
int ordenarEmployeesPorSueldo(void* a, void* b)
{
    int orden = 0;
    int sueldo1;
    int sueldo2;

    if( a != NULL && b != NULL )
    {
        employee_getSueldo(a, &sueldo1);
        employee_getSueldo(b, &sueldo2);

        if (sueldo1 < sueldo2)
        {
            orden = 1;
        }
        else if (sueldo1 > sueldo2)
        {
            orden = -1;
        }
    }
    return orden;
}

int ordenarEmployeesPorId(void* a, void* b)
{
    int orden = 0;
    int id1;
    int id2;

    if( a != NULL && b != NULL )
    {
        employee_getSueldo(a, &id1);
        employee_getSueldo(b, &id2);

        if (id1 < id2)
        {
            orden = 1;
        }
        else if (id1 > id2)
        {
            orden = -1;
        }
    }
    return orden;
}
