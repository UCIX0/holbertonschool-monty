#include "monty.h"
/**
 * monty_nop - No hace absolutamente nada para el opcode Monty 'nop'.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_nop(stack_t **stack, unsigned int linea_numero)
{
	(void)stack;
	(void)linea_numero;
}

/**
 * monty_pchar - Imprime el carácter en el nodo de valor superior
 *               de una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_pchar(stack_t **stack, unsigned int linea_numero)
{
	if ((*stack)->next == NULL)
	{
		establecer_error_op_tok(error_pchar(linea_numero, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		establecer_error_op_tok(error_pchar(linea_numero,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Imprime la cadena contenida en una lista vinculada stack_t.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 */
void monty_pstr(stack_t **stack, unsigned int linea_numero)
{
	stack_t *tempo = (*stack)->next;

	while (tempo && tempo->n != 0 && (tempo->n > 0 && tempo->n <= 127))
	{
		printf("%c", tempo->n);
		tempo = tempo->next;
	}

	printf("\n");

	(void)linea_numero;
}
