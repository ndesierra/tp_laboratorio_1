#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "jugador.h"

int parser_JugadorFromText(FILE* pFile, LinkedList* pArrayListJugador)
{
    int retorno = 0;
    int cantidad;
    jugador* auxJugador;
    char buffer[4][100];

    if (pFile != NULL  && pArrayListJugador != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            auxJugador = jugador_new();
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantidad == 4)
            {
                auxJugador = jugador_newParametros(buffer[0], buffer[1], buffer[2],  buffer[3]);
                ll_add(pArrayListJugador, auxJugador);
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

int parser_JugadorFromBinary(FILE* pFile, LinkedList* pArrayListJugador)
{
    int retorno= 0;
    jugador* auxJugador;

    if(pFile!=NULL && pArrayListJugador!= NULL)
    {
        while(!feof(pFile))
        {
            auxJugador = jugador_new();
            if ( fread ( auxJugador, sizeof(jugador), 1, pFile) != 0)
            {
                ll_add(pArrayListJugador, auxJugador);
                retorno = 1;
            }
        }
    }
    return retorno;
}
