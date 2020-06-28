#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Controller.h"
#include "Parser.h"

int main()
{

int menuPrincipal();

    char continuar = 's';
    LinkedList* listaJugadores = ll_newLinkedList();

    do{
        switch(menuPrincipal())
        {
            case 1:
                system("cls");
                if(controller_loadFromText("player.csv", listaJugadores))
                {
                   printf("Jugadores cargados correctamente\n");
                }
                else
                {
                    printf("Problemas para cargar los Jugadores\n");
                }
                system("pause");
                break;
            case 2:
                system("cls");
                if(controller_loadFromBinary("player.bin", listaJugadores))
                {
                    printf("Jugadores cargados correctamente\n");
                }
                else
                {
                    printf("Problemas para cargar los Jugadores\n");
                }
                system("pause");
                break;
            case 3:
                if(controller_addJugador(listaJugadores))
                {
                    printf("Jugador registrado con exito.\n");
                }
                system("pause");
                break;
            case 4:
                if(controller_editJugador(listaJugadores))
                {
                    printf("Jugador editado con exito.\n");
                }
                system("pause");
                break;
            case 5:
                if(controller_removeJugador(listaJugadores))
                {
                    printf("Jugador eliminado con exito.\n");
                }
                system("pause");
            break;
            case 6:
                system("cls");
                if(!controller_ListJugador(listaJugadores))
                {
                    printf("No hay Jugadores que listar\n");
                }
                system("pause");
                break;
            case 7:
                controller_sortJugador(listaJugadores);
                system("pause");
                break;
            case 8:
                controller_FiltJugador(listaJugadores);
                printf("8. Informes\n");
                system("pause");
                break;
            case 9:
                if(controller_saveAsText("player.csv" , listaJugadores))
                {
                    printf("Problemas para guardar el archivo\n");
                }
                else
                {
                    printf("Documento guardado exitosamente\n");
                }
                system("pause");

                break;
            case 10:
                if(controller_saveAsBinary("player.bin" , listaJugadores))
                {
                    printf("Problemas para guardar el archivo\n");
                }
                else
                {
                    printf("Documento guardado exitosamente\n");
                }
                system("pause");

                break;
            case 11:
                 continuar = 'n';
                break;
            default:
                 printf("Opcion invalida. Reingrese una opcion\n");
                 system("pause");
                break;
        }
        system("cls");

    }while(continuar == 's');

    return 0;
}
int menuPrincipal()
{
    int opcion = 0;

    printf("***Menu de opciones***\n\n");
    printf(" 1. Cargar los datos de los jugadores desde el archivo player.csv(modo texto)\n");
    printf(" 2. Cargar los datos de los jugadores desde el archivo player.bin(modo binario)\n");
    printf(" 3. Alta de jugador\n");
    printf(" 4. Modificar datos de jugador\n");
    printf(" 5. Baja de jugador\n");
    printf(" 6. Listar jugadores\n");
    printf(" 7. Ordenar jugadores\n");
    printf(" 8. Informes\n");
    printf(" 9. Guardar los datos de los jugadores en el archivo player.csv (modo texto).\n");
    printf("10. Guardar los datos de los jugadores en el archivo player.bin (modo binario).\n");
    printf("11. Salir\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    system("cls");

    return opcion;
}

