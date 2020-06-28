#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Jugador.h"


Jugador* jugador_new()
{
   Jugador* newJugador = (Jugador*)malloc(sizeof(newJugador));
   return newJugador;
}
Jugador* jugador_newParametros(char* id, char* apellido, char* posicion, char* valor)
{
    Jugador* newJugador = NULL;
    newJugador = jugador_new();

    int auxId;
    float auxValor;

    auxId = atoi(id);
    auxValor = atof(valor);

    if( newJugador != NULL && id!= NULL && apellido!= NULL && posicion!= NULL && valor!= NULL)
    {
        jugador_setId(newJugador, &auxId);
        jugador_setApellido(newJugador, apellido);
        jugador_setPosicion(newJugador, posicion);
        jugador_setValor(newJugador, &auxValor);
    }
    return newJugador;
}

void jugador_delete(Jugador* this)
{
    if (this != NULL)
    {
		free(this);
	}
}

int jugador_setId(Jugador* this,int* id)
{
    int retorno = 0;

    if( this != NULL && id >=0)
    {
        this->id = *id;
        retorno = 1;
    }

    return retorno;
}
int Jugador_getId(Jugador* this,int* id)
{
    int retorno = 0;

    if( this != NULL && id!= NULL )
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}

int jugador_setApellido(Jugador* this,char* apellido)
{
    int retorno = 0;

    if( this != NULL && apellido != NULL)
    {
        strcpy(this->apellido, apellido);
        retorno = 1;
    }

    return retorno;

}
int jugador_getApellido(Jugador* this,char* apellido)
{
    int retorno = 0;

    if( this != NULL && apellido!= NULL )
    {
        strcpy(apellido, this->apellido);
        retorno = 1;
    }

    return retorno;
}

int jugador_setPosicion(Jugador* this,char* posicion)
{
    int retorno = 0;

    if( this != NULL && posicion!= NULL)
    {
        strcpy(this->posicion, posicion);
        retorno = 1;
    }

    return retorno;
}
int jugador_getPosicion(Jugador* this,char* posicion)
{
    int retorno = 0;

    if( this != NULL && posicion!= NULL )
    {
        strcpy(posicion, this->posicion);
        retorno = 1;
    }

    return retorno;
}

int jugador_setValor(Jugador* this,float* valor)
{
    int retorno = 0;

    if( this != NULL && valor >=0)
    {
        this->valor = *valor;
        retorno = 1;
    }

    return retorno;
}
int jugador_getValor(Jugador* this,float* valor)
{
    int retorno = 0;

    if( this != NULL && valor!= NULL )
    {
        *valor = this->valor;
        retorno = 1;
    }

    return retorno;
}

int mostrarJugador(Jugador* this)
{
    int retorno =0;
    if(this != NULL)
    {
        retorno = 1;
        printf("%4d  %20s  %4s   %.2f \n", this->id, this->apellido, this->posicion, this->valor);
    }
    return retorno;
}
int mostrarJugadores(int* id, char* apellido, char* posicion, float* valor);

