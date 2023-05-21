#include "monty.h"
/**
 * monty_rotl - Rota el valor superior de una lista
 * vinculada stack_t hacia abajo.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_rotl(stack_t **stack, unsigned int linea_numero)
{
	stack_t *arriba, *abajo;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	arriba = (*stack)->next;
	abajo = (*stack)->next;
	while (abajo->next != NULL)
		abajo = abajo->next;

	arriba->next->prev = *stack;
	(*stack)->next = arriba->next;
	abajo->next = arriba;
	arriba->next = NULL;
	arriba->prev = abajo;

	(void)linea_numero;
}

/**
 * monty_rotr - Rota el valor inferior de una
 * lista vinculada stack_t hacia arriba.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_rotr(stack_t **stack, unsigned int linea_numero)
{
	stack_t *arriba, *abajo;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	arriba = (*stack)->next;
	abajo = (*stack)->next;
	while (abajo->next != NULL)
		abajo = abajo->next;

	abajo->prev->next = NULL;
	(*stack)->next = abajo;
	abajo->prev = *stack;
	abajo->next = arriba;
	arriba->prev = abajo;

	(void)linea_numero;
}

/**
 * monty_stack - Convierte una cola en una pila.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_stack(stack_t **stack, unsigned int linea_numero)
{
	(*stack)->n = PILA;
	(void)linea_numero;
}

/**
 * monty_queue - Convierte una pila en una cola.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_queue(stack_t **stack, unsigned int linea_numero)
{
	(*stack)->n = COLA;
	(void)linea_numero;
}

/**
 * establecer_error_op_tok - Establece el último
 * elemento de op_toks como un código de error.
 * @codigo_error: Entero para almacenar como una cadena en op_toks.
 */
void establecer_error_op_tok(int codigo_error)
{
	int longitud_toks = 0, i = 0;
	char *salida_str = NULL;
	char **nuevos_toks = NULL;

	longitud_toks = longitud_arr_token();
	nuevos_toks = malloc(sizeof(char *) * (longitud_toks + 2));
	if (!op_toks)
	{
		error_malloc();
		return;
	}
	while (i < longitud_toks)
	{
		nuevos_toks[i] = op_toks[i];
		i++;
	}
	salida_str = obtener_entero(codigo_error);
	if (!salida_str)
	{
		free(nuevos_toks);
		error_malloc();
		return;
	}
	nuevos_toks[i++] = salida_str;
	nuevos_toks[i] = NULL;
	free(op_toks);
	op_toks = nuevos_toks;
}
