/*
 ===================================
 Name        : TP1
 Author      : Elias Teruel
 ===================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibloTP1.h"
int main(void) {

	setbuf(stdout,NULL);

	int km;
	int precioAero;
	int precioLatam;
	int numeroIngresado;
	float debitoAero, resultado;
	float creditoAero, bitcoinAero, precioKmAero, diferencia;
	float debitoLatam, creditoLatam, bitcoinLatam, PrecioKmLatam;
	int pasoOpcionUno=0;
	int pasoOpcionDos=0;
	int pasoOpcionTres=0;
	char letra;

do{
	utn_StringInt("\n\f\f MENU DE OPCIONES \n\n\n 1. Ingresar Kilometros:\n 2. Ingresar Precio de Vuelos:\n 3. Calcular todos los costos:\n 4. Informar Resultados\n 5. Carga forzada de datos\n 6. Salir\n\nIngrese opcion:", &numeroIngresado);

	while(numeroIngresado < 1 || numeroIngresado > 6)
		{
		utn_StringInt("\n Error Ingrese opcion correcta:  \n", &numeroIngresado);
		}

	switch(numeroIngresado)
	{
		case 1:
			utn_StringInt("Ingrese los Kilometros:\n ", &km);
			pasoOpcionUno=1;
			break;
		case 2:
			utn_StringInt(" - Precio vuelo Aerolíneas:\n", &precioAero);
			utn_StringInt(" - Precio vuelo Latam:\n", &precioLatam);
			pasoOpcionDos=2;
			break;
		case 3:

			if(pasoOpcionUno == 0)
			{
				utn_PrintString("\n\nError, falta ingresar en opcion 1\n\n");
				break;
			}else if (pasoOpcionDos == 0)
			{
				utn_PrintString("\n\nError, falta ingresar en opcion 2\n\n");
				break;
			}

			do{
			utn_StringChar(" \n a) Tarjeta de debito descuento 10% \n  b) Tarjeta de credito interes 25% \n  c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) \n  d) Mostrar precio por km (precio unitario) \n  e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas) \n  f) Menu anterior \n Ingrese letra: \n", &letra);

			switch(letra)
			{
			case 'a':
				utn_Debito(precioAero, &resultado);
				debitoAero = resultado;
				utn_Debito(precioLatam, &resultado);
				debitoLatam = resultado;
				break;
			case 'b':
				utn_Creito(precioAero, &resultado);
				creditoAero = resultado;
				utn_Creito(precioLatam, &resultado);
				creditoLatam = resultado;
				break;
			case 'c':
				utn_Bitcoin(precioAero, &resultado);
				bitcoinAero = resultado;
				utn_Bitcoin(precioLatam, &resultado);
				bitcoinLatam = resultado;
				break;
			case 'd':
				utn_PrecioKm(precioAero, km, &resultado);
				precioKmAero = resultado;
				utn_PrecioKm(precioLatam, km, &resultado);
				PrecioKmLatam = resultado;
				break;
			case 'e':
				utn_Diferencia(precioAero, precioLatam, &resultado);
				diferencia = resultado;
				break;
			}

			}while(letra != 'f');

			pasoOpcionTres = 1;

			break;

		case 4:
			if(pasoOpcionUno == 0 )
			{
				utn_PrintString("\n\nError, falta ingresar en opcion 1\n\n");
				break;
			}else if (pasoOpcionDos == 0)
			{
				utn_PrintString("\n\nError, falta ingresar en opcion 2\n\n");
				break;
			}else if(pasoOpcionTres == 0)
			{
				utn_PrintString("\n\nError, falta ingresar en opcion 3\n\n");
				break;
			}
			utn_PrintChatInt("\n KMs: ", km);
			utn_PrintChatFloat("\n Aerolíneas: $", precioAero);
			utn_PrintChatFloat("\n a) Precio con tarjeta de débito: $", debitoAero);
			utn_PrintChatFloat("\n b) Precio con tarjeta de crédito: $", creditoAero);
			utn_PrintChatFloat("\n c) Precio pagando con bitcoin: ", bitcoinAero);
			utn_PrintChatFloat("\n d) Precio unitario: $", precioKmAero);
			utn_PrintChatFloat("\n Latam: $", precioLatam);
			utn_PrintChatFloat("\n a) Precio con tarjeta de débito: $", debitoLatam);
		    utn_PrintChatFloat("\n b) Precio con tarjeta de crédito: $", creditoLatam);
		    utn_PrintChatFloat("\n c) Precio pagando con bitcoin: ", bitcoinLatam);
		    utn_PrintChatFloat("\n d) Precio unitario: $", PrecioKmLatam);
		    utn_PrintChatFloat("\n Diferencia: $", diferencia);

		    pasoOpcionTres = 0;

		    break;

		case 5:
			utn_StringInt("\n Ingrese los Kilometros:\n", &km);
			utn_StringInt(" - Precio vuelo Aerolíneas:\n", &precioAero);
			utn_StringInt(" - Precio vuelo Latam:\n", &precioLatam);
			utn_Debito(precioAero, &resultado);
			debitoAero = resultado;
			utn_Debito(precioLatam, &resultado);
			debitoLatam = resultado;
			utn_Creito(precioAero, &resultado);
			creditoAero = resultado;
			utn_Creito(precioLatam, &resultado);
			creditoLatam = resultado;
			utn_Bitcoin(precioAero, &resultado);
			bitcoinAero = resultado;
			utn_Bitcoin(precioLatam, &resultado);
			bitcoinLatam = resultado;
			utn_PrecioKm(precioAero, km, &resultado);
			precioKmAero = resultado;
			utn_PrecioKm(precioLatam, km, &resultado);
			PrecioKmLatam = resultado;
			utn_Diferencia(precioAero, precioLatam, &resultado);
			diferencia = resultado;


			utn_PrintChatInt("\n KMs ingresados: ", km);
			utn_PrintChatFloat("\n\n Aerolíneas: $", precioAero);
			utn_PrintChatFloat("\n a) Precio con tarjeta de débito: $", debitoAero);
			utn_PrintChatFloat("\n b) Precio con tarjeta de crédito: $", creditoAero);
			utn_PrintChatFloat("\n c) Precio pagando con bitcoin: ", bitcoinAero);
			utn_PrintChatFloat("\n d) Precio unitario: $", precioKmAero);
			utn_PrintChatFloat("\n\n Latam: $", precioLatam);
			utn_PrintChatFloat("\n a) Precio con tarjeta de débito: $", debitoLatam);
			utn_PrintChatFloat("\n b) Precio con tarjeta de crédito: $", creditoLatam);
			utn_PrintChatFloat("\n c) Precio pagando con bitcoin: ", bitcoinLatam);
			utn_PrintChatFloat("\n d) Precio unitario: $", PrecioKmLatam);
			utn_PrintChatFloat("\n Diferencia: $", diferencia);

			break;
	}

}while(numeroIngresado < 6);

printf("\n\n -FIN- \n");

}
