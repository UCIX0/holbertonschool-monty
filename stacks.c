#include "monty.h"
/**
 * liberar_pila - Libera una pila stack_t.
 * @pila: Un puntero al tope (pila) o
 * abajo (cola) de un stack_t.
 */
void liberar_pila(stack_t **pila)
{
	stack_t *temporal = *pila;

	while (*pila)
	{
		temporal = (*pila)->next;
		free(*pila);
		*pila = temporal;
	}
}

/**
 * inicializar_pila - Inicializa una pila stack_t con nodos iniciales
 * de pila y nodos finales de cola.
 * @pila: Un puntero a una pila stack_t no inicializada.
 *
 * Return: Si ocurre un error - EXIT_FAILURE.
 * De lo contrario - EXIT_SUCCESS.
 */
int inicializar_pila(stack_t **pila)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (error_malloc());

	s->n = PILA;
	s->prev = NULL;
	s->next = NULL;

	*pila = s;

	return (EXIT_SUCCESS);
}

/**
 * verificar_modo - Verifica si una
 * lista enlazada stack_t está en modo pila o cola.
 * @pila: Un puntero al tope (pila) o abajo (cola)
 * de una lista enlazada stack_t.
 *
 * Return: Si el stack_t está en modo pila - PILA (0).
 * Si el stack_t está en modo cola - COLA (1).
 * De lo contrario - 2.
 */
int verificar_modo(stack_t *pila)
{
	if (pila->n == PILA)
		return (PILA);
	else if (pila->n == COLA)
		return (COLA);
	return (2);
}
