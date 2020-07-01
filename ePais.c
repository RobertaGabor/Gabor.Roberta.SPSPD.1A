#include <stdio.h>
#include <stdlib.h>
#include "ePais.h"
#include <string.h>
#include "linkedlist.h"
#include "utn_biblioteca.h"



ePais* pais_new()
{
 	ePais* nuevoPais=NULL;

	nuevoPais=(ePais*)malloc(sizeof(ePais));

	if(nuevoPais!=NULL)
	{
		nuevoPais->id=0;
		nuevoPais->infectados=0;
		nuevoPais->muertos=0;
		nuevoPais->recuperados=0;
		strcpy(nuevoPais->nombre,"");
	}
    return nuevoPais;
}
ePais* pais_newParametros(char* idStr,char* nombreStr,char* recuperadosStr,char* infectadosStr,char* muertosStr)
{

	ePais* nuevoPaisParams=NULL;
	nuevoPaisParams=pais_new();
	if(nuevoPaisParams!=NULL)
	{
		if(!(pais_setId(nuevoPaisParams,atoi(idStr))
			&&pais_setMuertos(nuevoPaisParams,atoi(muertosStr))
			&&pais_setRecuperados(nuevoPaisParams,atoi(recuperadosStr))
            &&pais_setInfectados(nuevoPaisParams,atoi(infectadosStr))
            &&pais_setNombre(nuevoPaisParams,nombreStr)))
		{
			pais_delete(nuevoPaisParams);
		}
	}
	return nuevoPaisParams;
}
int pais_delete(ePais* pais)
{

	int retorno=0;
	if(pais!=NULL)
	{
		free(pais);
		retorno=1;
	}

	return retorno;

}

/*--------------GETTERS Y SETTERS--------------------*/

int pais_setId(ePais* this,int id)
{
 	int retorno=0;
	if(this!=NULL&&id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int pais_setRecuperados(ePais* this,int recuperados)
{
 	int retorno=0;
	if(this!=NULL&&recuperados>=0)
	{
		this->recuperados=recuperados;
		retorno=1;
	}
	return retorno;
}
int pais_setMuertos(ePais* this,int muertos)
{
 	int retorno=0;
	if(this!=NULL&&muertos>=0)
	{
		this->muertos=muertos;
		retorno=1;
	}
	return retorno;
}
int pais_setInfectados(ePais* this,int infectados)
{
 	int retorno=0;
	if(this!=NULL&&infectados>=0)
	{
		this->infectados=infectados;
		retorno=1;
	}
	return retorno;
}
int pais_setNombre(ePais* this,char* nombre)
{
 	int retorno=0;
	if(this!=NULL&&nombre!=NULL&&validarStringLetras(nombre,sizeof(nombre)))
	{
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}
int pais_getNombre(ePais* this,char* nombre)
{
 	int retorno=0;
	if(this!=NULL&&nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}

	return retorno;
}
int pais_getId(ePais* this,int* id)
{
 	int retorno=0;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
int pais_getRecuperados(ePais* this,int* recuperados)
{
 	int retorno=0;
	if(this!=NULL&&recuperados!=NULL)
	{
		*recuperados=this->recuperados;
		retorno=1;
	}
	return retorno;
}
int pais_getMuertos(ePais* this,int* muertos)
{
 	int retorno=0;
	if(this!=NULL&&muertos!=NULL)
	{
		*muertos=this->muertos;
		retorno=1;
	}
	return retorno;
}
int pais_getInfectados(ePais* this,int* infectados)
{
 	int retorno=0;
	if(this!=NULL&&infectados!=NULL)
	{
		*infectados=this->infectados;
		retorno=1;
	}
	return retorno;
}

int list_Pais(LinkedList* pArrayList,int index)
{
	int retorno=0;
	char nombre[128];
	int id;
	int muertos;
    int recuperados;
    int infectados;
	ePais* auxiliar=NULL;

	if(pArrayList!=NULL&&index>=0)
	{
		auxiliar=(ePais*)ll_get(pArrayList,index);
		if(auxiliar!=NULL)
		{
			if(pais_getId(auxiliar,&id)
				&&pais_getNombre(auxiliar,nombre)
                &&pais_getMuertos(auxiliar,&muertos)
				&&pais_getRecuperados(auxiliar,&recuperados)
				&&pais_getInfectados(auxiliar,&infectados))
			{
				printf("%6d  %20s      %8d      %8d      %8d\n",id,nombre,recuperados,infectados,muertos);
				retorno=1;
			}
		}


	}

	return retorno;/*flag si se mostro o no*/
}

int list_Paises(LinkedList* pArrayList)
{

	int retorno=0;
	int tam;
	int flag;


	if(pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		printf("%d\n",tam);
		retorno=1;
		printf("    ID             NOMBRE      RECUPERADOS       INFECTADOS      MUERTOS\n");
		for(int i=0;i<tam;i++)
		{
			flag=list_Pais(pArrayList,i);
		}
	}


	if(!flag)
	{
		printf("No hay empleados que mostrar\n");
	}

    return retorno;
}


