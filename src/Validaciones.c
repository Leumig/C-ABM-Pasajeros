#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Validaciones.h"

int validarPalabra(char *palabra)
{
	int todoOk = -1;

	for (int i = 0; i < strlen(palabra); i++)
	{
		while ((palabra == NULL) || (strlen(palabra) < 2) || (strlen(palabra) > 49) ||
		 ((!(palabra[i] >= 65 && palabra[i] <= 90)) && (!(palabra[i] >= 97 && palabra[i] <= 122))))
		{
			printf("Nombre invalido. Debe ingresar entre 2-49 caracteres. Solo letras, sin tildes ni espacios \n");
			printf("[>] Reingrese: ");
			fflush(stdin);
			gets(palabra);
		}

		todoOk = 1;
	}

	return todoOk;
}

int validarInt(int validarInt, int *pNum)
{
	int todoOk = 0;
	int num;
	num = *pNum;

	while (validarInt != 1 || pNum == NULL || num <= 0)
	{
		printf("[>] Error, debe ingresar un numero entero mayor a 0. Reingrese numero: ");
		fflush(stdin);
		validarInt = scanf("%d", &num);
	}

	*pNum = num;
	return todoOk;
}

int validarFloat(int validarFloat, float *pNum)
{
	int todoOk = 0;
	float num;
	num = *pNum;

	while (validarFloat != 1 || pNum == NULL || num <= 5000)
	{
		printf("[>] Error, debe ingresar un precio numerico y mayor a 5000. Reingrese precio: ");
		fflush(stdin);
		validarFloat = scanf("%f", &num);
	}

	*pNum = num;
	return todoOk;
}

int validarCodigoYStatus(char *codigo, int *status)
{
	int todoOk = 0;

	if (codigo != NULL)
	{
		for (int i = 0; i < strlen(codigo); i++)
		{
			while (strlen(codigo) >= 8 || strlen(codigo) <= 6 || 
			((!(codigo[i] >= 65 && codigo[i] <= 90)) && (!(codigo[i] >= 97 && codigo[i] <= 122)) 
			&& (!(codigo[i] >= 48 && codigo[i] <= 57))) ||
			(codigo[0] != 65 && codigo[0] != 66 && codigo[0] != 67 && codigo[0] != 68))
			{
				printf("Codigo erroneo, debe tener 7 digitos de solo numeros y letras. \nTambien recuerde que el "
							 "primer digito solo puede ser 'A', 'B', 'C' o 'D'.\n");
				printf("[>] Reingrese codigo: ");
				fflush(stdin);
				gets(codigo);
			}
		}

		for (int i = 0; i < strlen(codigo); i++)
		{
			switch (codigo[0])
			{
			case 65:
				*status = 2;
				break;

			case 66:
				*status = 3;
				break;

			case 67:
				*status = 1;
				break;

			default:
				*status = 4;
				break;
			}
		}
	}

	return todoOk;
}

int validarTipo(int validarTipo, int *pTipo)
{
	int todoOk = 0;
	int tipo;
	tipo = *pTipo;

	while (validarTipo != 1 || (tipo != 1 && tipo != 2 && tipo != 3 && tipo != 4))
	{
		printf("[>] Error, debe elegir un tipo del 1 al 4. Reingrese tipo: ");
		fflush(stdin);
		validarTipo = scanf("%d", &tipo);
	}

	return todoOk;
}

int validarPath(char *path)
{
	int todoOk = 0;

	if (path != NULL)
	{
		for (int i = 0; i < strlen(path); i++)
		{
			while (strlen(path) >= 1 || ((!(path[i] >= 65 && path[i] <= 90)) && 
			(!(path[i] >= 97 && path[i] <= 122)) && (!(path[i] >= 48 && path[i] <= 57))))
			{
				printf("Path erroneo, debe tener solo digitos y letras.\n");
				printf("[>] Reingrese path: ");
				fflush(stdin);
				gets(path);
			}
		}
	}

	return todoOk;
}
