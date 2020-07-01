#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "controladores.h"
#include <time.h>
#define TAMARCHIVO 50
#include "utn_biblioteca.h"
int menuMain(void);
int main()
{
    LinkedList* lista=ll_newLinkedList();
    LinkedList* listaFiltradaMuertos=ll_newLinkedList();
    LinkedList* listaFiltradaInfectadosHorno=ll_newLinkedList();
    srand(time(NULL));

    int menuOption;
    int flagCarga=0;
    char archivo[TAMARCHIVO];


    if(lista==NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        menuOption=menuMain();
        switch(menuOption)
        {
        case 1:
            if(!flagCarga)
            {
                printf("ingrese nombre del archivo tipo csv ej: data.csv: ");
                fflush(stdin);
                scanString(archivo,TAMARCHIVO);
                if(controller_loadFromText(archivo,lista))
                {
                    flagCarga=1;
                }

            }
            else
            {
                printf("Ya fue cargado un archivo\n");
            }
            break;
        case 2:
            list_Paises(lista);
            break;
        case 3:
            lista=ll_map(lista,asignarRandomInfectados);
            lista=ll_map(lista,asignarRandomMuertos);
            lista=ll_map(lista,asignarRandomRecuperados);
            printf("Asignaciones realizadas con exito\n");
            break;
        case 4:
            listaFiltradaMuertos=ll_filter(lista,filtrarPorMuertos);
            if(listaFiltradaMuertos!=NULL)
            {
                list_Paises(listaFiltradaMuertos);
                controller_saveAsText("pandemiaSalvados.csv" , listaFiltradaMuertos);
            }
            break;
        case 5:
            listaFiltradaInfectadosHorno=ll_filter(lista,filtrarPorInfectadosAlHorno);
            if(listaFiltradaInfectadosHorno!=NULL)
            {
                list_Paises(listaFiltradaInfectadosHorno);
                controller_saveAsText("pandemiaAlhorno.csv" , listaFiltradaInfectadosHorno);
            }
            break;
        case 6:
            ll_sort(lista,comparaPorInfectados,0);
            break;
        case 7:
            mayorInfectados(lista);
            break;
        case 8:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while(menuOption!=8);


    ll_deleteLinkedList(lista);
    return 0;
}

int menuMain(void)
{

    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Cargar Archivo\n");
    printf("2-Imprimir lista\n");
    printf("3-Asignar estadisticas\n");
    printf("4-Filtrar por paises exitosos\n");
    printf("5-Filtrar por paises en el horno\n");
    printf("6-Ordenar por nivel de infeccion\n");
    printf("7-Mostrar mas castigado\n");
    printf("8-Salir\n");

    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}


