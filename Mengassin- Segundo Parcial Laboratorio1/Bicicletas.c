#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Bicicletas.h"

eBicicleta* bicicleta_new()
{
    eBicicleta* newbicicleta;
    newbicicleta = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(newbicicleta!=NULL)
    {
            newbicicleta->id_bike=0000;
            strcpy(newbicicleta->nombre,"Vacio");
            strcpy(newbicicleta->tipo,"Vacio");
            newbicicleta->tiempo=00;
    }
    return newbicicleta;
}

eBicicleta* bicicleta_newParametros(char* id_bikeStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    eBicicleta* newBicicleta;
    newBicicleta=bicicleta_new();

    if(newBicicleta!=NULL)
    {
            newBicicleta->id_bike=atoi(id_bikeStr);
            strcpy(newBicicleta->nombre,nombreStr);
            strcpy(newBicicleta->tipo,tipoStr);
            newBicicleta->tiempo=atoi(tiempoStr);
    }
    return newBicicleta;
}

int listBicicleta(eBicicleta* this)
{
    int retorno=1;

    if(this!=NULL )
    {
        printf("|--------------------------------------------------------------|\n");
        printf("|  %03d   |    %10s      |    %10s   |      %03d     |\n",this->id_bike,this->nombre,this->tipo,this->tiempo);
        retorno=0;
    }

    return retorno;
}

int listbicicletas(LinkedList* lista)
{
    int retorno=1;
    int flag=0;
    int tam=ll_len(lista);
    eBicicleta* auxBicicleta;
    if(lista!=NULL )
    {
        printf("|--------------------------------------------------------------|\n");
        printf("|   ID          NOMBRE              TIPO           TIEMPO      |\n");
        printf("|--------------------------------------------------------------|\n");
        for(int i=0;i<tam;i++)
        {
            auxBicicleta=((eBicicleta*)ll_get(lista,i));
            if(auxBicicleta!=NULL)
            {
                listBicicleta(auxBicicleta);
                flag=1;
            }
        }
        retorno=0;
    }
    if(flag==0)
    {
        printf("No hay bicicletas para mostrar\n");
    }
    printf("\n\n");
    return retorno;
}

int filtrarTipoPlayera(void* unaBicicleta)
{
    int auxReturn=0;
    eBicicleta* x;
    if(unaBicicleta!=NULL)
    {
        x=(eBicicleta*)unaBicicleta;
        if(strcmp(x->tipo,"PLAYERA")==0)
        {
            auxReturn=1;
        }
    }
    return auxReturn;
}
int filtrarTipoBmx(void* unaBicicleta)
{
    int auxReturn=0;
    eBicicleta* x;
    if(unaBicicleta!=NULL)
    {
        x=(eBicicleta*)unaBicicleta;
        if(strcmp(x->tipo,"BMX")==0)
        {
            auxReturn=1;
        }
    }
    return auxReturn;
}
int filtrarTipoPaseo(void* unaBicicleta)
{
    int auxReturn=0;
    eBicicleta* x;
    if(unaBicicleta!=NULL)
    {
        x=(eBicicleta*)unaBicicleta;
        if(strcmp(x->tipo,"PASEO")==0)
        {
            auxReturn=1;
        }
    }
    return auxReturn;
}
int filtrarTipoMtb(void* unaBicicleta)
{
    int auxReturn=0;
    eBicicleta* x;
    if(unaBicicleta!=NULL)
    {
        x=(eBicicleta*)unaBicicleta;
        if(strcmp(x->tipo,"MTB")==0)
        {
            auxReturn=1;
        }
    }
    return auxReturn;
}

int getRandom()
{
    int aleatorio;
    aleatorio = rand()% 71 + 50;
    return aleatorio;
}

void cargarTiempos(void* unaBicicleta)
{
    eBicicleta* x;
    if(unaBicicleta!=NULL)
    {
        x=(eBicicleta*)unaBicicleta;
        if(x->tiempo==0)
        {
            x->tiempo=getRandom();
        }
    }
}

int compararTiempos(void* tiempo1,void* tiempo2)
{
    int rta;
    eBicicleta* a=(eBicicleta*)tiempo1;
    eBicicleta* b=(eBicicleta*)tiempo2;
    if(a->tiempo==b->tiempo)
    {
        rta=0;
    }
    else if(a->tiempo>b->tiempo)
    {
        rta=-1;
    }
    else
    {
        rta=1;
    }
    return rta;
}
