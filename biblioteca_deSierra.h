#include <stdio.h>
#include <stdlib.h>


#ifndef BIBLIOTECA_DESIERRA_H_INCLUDED
#define BIBLIOTECA_DESIERRA_H_INCLUDED



#endif // BIBLIOTECA_DESIERRA_H_INCLUDED

/** \brief Menu
 *  \param opx Es el primer operando
 *  \param opy Es el segundo operando
 *  \param f1 Es el flag del primer operando
 *  \param f2 Es el flag del segundo operando
 * \return Devuelve un menu de opciones
 *
 */


int menu(float opx, float opy, int f1, int f2);

/** \brief  Funcion para efectuar la operaciones de suma
 *
 * \param a 1er operando
 * \param b 2do operando
 * \return Devuelve la suma de dos operandos
 *
 */


float sumar( float a, float b);


/** \brief  Funcion para efectuar la operaciones de resta
 *
 * \param a 1er operando
 * \param b 2do operando
 * \return Devuelve la resta de dos operandos
 *
 */
float restar( float a, float b);



/** \brief  Funcion para efectuar la operaciones de division
 *
 * \param a 1er operando
 * \param b 2do operando
 * \return Devuelve la division de dos operandos
 *
 */

float dividir ( float a, float b);



/** \brief Funcion para efectuar la operaciones de multiplicacion
 *
 * \param a 1er operando
 * \param b 2do operando
 * \return Devuelve la division de dos operandos
 *
 */

float multiplicar ( float a, float b);

/** \brief Funciona para calcular el factorial de dos numeros
 *
 * \param a Es el primer numero
 * \param b Es el segundo numero
 * \return
 *
 */

 int factorial (float num);

