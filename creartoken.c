#include "monty.h"
char **cadAVector(char *str, char *delims);
/**
 * cadAVector - toma una cadena y separa sus palabras
 *
 * @str: cadena para separar en palabras
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: matriz 2D de punteros a cada palabra
 */

char **cadAVector(char *str, char *delims)
{
	char **palabras = NULL;
	int wc, longitudPalabra, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = obtener_cantidad_palabras(str, delims);


	if (wc == 0)
		return (NULL);
	palabras = malloc((wc + 1) * sizeof(char *));
	if (palabras == NULL)
		return (NULL);
	while (i < wc)
	{
		longitudPalabra = obtener_longitud_palabra(str, delims);
		if (es_delim(*str, delims))
		{
			str = obtener_siguiente_palabra(str, delims);
		}
		palabras[i] = malloc((longitudPalabra + 1) * sizeof(char));
		if (palabras[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(palabras[i]);
			}
			free(palabras);
			return (NULL);
		}
		n = 0;
		while (n < longitudPalabra)
		{
			palabras[i][n] = *(str + n);
			n++;
		}
		palabras[i][n] = '\0';
		str = obtener_siguiente_palabra(str, delims);
		i++;
	}
	palabras[i] = NULL;
	return (palabras);
}

/**
 * es_delim - verifica si la corriente tiene un carácter delimitador
 *
 * @ch: caracter en la corriente
 *
 * @delims: Puntero a matriz terminada en nulo de delimitadores
 *
 * Return: 1 (éxito) 0 (falla)
 */

int es_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * obtener_longitud_palabra - obtiene la longitud de la palabra actual en str
 *
 * @str: cadena para obtener la longitud de la palabra actual
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: longitud de la palabra actual
 */

int obtener_longitud_palabra(char *str, char *delims)
{
	int longitudPalabra = 0, pendiente = 1, i = 0;

	while (*(str + i))
	{
		if (es_delim(str[i], delims))
			pendiente = 1;
		else if (pendiente)
		{
			longitudPalabra++;
		}
		if (longitudPalabra > 0 && es_delim(str[i], delims))
			break;
		i++;
	}
	return (longitudPalabra);
}

/**
 * obtener_cantidad_palabras - obtiene la cantidad de palabras de una cadena
 *
 * @str: cadena para obtener la cantidad de palabras
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: la cantidad de palabras de la cadena
 */

int obtener_cantidad_palabras(char *str, char *delims)
{
	int wc = 0, pendiente = 1, i = 0;

	while (*(str + i))
	{
		if (es_delim(str[i], delims))
			pendiente = 1;
		else if (pendiente)
		{
			pendiente = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * obtener_siguiente_palabra - obtiene la siguiente palabra en una cadena
 *
 * @str: cadena para obtener la siguiente palabra
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: puntero al primer carácter de la siguiente palabra
 */

char *obtener_siguiente_palabra(char *str, char *delims)
{
	int pendiente = 0;
	int i = 0;

	while (*(str + i))
	{
		if (es_delim(str[i], delims))
			pendiente = 1;
		else if (pendiente)
			break;
		i++;
	}
	return (str + i);
}
