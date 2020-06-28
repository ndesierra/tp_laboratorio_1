#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo player.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;

    FILE* f;

    if(path != NULL && pArrayListJugador!= NULL)
    {
        f= fopen(path, "r");
        if( f != NULL)
        {
            if(parser_JugadorFromText(f,pArrayListJugador))
            {
                retorno = 1;
            }
            fclose(f);
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo player.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;

    FILE* f;

    if(path != NULL && pArrayListJugador!= NULL)
    {
        f = fopen(path, "rb");
        if( f != NULL)
        {
            retorno = parser_JugadorFromBinary(f,pArrayListJugador);
            fclose(f);
        }
    }
    return retorno;
}

/** \brief Alta de Jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_addJugador(LinkedList* pArrayListJugador)
{
    Jugador* auxJugador;
    int retorno = 0;
    int* id = 36;
    char apellido[128];
    char posicion[128];
    float* valor;

    if(utn_getNombre(apellido, 50, "Ingrese el apellido del jugador: \n", "\nEl apellido contiene caracteres invalidos. Por favor, reigrese: ", 50) &&
    utn_getNombre(posicion, 50, "Ingrese la posicion del jugador: (Arquero-Defensor-Volante-Delantero)\n", "\nLa posicion no es valida.", 50)&&
    utn_getNumeroFlotante(valor, "Ingrese el valor del pase del jugador (50000 | 150000): ", "\nEl valor ingresado no es valido",50000,150000, 50))
    {
        if(auxJugador != NULL)
        {
        id++;
        jugador_setId(auxJugador, id);
        jugador_setApellido(auxJugador, apellido);
        jugador_setPosicion(auxJugador, posicion);
        jugador_setValor(auxJugador, valor);
        ll_add(pArrayListJugador,auxJugador);
        retorno = 1;
        printf("Se ha dado de alta al jugador con exito\n");
        }
    }
    return retorno;
}

/** \brief Modificar datos de Jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;

    return retorno;
}

/** \brief Baja de Jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removeJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;

    if( pArrayListJugador != NULL)
    {
        jugador_delete(pArrayListJugador);
        retorno = 1;
    }

    return retorno;
}

/** \brief Listar Jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ListJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;
    Jugador* auxJugador;
    int flag = 0;
    int tam;

    if(pArrayListJugador != NULL)
    {
        retorno = 1;
        tam = ll_len(pArrayListJugador);
        printf("ID   APELLIDO   POSICION   VALOR\n________________________________\n");
        for(int i=0; i < tam; i++)
        {
            auxJugador = (Jugador*) ll_get(pArrayListJugador,i);
            if(auxJugador != NULL)
            {
                mostrarJugador(auxJugador);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay jugadores en el plantel\n");
        }
    }

    return retorno;
}

/** \brief Ordenar Jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_sortJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;

    return retorno;
}

/** \brief Guarda los datos de los Jugadores en el archivo player.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;
    Jugador* auxJugador;
    FILE* f;
    int tam;

    f = fopen(path, "w");
    if(f != NULL)
    {
        tam= ll_len(pArrayListJugador);
        fprintf(f,"Id   Apellido   Posicion   Valor \n");
        for (int i =0; i<tam; i++)
        {
            auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
            if (auxJugador !=NULL)
            {
                fprintf(f, "%d,%s,%s,%f\n", auxJugador->id, auxJugador->apellido, auxJugador->posicion, auxJugador->valor);
                retorno = 1;
            }
        }
        fclose(f);
    }

    return retorno;
}

/** \brief Guarda los datos de los Jugadores en el archivo player.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListJugador)
{
    int retorno = 0;
    Jugador* auxJugador;
    FILE* f;
    int tam;

    f = fopen(path, "wb");
    if(f != NULL)
    {
        tam= ll_len(pArrayListJugador);
        for (int i =0; i<tam; i++)
        {
            auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
            if (auxJugador !=NULL)
            {
                fwrite(auxJugador, sizeof(Jugador), 1, f);
                retorno = 1;
            }
        }
        fclose(f);
    }

    return retorno;
}

/** \brief Filtrar Jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_FiltJugador(LinkedList* pArrayListJugador)
{
    int retorno = 0;

    return retorno;
}
