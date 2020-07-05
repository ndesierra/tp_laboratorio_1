#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED


#endif // controller_H_INCLUDED

/** \brief Carga los datos de los jugadores desde el archivo player.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListJugador);


/** \brief Carga los datos de los jugadores desde el archivo player.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListJugador);


/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_addJugador(LinkedList* pArrayListJugador);


/** \brief Modificar datos de jugador
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editJugador(LinkedList* pArrayListJugador);


 /** \brief Baja de jugador
*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_removeJugador(LinkedList* pArrayListJugador);


/** \brief Listar jugadores
*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_ListJugador(LinkedList* pArrayListJugador);


 /** \brief Ordenar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_sortJugador(LinkedList* pArrayListJugador);


/** \brief Guarda los datos de los jugadores en el archivo player.csv (modo texto).
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_saveAsText(char* path, LinkedList* pArrayListJugador);


 /** \brief Guarda los datos de los jugadores en el archivo player.bin (modo binario).
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_saveAsBinary(char* path, LinkedList* pArrayListJugador);
