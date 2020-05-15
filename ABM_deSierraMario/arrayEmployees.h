#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define LEN 1000
#define STRING_LEN 51

typedef struct
{
    int id;
    char name[STRING_LEN];
    char lastname[STRING_LEN];
    float salary;
    int sector;
    int isEmpty;

} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief Displays direct employee data from the vector
 *
 * \param x Pointer to array of employees
 * \return Employee data
 */
void mostrarEmpleado(Employee x);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);

/** \brief Search for the first free position to enter data
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int indice (i) if ok - (-1) if Error
 *
 */
int searchFree(Employee* list, int len);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployees(Employee* list, int len, int id, char* name,char lastName[],float salary,int sector);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Allows modifying employee data
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int retorno (-1) if Error - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len);

/** \brief Its a principal main
 *
 * \return int opcion With a user's choice
 *
 */
int menu();

/** \brief Secondary menu with options to modify
 *
 * \return int opcion With a user's choice
 *
 */
int menuDatos();

/** \brief Secondary menu with options to reports
 *
 * \return int opcion With a user's choice
 *
 */
int informes();

/** \brief Reporting functions call
 *
 * \param list Employee*
 * \param len int
 * \return A type of report
 *
 */
void informesEmpleados(Employee* list, int len);

/** \brief Calculate average wages
 *
 * \param list Employee*
 * \param len int
 * \return int retorno (-1) if Error - (0) if Ok
 *
 */
int totalPromedioSalarios(Employee* list, int len);
