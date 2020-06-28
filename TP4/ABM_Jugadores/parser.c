#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Jugador.h"

/** \brief Parsea los datos los datos de los Jugadores desde el archivo player.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
    Jugador* auxJugador;
    int retorno = 0;
    char buffer[4][100];
    int cantidad;

    if( pFile != NULL && pArrayListJugador!= NULL)
    {
        while(!feof(pFile))
        {
            auxJugador = jugador_new();
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantidad == 4)
            {
                auxJugador = jugador_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(pArrayListJugador,auxJugador);
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los Jugadores desde el archivo player.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    Jugador* auxJugador;
    int retorno = 0;

    if( pFile != NULL && pArrayListJugador != NULL)
    {
        while(!feof(pFile))
        {
            auxJugador = jugador_new();
            if(auxJugador != NULL)
            {
                if(fread(auxJugador, sizeof(Jugador), 1, pFile))
                {
                    ll_add(pArrayListJugador,auxJugador);
                }
                else
                {
                    break;
                }
            }
        retorno = 1;
        }
    }
    return retorno;
}
