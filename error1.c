#include "monty.h"
/**
 * error_uso - Imprime mensajes de error de uso.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_uso(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * error_malloc - Imprime mensajes de error de malloc.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * error_abrir_archivo - Imprime mensajes de error al abrir archivo con
 * el nombre del archivo.
 * @nombre_archivo: Nombre del archivo que falló al abrir
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_abrir_archivo(char *nombre_archivo)
{
	fprintf(stderr, "Error: Can't open file %s\n", nombre_archivo);
	return (EXIT_FAILURE);
}

/**
 * error_op_desconocido - Imprime mensajes de error de
 * instrucción desconocida.
 * @codigo_op: Código de operación donde ocurrió
 * el error.
 * @line_number: Número de línea en el archivo de
 * bytes de Monty donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_op_desconocido(char *codigo_op, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, codigo_op);
	return (EXIT_FAILURE);
}

/**
 * error_sin_entero - Imprime mensajes de error de argumento
 * inválido monty_inserta.
 * @line_number: Número de línea en el archivo de bytes de
 * Monty donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_sin_entero(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
