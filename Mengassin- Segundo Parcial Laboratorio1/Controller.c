#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Bicicletas.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    FILE* pFile;
    int retorno=-1;
    int cant;
    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            cant=parser_EmployeeFromText(pFile,pArrayList);
            if(cant!=-1)
            {
                retorno=cant;
            }
            fclose(pFile);
        }
    }
    return retorno;
}

int controller_ListBicicletas(LinkedList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        retorno=listbicicletas(pArrayList);
    }

    return retorno;
}

int controller_filtrarBicicletas(LinkedList* pArrayList,LinkedList* pArrayListFilt)
{
    int retorno=-1;
    int opcion;
    if(pArrayList!=NULL && pArrayListFilt!=NULL)
    {
        printf("Filtrar bicicletas por tipo.\n\n");
        printf("Eliga el tipo de bicicleta que desea filtrar: \n");
        printf("1-bmx\n");
        printf("2-playera\n");
        printf("3-mtb.\n");
        printf("4-paseo.\n");
        printf("Ingrese el numero de opcion: ");
        scanf("%d",&opcion);


        if(opcion==1)
        {
            pArrayListFilt=ll_filter(pArrayList,filtrarTipoBmx);
            controller_ListBicicletas(pArrayListFilt);
            controller_saveAsText("bicicletasBmx.csv",pArrayListFilt);
            retorno=0;
        }
        else if(opcion==2)
        {
            pArrayListFilt=ll_filter(pArrayList,filtrarTipoPlayera);
            controller_ListBicicletas(pArrayListFilt);
            controller_saveAsText("bicicletasPlayeras.csv",pArrayListFilt);
            retorno=0;
        }
        else if(opcion==3)
        {
            pArrayListFilt=ll_filter(pArrayList,filtrarTipoMtb);
            controller_ListBicicletas(pArrayListFilt);
            controller_saveAsText("bicicletasMtb.csv",pArrayListFilt);
            retorno=0;
        }
        else if(opcion==4)
        {
            pArrayListFilt=ll_filter(pArrayList,filtrarTipoPaseo);
            controller_ListBicicletas(pArrayListFilt);
            controller_saveAsText("bicicletasPaseo.csv",pArrayListFilt);
            retorno=0;
        }
        else
        {
            printf("Ocion incorrecta.\n");
        }

    }
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    //system("cls");
    FILE* pFile;
    int retorno=-1;
    eBicicleta* auxBicicleta;
    int tam;


    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL)
        {
            fprintf(pFile,"id_bike,nombre,tipo,tiempo\n");
            tam=ll_len(pArrayList);
            retorno=0;
            for(int i=0; i<tam; i++)
            {
                auxBicicleta=((eBicicleta*)ll_get(pArrayList,i));
                if (auxBicicleta!=NULL)
                {
                    fprintf(pFile,"%d,%s,%s,%d\n",auxBicicleta->id_bike,auxBicicleta->nombre,auxBicicleta->tipo,auxBicicleta->tiempo);
                }
            }
            fclose(pFile);
        }
    }
    return retorno;
}

int controller_cargarTiempos(LinkedList* pArrayList,LinkedList* pArrayListTiemp)
{
    int retorno=-1;
    if(pArrayList!=NULL && pArrayListTiemp!=NULL)
    {
        pArrayListTiemp=ll_map(pArrayList,cargarTiempos);
        controller_ListBicicletas(pArrayListTiemp);
        retorno=0;
    }
    return retorno;
}

int controller_ListPos(LinkedList* pArrayList,LinkedList* pArrayListOrd)
{
    int retorno=-1;
    if(pArrayList!=NULL && pArrayListOrd)
    {
        ll_sort(pArrayList,compararTiempos,0);
        controller_ListBicicletas(pArrayList);
        retorno=0;
    }
    return retorno;
}
