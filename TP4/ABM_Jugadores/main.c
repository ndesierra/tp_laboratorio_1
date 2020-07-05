#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "jugador.h"
#include "menu.h"

int main()
{
    char seguir = 's';
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaClonada = ll_newLinkedList();

    controller_loadFromText("player.csv",listaJugadores);

    do
    {
        switch(menu())
        {
        case 1:
            controller_addJugador(listaJugadores);
            break;
        case 2:
            if( !ll_isEmpty(listaJugadores))
            {
                controller_editJugador(listaJugadores);
            }
            else
            {
                printf("No hay jugadores que editar\n");
            }
            system("pause");
            break;
        case 3:
            if( !ll_isEmpty(listaJugadores))
            {
                controller_removeJugador(listaJugadores);
            }
            else
            {
                printf("No hay jugadores que remover\n");
            }
            system("pause");
            break;
        case 4:
            if( !ll_isEmpty(listaJugadores))
            {
                controller_ListJugador(listaJugadores);
            }
            else
            {
                printf("No hay jugadores que listar\n");
            }
            system("pause");
            break;
        case 5:
            if( !ll_isEmpty(listaJugadores))
            {
                controller_sortJugador(listaJugadores);
            }
            else
            {
                printf("No hay jugadores que ordenar\n");
            }
            system("pause");

            break;
        case 6:
            if( !ll_isEmpty(listaJugadores))
            {
                controller_saveAsText("player.csv",listaJugadores);
                controller_saveAsBinary("player.bin",listaJugadores);
                printf("Guardado exitoso\n");
            }
            else
            {
                printf("No hay jugadores que guardar\n");
            }
            system("pause");
            break;
        case 7:
            listaClonada = ll_clone(listaJugadores);
            if ( listaClonada != NULL || ll_containsAll(listaJugadores, listaClonada) == 1 )
            {
                controller_ListJugador(listaClonada);
                controller_saveAsText("playerAux.csv",listaClonada);
                controller_saveAsBinary("playerAux.bin",listaClonada);

                printf("Copia de seguridad guardada con exito\n");
            }
            else
            {
                printf("Fallo al intentar generar copia de seguridad\n");
            }
            system("pause");
            break;
        case 8:
            seguir = 'n';
            ll_deleteLinkedList(listaJugadores);
            break;
        default:
            printf("Ha ingresado una opcion incorrecta. Reintente\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
