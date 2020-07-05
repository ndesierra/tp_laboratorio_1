#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;

}Employee;

#endif // employee_H_INCLUDED


/** \brief Reserva memoria dinamica. Es el constructor vacio de empleados
 *
 * \return devuelve la posicion de memoria en la que asigno el puntero dinamico a empleado
 *
 */
Employee* employee_new();

/** \brief constructor de empleados con parametros, recibe variables, crea un empleado y se las asigna
 *
 * \param id de empleado
 * \param nombre de empleado
 * \param horas trabajadas del empleado
 * \param sueldo de empleado en variable  del tipo cadena de caracteres
 * \return
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief recibe un puntero a empleado y libera la zona de memoria que ocupaba
 *
 * \param puntero a empleado
 *
 */
void employee_delete(Employee* this );


/** \brief recibe un puntero a Employee y  una variable del tipo entero, asigna al atributo id del empleado recibido la variable id recibida por parametro
 *
 * \param puntero a empleado
 * \param variable del tipo entero
 * \return  devuelve 1 si pudo asignarle el id al empleado
                    -1 si el puntero a empleado es nulo o si el id recibido no se encuentra en el rango esperado
 *
 */
int employee_setId(Employee* this,int id);

/** \brief  recibe un puntero a un empleado y el puntero a una variable entera, obtiene el valor del id del empleado recibido y se lo asigna a la variable id recibida
 *
 * \param  puntero a un empleado
 * \param  puntero a una variable id del tipo int
 * \return  devuelve -1 si el empleado es nulo o el puntero a id es nulo
                      1 si pudo realizar la accion
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief  recibe un puntero a Employee y un puntero a una variable del tipo cadena de caracteres, asigna al atributo nombre del empleado recibido la variable nombre recibida por parametro
 *
 * \param puntero a un empleado
 * \param puntero a variable del tipo char
 * \return  devuelve 1 si pudo asignarle nombre al empleado
                    -1 si el puntero a empleado es nulo o si el nombre recibido no se encuentra en el rango esperado
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief recibe un puntero a un empleado y el puntero a una variable del tipo cadena de caracteres, obtiene el valor del nombre del empleado recibido y se lo asigna a la variable nombre recibida
 *
 * \param puntero a un empleado
 * \param puntero a variable del tipo char
 * \return  devuelve -1 si el empleado es nulo o el puntero a nombre es nulo
                      1 si pudo realizar la accion
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief recibe un puntero a Employee y una variable del tipo entero, asigna al atributo horasTrabajadas del empleado recibido la variable horasTrabajadas recibida por parametro
 *
 * \param puntero a un empleado
 * \param variable del tipo entero
 * \return devuelve 1 si pudo asignarle las horas trabajadas al empleado
                   -1 si el puntero a empleado es nulo o si las horas trabajadas recibidas no se encuentran en el rango solicitado
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);

/** \brief recibe un puntero a un empleado y el puntero a una variable del tipo entero, obtiene el valor de las horas trajadas del empleado recibido y se lo asigna a la variable horas trabajadas recibida
 *
 * \param puntero a un empleado
 * \param puntero a variable del tipo int
 * \return devuelve -1 si el empleado es nulo o el puntero a horasTrabajadas es nulo
                     1 si pudo realizar la accion
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief recibe un puntero a Employee y una variable del tipo entero, asigna al atributo sueldo del empleado recibido la variable sueldo recibida por parametro
 *
 * \param puntero a un empleado
 * \param recibe variable del tipo int
 * \return devuelve 1 si pudo asignarle el sueldo al empleado
                   -1 si el puntero a empleado es nulo o si el sueldo recibido no se encuentra en el rango solicitado
 *
 */
int employee_setSueldo(Employee* this, int sueldo);

/** \brief recibe un puntero a un empleado y el puntero a una variable del tipo entero, obtiene el valor de las sueldo del empleado recibido y se lo asigna a la variable sueldo recibida
 *
 * \param puntero a un empleado
 * \param puntero a variable del tipo int
 * \return devuelve -1 si el empleado es nulo o el puntero a sueldo es nulo
                     1 si pudo realizar la accion
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief recibe un puntero a empleado y lo muestra por pantalla
 *
 * \param puntero a un empleado
 * \return  devuelve 1 si el puntero recibido es distinto de nulo
                    -1 si el puntero recibido es nulo
 *
 */
int employee_mostrar(Employee* this);

/** \brief recibe un puntero a Employee e interactua con el usuario para que elija que atributo desea modificar permitiendole modificarlo
 *
 * \param  puntero a un empleado del tipo Employee
 * \return devuelve 1 si se pudo realizar alguna modificacion
                   -1 en caso contrario
 *
 */
int modificarEmployee(Employee* this);

/** \brief busca en la lista el empleado que posea el id recibido por parametro y devuelve su indice
 *
 * \param puntero a una lista
 * \param variable del tipo entero
 * \return -1 si no existe en la lista un empleado con el id proporcionado
            El indice del empleado con el id recibido si existe
 *
 */
int buscarEmployeePorId(LinkedList* pArrayListEmployee, int id);

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
int ordenarEmployee(LinkedList* this);

/** \brief Compara las horas trabajadas de los empleados recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si las horas trabajadas de los empleados son iguales
                    1 si "a" es mayor a "b"
                   -1 si "a" es menor a "b"
 *
 */
int ordenarEmployeesPorHorasTrabajadas(void* a, void* b);

/** \brief Compara los nombres de los empleados recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los nombres de los empleados son iguales
                    1 si el nombre de "a" es mayor al nombre de "b"
                   -1 si el nombre de "a" es menor al nombre de "b"
 *
 */
int ordenarEmployeesPorNombre(void* a, void* b);

/** \brief Compara los sueldos de los empleados recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los sueldos de los empleados son iguales
                    1 si "a" es mayor a "b"
                   -1 si "a" es menor a "b"
 *
 */
int ordenarEmployeesPorSueldo(void* a, void* b);

/** \brief Compara los id de los empleados recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los id de los empleados son iguales
                    1 si "a" es mayor a "b"
                   -1 si "a" es menor a "b"
 *
 */
int ordenarEmployeesPorId(void* a, void* b);
