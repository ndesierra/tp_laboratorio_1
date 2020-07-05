#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int cantidad;
    Employee* auxEmployee;
    char buffer[4][100];

    if (pFile != NULL  && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            auxEmployee = employee_new();
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantidad == 4)
            {
                auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2],  buffer[3]);
                ll_add(pArrayListEmployee, auxEmployee);
                retorno = 1;
            }
            else
            {
                break;
            }
        }
    }
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno= 0;
    Employee* auxEmployee;

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee = employee_new();
            if ( fread ( auxEmployee, sizeof(Employee),1,pFile) != 0)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                retorno = 1;
            }
        }
    }
    return retorno;
}
