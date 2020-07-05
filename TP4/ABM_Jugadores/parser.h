#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include "LinkedList.h"

#endif // parser_H_INCLUDED


/** \brief Parsea los datos los datos de los jugadores desde el archivo player.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos los datos de los jugadores desde el archivo player.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

