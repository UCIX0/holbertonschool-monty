#include "monty.h"
int ejecutar_monty(FILE *script_fd);
/**
 * liberar_tokens - Libera la matriz global op_toks de cadenas.
 */
void liberar_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * longitud_arr_token - Obtiene la longitud de op_toks actual.
 *
 * Return: Longitud de op_toks actual (como int).
 */
unsigned int longitud_arr_token(void)
{
	unsigned int longitud_toks = 0;

	while (op_toks[longitud_toks])
		longitud_toks++;
	return (longitud_toks);
}

/**
 * es_linea_vacia - Comprueba si una línea leída desde getline
 * sólo contiene delimitadores.
 * @linea: Un puntero a la línea.
 * @delims: Una cadena de caracteres delimitadores.
 *
 * Return: Si la línea sólo contiene delimitadores - 1.
 * De lo contrario - 0.
 */
int es_linea_vacia(char *linea, char *delims)
{
	int i, j;

	for (i = 0; linea[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (linea[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * obtener_func_op - Asocia un opcode con su función correspondiente.
 * @opcode: El opcode a asociar.
 *
 * Return: Un puntero a la función correspondiente.
 */
void (*obtener_func_op(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_inserta},
		{"pall", monty_imprimeTodo},
		{"pint", monty_imprimeSup},
		{"pop", monty_elimina},
		{"swap", monty_intercambia},
		{"add", monty_suma},
		{"nop", monty_nop},
		{"sub", monty_resta},
		{"div", monty_divide},
		{"mul", monty_multiplica},
		{"mod", monty_modulo},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * ejecutar_monty - Función principal para ejecutar
 * un script de bytecodes Monty.
 * @script_fd: Descriptor de fichero para un script abierto de bytecodes Monty.
 *
 * Return: EXIT_SUCCESS en éxito, código de error correspondiente en fallo.
 */
int ejecutar_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *linea = NULL;
	size_t len = 0, estado_salida = EXIT_SUCCESS;
	unsigned int numero_linea = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (inicializar_pila(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&linea, &len, script_fd) != -1)
	{
		numero_linea++;
		op_toks = cadAVector(linea, DELIMITADORES);
		if (op_toks == NULL)
		{
			if (es_linea_vacia(linea, DELIMITADORES))
				continue;
			liberar_pila(&stack);
			return (error_malloc());
		}
		else if (op_toks[0][0] == '#') /* línea de comentario */
		{
			liberar_tokens();
			continue;
		}
		op_func = obtener_func_op(op_toks[0]);
		if (op_func == NULL)
		{
			liberar_pila(&stack);
			estado_salida = error_op_desconocido(op_toks[0], numero_linea);
			liberar_tokens();
			break;
		}
		prev_tok_len = longitud_arr_token();
		op_func(&stack, numero_linea);
		if (longitud_arr_token() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				estado_salida = atoi(op_toks[prev_tok_len]);
			else
				estado_salida = EXIT_FAILURE;
			liberar_tokens();
			break;
		}
		liberar_tokens();
	}
	liberar_pila(&stack);

	if (linea && *linea == 0)
	{
		free(linea);
		return (error_malloc());
	}

	free(linea);
	return (estado_salida);
}
