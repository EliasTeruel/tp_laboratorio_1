/*
 * bibloTP1.h
 */
#ifndef BIBLOTP1_H_
#define BIBLOTP1_H_

int utn_GetInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado);

float utn_Debito(float numero1, float* pResultado);
float utn_Creito(float numero1, float* pResultado);
float utn_Bitcoin(float numero1, float* pResultado);
float utn_PrecioKm(float numero1, float numero2, float* pResultado);
float utn_Diferencia(float numero1, float numero2, float* pResultado);

int utn_PrintChatInt(char* msj, int numero);
int utn_PrintString(char* msj);
int utn_PrintChatFloat(char* msj, float numero);
int utn_StringInt(char* msj, int* pResultado);
char utn_StringChar(char* msj, char* pResultado);

#endif
