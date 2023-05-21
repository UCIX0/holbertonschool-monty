#include "monty.h"

/**
 * error_pop - Imprime mensajes de error pop para pilas vacías.
 * @line_number: Número de línea en el script donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_pint - Imprime mensajes de error pint para pilas vacías.
 * @line_number: Número de línea en el archivo de bytecodes
 * de Monty donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_pila_corta - Imprime mensajes de error de funciones
 * matemáticas de monty
 * para pilas/colas menores a dos nodos.
 * @line_number: Número de línea en el archivo de
 * bytecodes de Monty donde ocurrió el error.
 * @operacion: Operación donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_pila_corta(unsigned int line_number, char *operacion)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, operacion);
	return (EXIT_FAILURE);
}

/**
 * error_div - Imprime mensajes de error de
 * división para divisiones por 0.
 * @line_number: Número de línea en el archivo de
 * bytecodes de Monty donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_pchar - Imprime mensajes de error pchar para pilas vacías
 * y valores no característicos.
 * @line_number: Número de línea en el archivo de bytecodes
 * de Monty donde ocurrió el error.
 * @mensaje: El mensaje de error correspondiente a imprimir.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_pchar(unsigned int line_number, char *mensaje)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, mensaje);
	return (EXIT_FAILURE);
}
