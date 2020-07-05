#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "jugador.h"
#include "Controller.h"
#include "validaciones.h"
#include "parser.h"


int controller_loadFromText(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;
    FILE* pFile;

    if(path != NULL && pArrayListJugador != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_JugadorFromText(pFile, pArrayListJugador))
            {
                retorno = 1;
                printf("Se cargaron correctamente los jugadores\n");
            }
            else
            {
                printf("Error al cargar los jugadores\n");
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

int controller_loadFromBinary(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;
    FILE* pFile;

    if(path!=NULL && pArrayListJugador!=NULL)
    {
        pFile = fopen(path, "rb");
        if( pFile != NULL)
        {
            if(parser_JugadorFromBinary(pFile,pArrayListJugador))
            {
                retorno = 1;
                printf("Se cargaron correctamente los jugadores\n");
            }
            else
            {
                printf("Error al cargar los jugadores\n");
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

int controller_addJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;
    int id;
    char apellido[50];
    char posicion[50];
    float valor;
    char idStr[20];
    char valorStr[20];

    jugador* auxJugador;

    system("cls");
    printf("**** Alta de jugador **** \n\n");

    if ( pArrayListJugador != NULL)
    {
        utn_getNombre(apellido, 49,"\nIngrese el apellido: ", "\nEl apellido solo puede contener letras y debe tener una longitud menor a 50. Reintente\n",  10);
        utn_getNombre(posicion, 49,"\nIngrese la posicion: ", "\nLa posicion solo puede contener letras y debe tener una longitud menor a 50. Reintente\n",  10);
        utn_getNumeroFlotante(&valor, "\nIngrese el valor: ", "\nEl valor debe ser un numero entre 1 y 500000.\n", 1, 500000, 10);

        obtenerId(&id);
        strlwr(apellido);
        apellido[0]= toupper(apellido[0]);
        strlwr(posicion);
        posicion[0]= toupper(posicion[0]);
        itoa(valor, valorStr, 10);
        itoa(id, idStr, 10);
        auxJugador = jugador_newParametros(idStr, apellido, posicion, valorStr);
        if (auxJugador != NULL)
        {
            ll_add(pArrayListJugador, auxJugador);
            printf("\nAlta exitosa\n");
            actualizarId(id);
            retorno = 1;
        }
    }
    else
    {
        printf("\nNo se pudo dar de alta al jugador\n");
    }
    system("pause");
    return retorno;
}

int controller_editJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;
    int id;
    int indice;

    system("cls");

    if ( pArrayListJugador != NULL)
    {
        controller_ListJugador(pArrayListJugador);
        utn_getNumero(&id, "\nIngrese el ID del jugador a modificar: ","\nEl id debe debe ser un numero entre 1 y 1000", 1, 1000, 10);

        indice = buscarJugadorPorId(pArrayListJugador, id);

        if(indice != 0)
        {
            system("cls");
            printf("\nEl jugador a modificar es:  \n\n");

            printf("\n  Id              Apellido            Posicion     Valor \n");
            printf("-----------------------------------------------------------\n");

            jugador_mostrar((jugador*) ll_get(pArrayListJugador,indice));
            modificarJugador((jugador*) ll_get(pArrayListJugador,indice));
            retorno = 1;
        }
        else
        {
            printf("No hay jugadores con el id: %d\n",id);
            system("pause");
        }
    }
    return retorno;
}

int controller_removeJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;
    int indice;
    int id;
    char confirma;

    if(pArrayListJugador != NULL)
    {
        controller_ListJugador(pArrayListJugador);

        if(utn_getNumero(&id,"\nIngrese el id del jugador a eliminar: ","\nEl id debe debe ser un numero entre 1 y 1000\n",1,1000,10))
            {
                indice = buscarJugadorPorId(pArrayListJugador, id);

                if(indice!= 0)
                {
                    printf("El jugador a eliminar es el siguiente: \n\n");
                    printf("\n  Id              Apellido            Posicion     Valor \n");
                    printf("-----------------------------------------------------------\n");

                    jugador_mostrar((jugador*) ll_get(pArrayListJugador,indice));

                    printf("Esta seguro que desea dar de baja al jugador?  [s/n] ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if (confirma == 's')
                    {
                        ll_remove(pArrayListJugador, indice);
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
                    printf("No hay jugadores con el id: %d\n",id);
                    system("pause");
                }
            }
    }
    else
    {
        printf("No hay jugadores en la lista\n");
        retorno = -1;
    }
    return retorno;
}

int controller_ListJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;
    int tam;
    int flag = 0;
    jugador* auxJugador;

    if( pArrayListJugador != NULL)
    {
        printf("\n  Id              Apellido            Posicion     Valor \n");
        printf("-----------------------------------------------------------\n");

        tam = ll_len(pArrayListJugador);

        for(int i=0; i< tam; i++)
        {
            auxJugador = (jugador*) ll_get(pArrayListJugador, i);
            if (  auxJugador != NULL )
            {
                jugador_mostrar( auxJugador );
                retorno = 1;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay jugadores que mostrar\n");
        }
    }
    return retorno;
}

int controller_sortJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;

    if( pArrayListJugador != NULL)
    {
        ordenarJugador( pArrayListJugador);
        retorno = 1;
    }
    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;
    int id;
    char apellido[50];
    char posicion[50];
    float valor;
    int tam;

    FILE* f = NULL;
    jugador* auxJugador;

    if(path != NULL &&  pArrayListJugador != NULL)
    {
        f = fopen(path,"w");
        fprintf(f,"\nId,Apellido,Posicion,Valor\n");
        tam =  ll_len(pArrayListJugador);

        for (int i=0; i<tam; i++)
        {
            auxJugador = (jugador*) ll_get(pArrayListJugador, i);
            if (auxJugador !=NULL)
            {
                jugador_getId(auxJugador, &id);
                jugador_getApellido(auxJugador, apellido);
                jugador_getPosicion(auxJugador, posicion);
                jugador_getValor(auxJugador, &valor);

                fprintf(f, "%d,%s,%s,%.2f\n", id, apellido, posicion, valor);
                retorno = 1;
            }
        }
        fclose(f);
        ll_clear(pArrayListJugador);
    }
    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;
    int tam;
    FILE* f = NULL;
    jugador* auxJugador;

    if(path != NULL &&  pArrayListJugador != NULL)
    {
        f = fopen(path,"wb");
        tam =  ll_len(pArrayListJugador);

        for (int i=0; i<tam; i++)
        {
            auxJugador = (jugador*) ll_get(pArrayListJugador, i);
            if (auxJugador != NULL)
            {
                fwrite(auxJugador, sizeof(jugador), 1, f);
                retorno = 1;
            }
        }
        fclose(f);
        ll_clear(pArrayListJugador);
    }
    return retorno;
}
