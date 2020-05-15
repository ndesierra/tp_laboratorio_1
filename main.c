/*      TRABAJO PRACTICO N°1
Titulo: Calculadora
Alumno: de Sierra Mario Nicolas
Comision: 1° G
Materia: Programacion I/ LaboratorioI
Profesor: Christian Baus
Año: 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_deSierra.h"



int main()
{
    float A;
    float B;
    int flagA = 0;
    int flagB = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    double r1 = 1;
    double r2 = 1;
    int seguir = 1;


    printf("\n\nBienvenido a la calculadora\n\n");
    system("pause");

   do{


    switch( menu(A, B, flagA, flagB) ){

    case 1:
        system("cls");
        printf("Ingrese el primer Operando (A = x): \n\n");
        scanf("%f", &A);
        flagA = 1;
        flag1 = 1;
        break;


    case 2:
        system("cls");
        if(flag1 == 1)
        {
            printf("Ingrese el segundo Operando (B = y): \n\n");
            scanf("%f", &B);
            flagB = 1;
            flag2 = 1;
            break;
        }
        else{
            printf("Primero debe ingresar el primer operando\n\n");
            system("pause");
            break;
        }

    case 3:
        system("cls");
        if( flag2 == 1){
            printf("\nCalculando la suma (%.2f + %.2f )\n\n", A, B);
            resultadoSuma = sumar(A, B);


            printf("\nCalculando la resta (%.2f - %.2f )\n\n", A, B);
            resultadoResta = restar(A, B);


            printf("\nCalculando la division (%.2f / %.2f )\n\n", A, B);
            resultadoDivision = dividir(A, B);


            printf("\nCalculando la multiplicacion (%.2f * %.2f )\n\n", A, B);
            resultadoMultiplicacion = multiplicar(A, B);


            printf("\nCalculando el factorial (%.2f!) (%.2f!)\n\n", A, B);
            r1 = factorial(A);
            r2 = factorial(B);

            flag3 = 1;
            system("pause");
            break;
        }
        else{
            printf("Antes debe ingresar el segundo operando\n\n");
            system("pause");
            break;
            }


    case 4:
        system("cls");
        if (flag3 == 1)
        {
            printf("\na) El resultado de %.2f + %.2f es: %.2f\n\n", A, B, resultadoSuma);
            printf("\nb) El resultado de %.2f - %.2f es: %.2f\n\n", A, B, resultadoResta);
            if (B != 0){
                printf("\nc) El resultado de %.2f / %.2f es: %.2f\n\n", A, B, resultadoDivision);
            }else{
                printf("d) No es posible realizar la division. Intente con un valor de B mayor a 0\n\n");
            }

            printf("\nd) El resultado de %.2f * %.2f es: %.2f\n\n", A, B, resultadoMultiplicacion);
            if (A >= 0 || B >= 0)
            {
                printf("\ne) El factorial de %.2f es: %.2lf y El factorial de %.2f es: %.2lf\n\n", A, r1, B, r2);
            }
            else
            {
                printf("\nNo es posible factorear un numero negativo.\n\n");
            }
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            system("pause");
            break;

        }
        else{
            printf("Antes realice las operaciones de la opcion 3\n\n");
            system("pause");
            break;


        }
    case 5:
        seguir = 0;
        break;
    }
   }while (seguir == 1);



    return 0;
}
