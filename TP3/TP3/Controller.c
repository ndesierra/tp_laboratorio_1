#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "validaciones.h"
#include "parser.h"
#include <ctype.h>
#include <string.h>

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                retorno = 1;
                printf("Se cargaron correctamente los empleados\n");
            }
            else
            {
                printf("Error al cargar los empleados\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("No pudo abrirse el archivo\n");
        }
    }

    return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path, "rb");
        if( pFile != NULL)
        {
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                retorno = 1;
                printf("Se cargaron correctamente los empleados\n");
            }
            else
            {
                printf("Error al cargar los empleados\n");
            }
        }
        else
        {
            printf("No pudo abrirse el archivo\n");
        }
        fclose(pFile);
    }
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char nombre[50];
    int id;
    int horasTrabajadas;
    int sueldo;
    char horasTrabajadasStr[20];
    char sueldoStr[20];
    char idStr[20];

    Employee* auxEmployee;

    system("cls");
    printf("**** Alta de empleado **** \n\n");

    if ( pArrayListEmployee != NULL)
    {
        utn_getNombre(nombre, 49,"\nIngrese el nombre: ", "\nEl nombre solo puede contener letras y debe tener una longitud menor a 50. Reintente\n",  10);
        utn_getNumero(&horasTrabajadas, "\nIngrese la cantidad de horas trabajadas: ", "\nLa cantidad de horas debe ser un numero del 1 al 2000.\n", 1, 2000, 10);
        utn_getNumero(&sueldo, "\nIngrese el sueldo: ", "\nEl sueldo debe ser un numero entre 1 y 500000.\n", 1, 500000, 10);

        obtenerId(&id);
        strlwr(nombre);
        nombre[0]= toupper(nombre[0]);
        itoa(horasTrabajadas, horasTrabajadasStr, 10);
        itoa(sueldo, sueldoStr, 10);
        itoa(id, idStr, 10);
        auxEmployee = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);
        if (auxEmployee != NULL)
        {
            ll_add(pArrayListEmployee, auxEmployee);
            printf("Alta exitosa\n");
            actualizarId(id);
            retorno = 1;
        }
    }
    else
    {
        printf("No se pudo dar de alta al empleado\n");
    }
    system("pause");
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    int indice;

    system("cls");

    if ( pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumero(&id, "\nIngrese el ID del empleado a modificar: ","\nEl id debe debe ser un numero entre 1 y 2000", 1, 2000, 10);

        indice = buscarEmployeePorId(pArrayListEmployee, id);

        if(indice != 0)
        {
            system("cls");
            printf("\nEl empleado a modificar es:  \n\n");

            printf("\n  Id   Nombre   Horas Trabajadas   Sueldo \n");
            printf("------------------------------------------------------------------------\n");

            employee_mostrar((Employee*) ll_get(pArrayListEmployee,indice));
            modificarEmployee((Employee*) ll_get(pArrayListEmployee,indice));
            retorno = 1;
        }
        else
        {
            printf("No hay empleados con el id: %d\n",id);
            system("pause");
        }
    }
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int indice;
    int id;
    char confirma;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(utn_getNumero(&id,"\nIngrese el id del empleado a eliminar: ","\nEl id debe debe ser un numero entre 1 y 2000\n",0,2000,10))
            {
                indice = buscarEmployeePorId(pArrayListEmployee, id);

                if(indice!= 0)
                {
                    printf("El empleado a eliminar es el siguiente: \n\n");
                    printf("\n  Id   Nombre   Horas Trabajadas   Sueldo \n");
                    printf("--------------------------------------------\n");

                    employee_mostrar((Employee*) ll_get(pArrayListEmployee,indice));

                    printf("¿Esta seguro que desea dar de baja al empleado?  [s/n] ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if (confirma == 's')
                    {
                        ll_remove(pArrayListEmployee, indice);
                        printf("\nBaja exitosa\n");
                        retorno = 1;
                    }
                    else
                    {
                        printf("Se ha cancelado la operacion\n");
                    }
                }
                else
                {
                    printf("No hay empleados con el id: %d\n",id);
                    system("pause");
                }
            }
    }
    else
    {
        printf("No hay empleados en la lista\n");
        retorno = -1;
    }
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int tam;
    int flag = 0;
    Employee* auxEmp;

    if( pArrayListEmployee != NULL)
    {
        printf("\n  Id   Nombre   Horas Trabajadas   Sueldo \n");
        printf("--------------------------------------------\n");

        tam = ll_len(pArrayListEmployee);

        for(int i=0; i< tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if (  auxEmp  != NULL )
            {
                employee_mostrar( auxEmp );
                retorno = 1;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay empleados que mostrar\n");
        }
    }
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if( pArrayListEmployee != NULL)
    {
        ordenarEmployee( pArrayListEmployee);
        retorno = 1;
    }
    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    char nombre[50];
    int horas;
    int sueldo;
    int tam;
    FILE* f = NULL;
    Employee* auxEmployee;

    if(path != NULL &&  pArrayListEmployee != NULL)
    {
        f = fopen(path,"w");
        fprintf(f,"\nId,Nombre,Horas Trabajadas,Sueldo\n");
        tam =  ll_len(pArrayListEmployee);

        for (int i=0; i<tam; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmployee !=NULL)
            {
                employee_getId(auxEmployee, &id);
                employee_getNombre(auxEmployee, nombre);
                employee_getHorasTrabajadas(auxEmployee, &horas);
                employee_getSueldo(auxEmployee, &sueldo);

                fprintf(f, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
                retorno = 1;
            }
        }
        fclose(f);
    }
    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int tam;
    FILE* f = NULL;
    Employee* auxEmployee;

    if(path != NULL &&  pArrayListEmployee != NULL)
    {
        f = fopen(path,"wb");
        tam =  ll_len(pArrayListEmployee);

        for (int i=0; i<tam; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmployee != NULL)
            {
                fwrite(auxEmployee, sizeof(Employee), 1, f);
                retorno = 1;
            }
        }
        fclose(f);
    }
    return retorno;
}
