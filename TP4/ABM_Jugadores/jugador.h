#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char apellido[50];
    char posicion[50];
    float valor;

}jugador;

#endif // employee_H_INCLUDED


/** \brief Reserva memoria dinamica. Es el constructor vacio de jugadores
 *
 * \return devuelve la posicion de memoria en la que asigno el puntero dinamico a jugador
 *
 */
jugador* jugador_new();

/** \brief constructor de jugadores con parametros, recibe variables, crea un jugador y se las asigna
 *
 * \param id de jugador
 * \param apellido de jugador
 * \param posicion del jugador
 * \param valor de jugador
 * \return
 *
 */
jugador* jugador_newParametros(char* idStr,char* apellidoStr,char* posicionStr, char* valor);

/** \brief recibe un puntero a jugador y libera la zona de memoria que ocupaba
 *
 * \param puntero a jugador
 *
 */
void jugador_delete(jugador* this );


/** \brief recibe un puntero a jugador y  una variable del tipo entero, asigna al atributo id del jugador recibido la variable id recibida por parametro
 *
 * \param puntero a jugador
 * \param variable del tipo entero
 * \return  devuelve 1 si pudo asignarle el id al jugador
                    -1 si el puntero a jugador es nulo o si el id recibido no se encuentra en el rango esperado
 *
 */
int jugador_setId(jugador* this,int id);

/** \brief  recibe un puntero a un jugador y el puntero a una variable entera, obtiene el valor del id del jugador recibido y se lo asigna a la variable id recibida
 *
 * \param  puntero a un jugador
 * \param  puntero a una variable id del tipo int
 * \return  devuelve -1 si el jugador es nulo o el puntero a id es nulo
                      1 si pudo realizar la accion
 *
 */
int jugador_getId(jugador* this,int* id);

/** \brief  recibe un puntero a jugador y un puntero a una variable del tipo cadena de caracteres, asigna al atributo apellido del jugador recibido la variable apellido recibida por parametro
 *
 * \param puntero a un jugador
 * \param puntero a variable del tipo char
 * \return  devuelve 1 si pudo asignarle apellido al jugador
                    -1 si el puntero a jugador es nulo o si el apellido recibido no se encuentra en el rango esperado
 *
 */
int jugador_setApellido(jugador* this,char* apellido);

/** \brief recibe un puntero a un jugador y el puntero a una variable del tipo cadena de caracteres, obtiene el valor del apellido del jugador recibido y se lo asigna a la variable apellido recibida
 *
 * \param puntero a un jugador
 * \param puntero a variable del tipo char
 * \return  devuelve -1 si el jugador es nulo o el puntero a apellido es nulo
                      1 si pudo realizar la accion
 *
 */
int jugador_getApellido(jugador* this,char* apellido);


/** \brief recibe un puntero a jugador y una variable del tipo entero, asigna al atributo posicion del jugador recibido la variable posicion recibida por parametro
 *
 * \param puntero a un jugador
 * \param variable del tipo entero
 * \return devuelve 1 si pudo asignarle las posicion al jugador
                   -1 si el puntero a jugador es nulo o si las posicion recibidas no se encuentran en el rango solicitado
 *
 */
int jugador_setPosicion(jugador* this, char* posicion);

/** \brief recibe un puntero a un jugador y el puntero a una variable del tipo entero, obtiene el valor de las horas trajadas del jugador recibido y se lo asigna a la variable posicion recibida
 *
 * \param puntero a un jugador
 * \param puntero a variable del tipo int
 * \return devuelve -1 si el jugador es nulo o el puntero a posicion es nulo
                     1 si pudo realizar la accion
 *
 */
int jugador_getPosicion(jugador* this,char* posicion);

/** \brief recibe un puntero a jugador y una variable del tipo entero, asigna al atributo valor del jugador recibido la variable valor recibida por parametro
 *
 * \param puntero a un jugador
 * \param recibe variable del tipo float
 * \return devuelve 1 si pudo asignarle el valor al jugador
                   -1 si el puntero a jugador es nulo o si el valor recibido no se encuentra en el rango solicitado
 *
 */
int jugador_setValor(jugador* this, float valor);

/** \brief recibe un puntero a un jugador y el puntero a una variable del tipo entero, obtiene el valor de las valor del jugador recibido y se lo asigna a la variable valor recibida
 *
 * \param puntero a un jugador
 * \param puntero a variable del tipo float
 * \return devuelve -1 si el jugador es nulo o el puntero a valor es nulo
                     1 si pudo realizar la accion
 *
 */
int jugador_getValor(jugador* this,float* valor);

/** \brief recibe un puntero a jugador y lo muestra por pantalla
 *
 * \param puntero a un jugador
 * \return  devuelve 1 si el puntero recibido es distinto de nulo
                    -1 si el puntero recibido es nulo
 *
 */
int jugador_mostrar(jugador* this);

/** \brief recibe un puntero a jugador e interactua con el usuario para que elija que atributo desea modificar permitiendole modificarlo
 *
 * \param  puntero a un jugador del tipo jugador
 * \return devuelve 1 si se pudo realizar alguna modificacion
                   -1 en caso contrario
 *
 */
int modificarJugador(jugador* this);

/** \brief busca en la lista el jugador que posea el id recibido por parametro y devuelve su indice
 *
 * \param puntero a una lista
 * \param variable del tipo entero
 * \return -1 si no existe en la lista un jugador con el id proporcionado
            El indice del jugador con el id recibido si existe
 *
 */
int buscarJugadorPorId(LinkedList* pArrayListJugador, int id);

/** \brief Abre el archivo proxId.bin, si no existe lo crea y si existe lee el numero de id que contiene y lo guarda en la variable recibida por parametro
 *
 * \param puntero a varible del tipo entero
 * \return devuelve 1 si pudo conseguir el id del archivo
                   -1 si el archivo no existia
 *
 */
int obtenerId(int* id);

/** \brief al id recibido por parametro le suma 1 y lo escribe en el archivo proximoId.bin
 *
 * \param variable del tipo entero
 * \return 1 si pudo actualizar el archivo con la nueva variable
          -1 en caso contrario
 *
 */
int actualizarId(int id);

/** \brief Permite elegir el parametro de ordenamiento
 *
 * \param puntero a Lista
 * \return devuelve la opcion elegida por el usuario
 *
 */
int ordenarJugador(LinkedList* this);

/** \brief Compara las posiciones de los jugadores recibidos por parametro
 *
 * \param puntero a jugador
 * \param puntero a jugador
 * \return devuelve 0 si las posicion de los jugadores son iguales
                    1 si pA es mayor a pB
                   -1 si pA es menor a pB
 *
 */
int ordenarJugadorPorPosicion(void* a, void* b);

/** \brief Compara los apellidos de los jugadores recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los apellidos de los jugadores son iguales
                    1 si el apellido del empA es mayor al apellido del empB
                   -1 si el apellido del empA es menor al apellido del empB
 *
 */
int ordenarJugadorPorApellido(void* a, void* b);

/** \brief Compara los valores de los jugadores recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los valores de los jugadores son iguales
                    1 si pA es mayor a pB
                   -1 si pA es menor a pB
 *
 */
int ordenarJugadorPorValor(void* a, void* b);

/** \brief Compara los Id de los jugadores recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los Id de los jugadores son iguales
                    1 si pA es mayor a pB
                   -1 si pA es menor a pB
 *
 */
int ordenarJugadorPorId(void* a, void* b);
