/*
 * bibloTP1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibloTP1.h"

////// SACAR 10% DE DESCUENTO CON DEBITO //////////////////
float utn_Debito(float numero1, float* pResultado)
{
	int porcentaje = 10;
	int retorno = -1;

	if(numero1 >0 && pResultado != NULL)
	{
		*pResultado = numero1 - ((numero1 * porcentaje)/100);
		retorno = 0;
	}
	return retorno;
}

////// SACAR 25% DE INCREMENTO CON CREDITO //////////////
float utn_Creito(float numero1, float* pResultado)
{
	int porcentaje = 25;
	int retorno = -1;

	if(numero1 >0 && pResultado != NULL)
	{
		*pResultado = numero1 + ((numero1 * porcentaje)/100);
		retorno = 0;
	}
	return retorno;
}

///////////// BITCOIN //////////////////////
float utn_Bitcoin(float numero1, float* pResultado)
{
	int retorno = -1;

	if(numero1 >0 && pResultado != NULL)
		{
			*pResultado = numero1 / 4606954.55 ;
			retorno = 0;
		}
	return retorno;
}

//////////////////7Mostrar precio por km (precio unitario)/////
float utn_PrecioKm(float numero1, float numero2, float* pResultado)
{
	int retorno = -1;

	if(numero1 >0 && numero2 >0 && pResultado != NULL)
			{
				*pResultado = numero1 / numero2;
				retorno = 0;
			}
		return retorno;
}


/////Mostrar diferencia de precio ingresada (Latam - Aerolíneas)////////////7
float utn_Diferencia(float numero1, float numero2, float* pResultado)
{
	int retorno = -1;

	if(numero1 >0 && numero2 >0 && pResultado != NULL)
			{
				if(numero1 > numero2)
				{
					*pResultado = numero1 - numero2;
				}else
				{
					*pResultado = numero2 - numero1;
				}
				retorno = 0;
			}
		return retorno;
}

//// imprime texto y espera a un dato numerico /////
int utn_StringInt(char* msj, int* pResultado)
{
	int retorno = -1;
	int bufferInt;

	if(msj != NULL && pResultado != NULL)
	{
		printf("%s",msj);
		scanf("%d", &bufferInt);

		*pResultado = bufferInt;

		retorno = 0;
	}
	return retorno;
}

//// imprime texto y espera a un dato tipo letra /////
char utn_StringChar(char* msj, char* pResultado)
{
	int retorno = -1;
	char bufferInt;

	if(msj != NULL && pResultado != NULL)
	{
		printf("%s",msj);
		scanf("%s", &bufferInt);
		fflush(stdin);

		*pResultado = bufferInt;

		retorno = 0;
	}
	return retorno;
}

///////// PRINTF  //////////////
int utn_PrintString(char* msj)
{
	int retorno = -1;

	if(msj != NULL)
	{
		printf("%s",msj);

		retorno = 0;
	}
	return retorno;
}

////////// IMPRIME STRING Y FLOAT ////////////////
int utn_PrintChatFloat(char* msj, float numero)
{
	int retorno = -1;

	if(msj != NULL && numero >= 0 )
	{
		printf("%s",msj);
		printf("%.2f",numero);
		retorno = 0;
	}
	return retorno;
}


////////// IMPRIME STRING Y INT ////////////////
int utn_PrintChatInt(char* msj, int numero)
{
	int retorno = -1;

	if(msj != NULL && numero >= 0 )
	{
		printf("%s",msj);
		printf("%d",numero);
		retorno = 0;
	}
	return retorno;
}

int utn_GetInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
		{
			int bufferInt; // variable transitoria donde guardp las cosas del usuario
			int retorno = -1;
			if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
			{
				do{
				printf("%s",mensaje);
				scanf('%d',bufferInt);
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}else{
					printf("%s",mensajeError);
					reintentos --;
				}
				}while(reintentos >= 0);
			}
			return retorno;
		}


int getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado)
{
	int rtn = 0;
	float auxiliarFloat; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroingresado != NULL && reintentos >= 0)
	{
		printf("\n%s", mensaje);
		retornoScanf = scanf("%f", &auxiliarFloat);
		do
		{
			if (retornoScanf !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo)
			{
				printf("\n%s", mensajeError);
				retornoScanf = scanf("%f", &auxiliarFloat);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroingresado = auxiliarFloat;
				rtn = 1;
			}
		}
		while(reintentos>0);
	}
	return rtn;
}
