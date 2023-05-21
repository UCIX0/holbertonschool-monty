#include "monty.h"

/**
 * monty_suma - Suma los dos valores superiores de una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 *
 * Descripción: El resultado se almacena en el segundo nodo de valor
 *              desde la parte superior y se elimina el valor superior.
 */
void monty_suma(stack_t **stack, unsigned int linea_numero)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		establecer_error_op_tok(error_pila_corta(linea_numero, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_elimina(stack, linea_numero);
}

/**
 * monty_resta - Resta el segundo valor desde la parte superior de
 *             una lista vinculada stack_t por el valor superior.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 *
 * Descripción: El resultado se almacena en el segundo nodo de valor
 *              desde la parte superior y se elimina el valor superior.
 */
void monty_resta(stack_t **stack, unsigned int linea_numero)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		establecer_error_op_tok(error_pila_corta(linea_numero, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_elimina(stack, linea_numero);
}

/**
 * monty_divide - Divide el segundo valor desde la parte superior de
 *             una lista vinculada stack_t por el valor superior.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 *
 * Descripción: El resultado se almacena en el segundo nodo de valor
 *              desde la parte superior y se elimina el valor superior.
 */
void monty_divide(stack_t **stack, unsigned int linea_numero)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		establecer_error_op_tok(error_pila_corta(linea_numero, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		establecer_error_op_tok(error_div(linea_numero));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_elimina(stack, linea_numero);
}

/**
 * monty_multiplica - Multiplica el segundo valor desde la parte superior de
 *             una lista vinculada stack_t por el valor superior.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 *
 * Descripción: El resultado se almacena en el segundo nodo de valor
 *              desde la parte superior y se elimina el valor superior.
 */
void monty_multiplica(stack_t **stack, unsigned int linea_numero)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		establecer_error_op_tok(error_pila_corta(linea_numero, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_elimina(stack, linea_numero);
}

/**
 * monty_modulo - Calcula el módulo del segundo valor desde la
 * parte superior de una lista vinculada stack_t por el valor superior.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 *
 * Descripción: El resultado se almacena en el segundo nodo de valor
 * esde la parte superior y se elimina el valor superior.
 */
void monty_modulo(stack_t **stack, unsigned int linea_numero)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		establecer_error_op_tok(error_pila_corta(linea_numero, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		establecer_error_op_tok(error_div(linea_numero));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_elimina(stack, linea_numero);
}
