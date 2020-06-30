#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Bicicletas.h"
#include "time.h"


int menu();

int main()
{
    LinkedList* listaBicicletas=ll_newLinkedList();
    LinkedList* listaBicicletasFilt=ll_newLinkedList();
    LinkedList* listaBicicletasTiempos=ll_newLinkedList();
    LinkedList* listaBicicletasOrdenadas=ll_newLinkedList();
    char seguir='s';
    char confirma;
    int cant;
    srand(time(NULL));
    int flag=0,flag2=0;;
    char nombreArchivo[10];
    do
    {
        switch(menu())
        {
            case 1:
                {
                    printf("Cargar los datos de las bicicletas.\n");
                    printf("Ingrese el nombre del archivo(no olvidar la extension .csv): ");
                    fflush(stdin);
                    gets(nombreArchivo);
                    //cant=controller_loadFromText("bicicletas.csv",listaBicicletas);
                    cant=controller_loadFromText(nombreArchivo,listaBicicletas);
                    if(cant==-1)
                    {
                        printf("Problemas para cargar las bicicletas.\n");
                    }
                    else
                    {
                        printf("Bicicletas cargadas correctamente \n");
                        flag=1;
                    }
                    break;
                }

            case 2:
                {
                    if(flag==0)
                    {
                        printf("No se cargaron los datos de las bicicletas todavia.\n");
                    }
                    else
                    {
                        printf("Listar bicicletas.\n");
                        if(controller_ListBicicletas(listaBicicletas))
                        {
                            printf("Problemas para listar las bicicletas.\n");
                        }
                        else
                        {
                            printf("Bicicletas listadas correctamente.\n");
                        }
                    }
                    break;
                }
            case 3:
                {
                    if(flag==0)
                    {
                        printf("No se cargaron los datos de las bicicletas todavia.\n");
                    }
                    else
                    {
                        printf("Asignar tiempos.\n");
                        if(controller_cargarTiempos(listaBicicletas,listaBicicletasTiempos))
                        {
                            printf("Problemas para cargar tiempos de bicicletas.\n");
                        }
                        else
                        {
                            printf("Tiempos de bicicletas cargados correctamente.\n");
                            flag2=1;
                        }
                    }
                    break;
                }
            case 4:
                {
                    if(flag==0)
                    {
                        printf("No se cargaron los datos de las bicicletas todavia.\n");
                    }
                    else
                    {
                        if(controller_filtrarBicicletas(listaBicicletas,listaBicicletasFilt))
                        {
                            printf("Problemas para filtrar los datos de las bicicletas.\n");
                        }
                        else
                        {
                            printf("Bicicletas filtrados correctamente.\n");
                        }
                    }
                    break;
                }
            case 5:
                {
                    if(flag==0 || flag2==0)
                    {
                        printf("No se cargaron los datos o no se asignaron los tiempos de las bicicletas todavia.\n");
                    }
                    else
                    {
                        printf("Mostrar posiciones.\n");
                        if(controller_ListPos(listaBicicletas,listaBicicletasOrdenadas))
                        {
                            printf("Problemas para listar las posiciones.\n");
                        }
                        else
                        {
                            printf("Posiciones listadas correctamente.\n");
                        }
                    }
                    break;
                }
            case 6:
                {
                    if(flag==0|| flag2==0)
                    {
                        printf("No se cargaron los datos o no se asignaron los tiempos de las bicicletas todavia.\n");
                    }
                    else
                    {
                        printf("Guardar posiciones.\n");
                        if(controller_saveAsText("bicicletasPosiciones.csv",listaBicicletas))
                        {
                            printf("Problemas para listar las posiciones.\n");
                        }
                        else
                        {
                            printf("Posiciones listadas correctamente.\n");
                        }
                    }
                    break;
                }
            case 7:
                {
                    printf("Confirma salir de gestion de empleados?(s/n): ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma=='s')
                    {
                        seguir='n';
                    }
                    break;
                }

            default:
                {
                    printf("Opcion incorrecta.\n");
                    break;

                }
        }
    system("pause");
    }while(seguir=='s');
    return 0;
}

int menu()
{
    system("cls");
    int opc;
    printf("|---------------------------MENU DE OPCIONES------------------------------|\n");
    printf("1. Cargar los datos de las bicicletas.\n");
    printf("2. Listar bicicletas.\n");
    printf("3. Asignar tiempos.\n");
    printf("4. Filtrar bicicletas por tipo.\n");
    printf("5. Mostrar posiciones.\n");
    printf("6. Guardar posiciones.\n");
    printf("7. Salir del programa.\n");
    printf("Ingrese numero de opcion: ");
    scanf("%d",&opc);
    return opc;
}
