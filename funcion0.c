#include "monty.h"
void monty_inserta(stack_t **stack, unsigned int linea_numero);

/**
 * monty_inserta - Inserta un valor a una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_inserta(stack_t **stack, unsigned int linea_numero)
{
	stack_t *temporal, *nuevo;
	int i;

	nuevo = malloc(sizeof(stack_t));
	if (nuevo == NULL)
	{
		establecer_error_op_tok(error_malloc());
		return;
	}

	if (op_toks[1] == NULL)
	{
		establecer_error_op_tok(error_sin_entero(linea_numero));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			establecer_error_op_tok(error_sin_entero(linea_numero));
			return;
		}
	}
	nuevo->n = atoi(op_toks[1]);

	if (verificar_modo(*stack) == PILA)
	{
		temporal = (*stack)->next;
		nuevo->prev = *stack;
		nuevo->next = temporal;
		if (temporal)
			temporal->prev = nuevo;
		(*stack)->next = nuevo;
	}
	else /* Modo COLA, inserta al final */
	{
		temporal = *stack;
		while (temporal->next)
			temporal = temporal->next;
		nuevo->prev = temporal;
		nuevo->next = NULL;
		temporal->next = nuevo;
	}
}

/**
 * monty_imprimeTodo - Imprime los valores de una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_imprimeTodo(stack_t **stack, unsigned int linea_numero)
{
	stack_t *temporal = (*stack)->next;

	while (temporal)
	{
		printf("%d\n", temporal->n);
		temporal = temporal->next;
	}
	(void)linea_numero;
}

/**
 * monty_imprimeSup - Imprime el valor superior de una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_imprimeSup(stack_t **stack, unsigned int linea_numero)
{
	if ((*stack)->next == NULL)
	{
		establecer_error_op_tok(error_pint(linea_numero));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_elimina - Elimina el elemento de valor superior de
 * una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_elimina(stack_t **stack, unsigned int linea_numero)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		establecer_error_op_tok(error_pop(linea_numero));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_intercambia - Intercambia los dos elementos de valor superior
 * de una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_intercambia(stack_t **stack, unsigned int linea_numero)
{
	stack_t *temporal;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		establecer_error_op_tok(error_pila_corta(linea_numero, "swap"));
		return;
	}

	temporal = (*stack)->next->next;
	(*stack)->next->next = temporal->next;
	(*stack)->next->prev = temporal;
	if (temporal->next)
		temporal->next->prev = (*stack)->next;
	temporal->next = (*stack)->next;
	temporal->prev = *stack;
	(*stack)->next = temporal;
}
