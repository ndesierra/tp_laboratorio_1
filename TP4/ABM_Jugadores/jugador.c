#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"
#include "validaciones.h"
#include "controller.h"
#include "menu.h"

jugador* jugador_new()
{
    return (jugador*) malloc(sizeof(jugador));
}

jugador* jugador_newParametros(char* idStr, char* apellidoStr, char* posicionStr, char* valor)
{
    jugador* nuevoJugador;

    nuevoJugador = jugador_new();

    if(nuevoJugador != NULL)
    {
        if   ( (jugador_setId(nuevoJugador, atoi(idStr)) == 0) ||
                (jugador_setApellido(nuevoJugador, apellidoStr) == 0) ||
                (jugador_setPosicion(nuevoJugador, posicionStr) == 0)||
                (jugador_setValor(nuevoJugador, atof(valor)) == 0))
        {
            jugador_delete(nuevoJugador);
            nuevoJugador = NULL;
        }
    }
    return nuevoJugador;
}

int jugador_setId(jugador* this,int id)
{
    int retorno = 0;

    if ( this != NULL && id >0 && id <= 1000)
    {
        this-> id = id;
        retorno = 1;
    }
    return retorno;
}

int jugador_getId(jugador* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int jugador_setApellido(jugador* this,char* apellido)
{
    int retorno = 0;

    if (this != NULL  && strlen(apellido) >= 3  && strlen(apellido) < 50)
    {
        strcpy(this->apellido, apellido);
        retorno = 1;
    }
    return retorno;
}

int jugador_getApellido(jugador* this, char* apellido)
{
    int retorno = 0;
    if(this != NULL && apellido!=NULL)
    {
        strcpy(apellido, this->apellido);
        retorno = 1;
    }
    return retorno;
}

int jugador_setPosicion(jugador* this, char* posicion)
{
    int retorno = 0;

    if ( this != NULL && strlen(posicion) >= 3  && strlen(posicion) < 50)
    {
        strcpy(this->posicion, posicion);
        retorno = 1;
    }
    return retorno;
}

int jugador_getPosicion(jugador* this, char* posicion)
{
    int retorno = 0;

    if ( this != NULL && posicion != NULL)
    {
        strcpy(posicion, this->posicion);
        retorno = 1;
    }
    return retorno;
}

int jugador_setValor(jugador* this, float valor)
{
    int retorno = 0;

    if ( this != NULL && valor >0 && valor <= 500000 )
    {
        this-> valor = valor;
        retorno = 1;
    }
    return retorno;
}

int jugador_getValor(jugador* this,float* valor)
{
    int retorno = 0;

    if ( this != NULL && valor != NULL)
    {
        *valor = this->valor;
        retorno = 1;
    }
    return retorno;
}

void jugador_delete(jugador* this )
{
    if ( this != NULL)
    {
        free(this);
    }
}

int jugador_mostrar(jugador* this)
{
    int retorno = 0;
    int id;
    char apellido[50];
    char posicion[50];
    float valor;

    if(this != NULL)
    {
        jugador_getId(this, &id);
        jugador_getApellido(this, apellido);
        jugador_getPosicion(this, posicion);
        jugador_getValor(this, &valor);

        printf("%4d  %20s  %20s  %.2f\n", id, apellido, posicion, valor);
        retorno = 1;
    }
    return retorno;
}

int modificarJugador(jugador* this)
{
    int retorno = 0;
    char salir = 'n';
    char apellido[50];
    char posicion[50];
    float valor;

    system("cls");
    do
    {
        switch(menuModificaciones())
        {
        case 1:
            utn_getNombre(apellido, 49,"\nIngrese un nuevo apellido: ", "\nEl apellido solo puede contener letras y debe tener una longitud menor a 50\n",  10);
            strlwr(apellido);
            apellido[0]= toupper(apellido[0]);
            jugador_setApellido(this, apellido);
            printf("Modificacion exitosa\n\n");
            system("pause");
            retorno = 1;
            break;
        case 2:
            utn_getNombre(posicion, 49,"\nIngrese la nueva posicion: ", "\nLa posicion solo puede contener letras y debe tener una longitud menor a 50\n",  10);
            strlwr(posicion);
            posicion[0]= toupper(posicion[0]);
            jugador_setPosicion(this, posicion);
            printf("Modificacion exitosa\n\n");
            system("pause");
            retorno = 1;
            break;
        case 3:
            utn_getNumeroFlotante(&valor, "\nIngrese el nuevo valor: ", "\nEl valor debe ser un numero entre 1 y 500000\n", 1, 500000, 10);
            jugador_setValor(this, valor);
            printf("Modificacion exitosa\n\n");
            system("pause");
            retorno = 1;
            break;
        case 4:
            salir = 's';
            break;
        default:
            printf("Opcion invalida. Reintente\n");
            break;
        }
    }
    while(salir =='n');
    return retorno;
}

int buscarJugadorPorId(LinkedList* pArrayListJugador, int id)
{
    int retorno = 0;
    int idAux;
    int tam;
    jugador* auxJugador;

    if( pArrayListJugador != NULL && id >0)
    {
        tam = ll_len(pArrayListJugador);
        for(int i=0; i < tam; i++)
        {
            auxJugador = ll_get(pArrayListJugador, i);
            if(jugador_getId(auxJugador, &idAux)  &&  idAux == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int obtenerId(int* id)
{
    *id = 36;
    int retorno = 0;

    FILE* f;
    f = fopen("proxId.bin","rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        retorno = 1;
    }
    return retorno;
}

int actualizarId(int id)
{
    int retorno = 0;
    int proxId = id;
    proxId++;

    FILE* f;
    f = fopen("proxId.bin","wb");

    if(f != NULL)
    {
        fwrite(&proxId,sizeof(int),1,f);

        fclose(f);
        retorno = 1;
    }
    return retorno;
}

int ordenarJugador(LinkedList* this)
{
    int retorno = 0;
    char salir = 'n';
    int orden;

    system("cls");
    do
    {
        switch(menuOrdenamiento())
        {
        case 1:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los jugadores \n0. Ascendente\n1. Descendente\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarJugadorPorId, orden);
            controller_ListJugador(this);
            system("pause");
            retorno = 1;
            break;
        case 2:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los jugadores \n0. Ascendente\n1. Descendente\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarJugadorPorApellido, orden);
            controller_ListJugador(this);
            system("pause");
            retorno = 1;
            break;
        case 3:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los jugadores \n0. Ascendente\n1. Descendente\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarJugadorPorPosicion, orden);
            controller_ListJugador(this);
            system("pause");
            retorno = 1;
            break;
        case 4:
            utn_getNumero(&orden, "\nIngrese la forma para ordenar los jugadores \n0. Ascendente\n1. Descendente\n","\nError. Ingrese 0 o 1", 0, 1, 10);
            ll_sort(this, ordenarJugadorPorValor, orden);
            controller_ListJugador(this);
            system("pause");
            retorno = 1;
            break;
        case 5:
            salir = 's';
            break;
        default:
            printf("Opcion invalida. Reintente\n");
            break;
        }
    }
    while(salir =='n');
    return retorno;
}

int ordenarJugadorPorApellido(void* a, void* b)
{
    int orden = 0;
    char apellido1[50];
    char apellido2[50];

    if( a != NULL && b != NULL )
    {
        jugador_getApellido((jugador*)a, apellido1);
        jugador_getApellido((jugador*)b, apellido2);

        if (strcmp(apellido1, apellido2) > 0)
        {
            orden = 1;
        }
        else if(strcmp(apellido1, apellido2) < 0)
        {
            orden = -1;
        }
    }
    return orden;
}
int ordenarJugadorPorPosicion(void* a, void* b)
{
    int orden = 0;
    char posicion1[50];
    char posicion2[50];

    if( a != NULL && b != NULL )
    {
        jugador_getPosicion((jugador*)a, posicion1);
        jugador_getPosicion((jugador*)b, posicion2);

        if (strcmp(posicion1, posicion2) > 0)
        {
            orden = 1;
        }
        else if(strcmp(posicion1, posicion2) < 0)
        {
            orden = -1;
        }
    }
    return orden;
}
int ordenarJugadorPorValor(void* a, void* b)
{
    int orden = 0;
    float valor1;
    float valor2;

    if( a != NULL && b != NULL )
    {
        jugador_getValor(a, &valor1);
        jugador_getValor(b, &valor2);

        if (valor1 < valor2)
        {
            orden = 1;
        }
        else if (valor1 > valor2)
        {
            orden = -1;
        }
    }
    return orden;
}

int ordenarJugadorPorId(void* a, void* b)
{
    int orden = 0;
    int id1;
    int id2;

    if( a != NULL && b != NULL )
    {
        jugador_getId(a, &id1);
        jugador_getId(b, &id2);

        if (id1 < id2)
        {
            orden = 1;
        }
        else if (id1 > id2)
        {
            orden = -1;
        }
    }
    return orden;
}
