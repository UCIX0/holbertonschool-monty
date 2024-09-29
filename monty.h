#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define PILA 0
#define COLA 1
#define DELIMITADORES " \n\t\a\b"

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int error_uso(void);
int error_malloc(void);
int error_abrir_archivo(char *nombre_archivo);
int error_op_desconocido(char *codigo_op, unsigned int line_number);
int error_sin_entero(unsigned int line_number);
int error_pop(unsigned int line_number);
int error_pint(unsigned int line_number);
int error_pila_corta(unsigned int line_number, char *operacion);
int error_div(unsigned int line_number);
int error_pchar(unsigned int line_number, char *mensaje);
char *obtener_entero(int num);
unsigned int _abs(int i);
int obtener_longitud_base_num(unsigned int num, unsigned int base);
void llenar_buff_base_num(unsigned int num, unsigned int base,
			char *buff, int tamano_buff);
char **cadAVector(char *str, char *delims);
int es_delim(char ch, char *delims);
int obtener_longitud_palabra(char *str, char *delims);
int obtener_cantidad_palabras(char *str, char *delims);
char *obtener_siguiente_palabra(char *str, char *delims);

void monty_inserta(stack_t **stack, unsigned int linea_numero);
void monty_imprimeTodo(stack_t **stack, unsigned int linea_numero);
void monty_imprimeSup(stack_t **stack, unsigned int linea_numero);
void monty_elimina(stack_t **stack, unsigned int linea_numero);
void monty_intercambia(stack_t **stack, unsigned int linea_numero);

void monty_suma(stack_t **stack, unsigned int linea_numero);
void monty_resta(stack_t **stack, unsigned int linea_numero);
void monty_divide(stack_t **stack, unsigned int linea_numero);
void monty_multiplica(stack_t **stack, unsigned int linea_numero);
void monty_modulo(stack_t **stack, unsigned int linea_numero);


void monty_nop(stack_t **stack, unsigned int linea_numero);
void monty_pchar(stack_t **stack, unsigned int linea_numero);
void monty_pstr(stack_t **stack, unsigned int linea_numero);
void monty_rotl(stack_t **stack, unsigned int linea_numero);
void monty_rotr(stack_t **stack, unsigned int linea_numero);
void monty_stack(stack_t **stack, unsigned int linea_numero);
void monty_queue(stack_t **stack, unsigned int linea_numero);

void liberar_tokens(void);
unsigned int longitud_arr_token(void);
int es_linea_vacia(char *linea, char *delims);
void (*obtener_func_op(char *opcode))(stack_t**, unsigned int);
int ejecutar_monty(FILE *script_fd);
void establecer_error_op_tok(int codigo_error);
void liberar_pila(stack_t **pila);
int inicializar_pila(stack_t **pila);
int verificar_modo(stack_t *pila);

#endif /* MONTY_H */