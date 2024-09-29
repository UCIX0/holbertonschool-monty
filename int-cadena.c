#include "monty.h"

/**
 * obtener_entero - obtiene un puntero a una
 * nueva cadena que contiene un entero
 * @num: número a convertir a cadena
 *
 * Return: puntero a la nueva cadena creada. NULL si falla el malloc.
 */
char *obtener_entero(int num)
{
	unsigned int temp;
	int longitud = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	longitud = obtener_longitud_base_num(temp, 10);

	if (num < 0 || num_l < 0)
		longitud++; /* signo negativo */
	ret = malloc(longitud + 1); /* crear nueva cadena */
	if (!ret)
		return (NULL);

	llenar_buff_base_num(temp, 10, ret, longitud);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - obtiene el valor absoluto de un entero
 * @i: entero para obtener el valor absoluto
 *
 * Return: representación de abs de i como entero sin signo
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * obtener_longitud_base_num - obtiene la longitud del
 * buffer necesaria para un entero sin signo
 * @num: número para obtener la longitud necesaria
 * @base: base de la representación numérica utilizada por el buffer
 *
 * Return: entero que contiene la
 * longitud del buffer necesaria (no contiene bt nulo)
 */
int obtener_longitud_base_num(unsigned int num, unsigned int base)
{
	int len = 1; /* todos los números contienen al menos un dígito */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * llenar_buff_base_num - llena el buffer con
 * los números correctos hasta la base 36
 * @num: número a convertir a cadena dada la base
 * @base: base del número utilizado en la conversión,
 * solo funciona hasta la base 36
 * @buff: buffer para llenar con el resultado de la conversión
 * @tamano_buff: tamano del buffer en bytes
 *
 * Return: siempre vacío.
 */
void llenar_buff_base_num(unsigned int num, unsigned int base,
			char *buff, int tamano_buff)
{
	int rem, i = tamano_buff - 1;

	buff[tamano_buff] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* retornar representación de valor ascii en minúsculas */
			buff[i] = rem + 87; /* 10 será a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
