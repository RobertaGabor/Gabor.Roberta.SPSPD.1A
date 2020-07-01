#ifndef EPAIS_H_INCLUDED
#define EPAIS_H_INCLUDED
#include "linkedlist.h"

typedef struct{

int id;
char nombre[25];
int recuperados;
int infectados;
int muertos;

}ePais;

int list_Paises(LinkedList* pArrayList);
int list_Pais(LinkedList* pArrayList,int index);
int pais_getInfectados(ePais* this,int* infectados);
int pais_getMuertos(ePais* this,int* muertos);
int pais_getRecuperados(ePais* this,int* recuperados);
int pais_getId(ePais* this,int* id);
int pais_getNombre(ePais* this,char* nombre);
int pais_setNombre(ePais* this,char* nombre);
int pais_setInfectados(ePais* this,int infectados);
int pais_setMuertos(ePais* this,int muertos);
int pais_setRecuperados(ePais* this,int recuperados);
int pais_setId(ePais* this,int id);
int pais_delete(ePais* pais);
ePais* pais_newParametros(char* idStr,char* nombreStr,char* recuperadosStr,char* infectadosStr,char* muertosStr);
ePais* pais_new();

#endif // EPAIS_H_INCLUDED

