#include "monty.h"
/*----------------------------------------ERROR1*/
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
 * error_abrir_archivo - Imprime mensajes de error al abrir archivo con el nombre del archivo.
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
 * error_op_desconocido - Imprime mensajes de error de instrucción desconocida.
 * @codigo_op: Código de operación donde ocurrió el error.
 * @line_number: Número de línea en el archivo de bytes de Monty donde ocurrió el error.
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
 * error_sin_entero - Imprime mensajes de error de argumento inválido monty_inserta.
 * @line_number: Número de línea en el archivo de bytes de Monty donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_sin_entero(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/*----------------------------------------ERROR2*/

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
 * @line_number: Número de línea en el archivo de bytecodes de Monty donde ocurrió el error.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_pila_corta - Imprime mensajes de error de funciones matemáticas de monty
 *                    para pilas/colas menores a dos nodos.
 * @line_number: Número de línea en el archivo de bytecodes de Monty donde ocurrió el error.
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
 * error_div - Imprime mensajes de error de división para divisiones por 0.
 * @line_number: Número de línea en el archivo de bytecodes de Monty donde ocurrió el error.
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
 *               y valores no característicos.
 * @line_number: Número de línea en el archivo de bytecodes de Monty donde ocurrió el error.
 * @mensaje: El mensaje de error correspondiente a imprimir.
 *
 * Return: (EXIT_FAILURE) siempre.
 */
int error_pchar(unsigned int line_number, char *mensaje)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, mensaje);
	return (EXIT_FAILURE);
}

/*----------------------------------------intacadena*/

/**
 * obtener_entero - obtiene un puntero a una nueva cadena que contiene un entero
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
 * obtener_longitud_base_num - obtiene la longitud del buffer necesaria para un entero sin signo
 * @num: número para obtener la longitud necesaria
 * @base: base de la representación numérica utilizada por el buffer
 *
 * Return: entero que contiene la longitud del buffer necesaria (no contiene bt nulo)
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
 * llenar_buff_base_num - llena el buffer con los números correctos hasta la base 36
 * @num: número a convertir a cadena dada la base
 * @base: base del número utilizado en la conversión, solo funciona hasta la base 36
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
/*----------------------------------------hacerToken*/

/**
 * cadAVector - toma una cadena y separa sus palabras
 *
 * @str: cadena para separar en palabras
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: matriz 2D de punteros a cada palabra
 */

char **cadAVector(char *str, char *delims)
{
	char **palabras = NULL;
	int wc, longitudPalabra, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = obtener_cantidad_palabras(str, delims);


	if (wc == 0)
		return (NULL);
	palabras = malloc((wc + 1) * sizeof(char *));
	if (palabras == NULL)
		return (NULL);
	while (i < wc)
	{
		longitudPalabra = obtener_longitud_palabra(str, delims);
		if (es_delim(*str, delims))
		{
			str = obtener_siguiente_palabra(str, delims);
		}
		palabras[i] = malloc((longitudPalabra + 1) * sizeof(char));
		if (palabras[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(palabras[i]);
			}
			free(palabras);
			return (NULL);
		}
		n = 0;
		while (n < longitudPalabra)
		{
			palabras[i][n] = *(str + n);
			n++;
		}
		palabras[i][n] = '\0'; /* establecer el final de str */
		str = obtener_siguiente_palabra(str, delims);
		i++;
	}
	palabras[i] = NULL; /* el último elemento es nulo para la iteración */
	return (palabras);
}

/**
 * es_delim - verifica si la corriente tiene un carácter delimitador
 *
 * @ch: caracter en la corriente
 *
 * @delims: Puntero a matriz terminada en nulo de delimitadores
 *
 * Return: 1 (éxito) 0 (falla)
 */

int es_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * obtener_longitud_palabra - obtiene la longitud de la palabra actual en str
 *
 * @str: cadena para obtener la longitud de la palabra actual
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: longitud de la palabra actual
 */

int obtener_longitud_palabra(char *str, char *delims)
{
	int longitudPalabra = 0, pendiente = 1, i = 0;

	while (*(str + i))
	{
		if (es_delim(str[i], delims))
			pendiente = 1;
		else if (pendiente)
		{
			longitudPalabra++;
		}
		if (longitudPalabra > 0 && es_delim(str[i], delims))
			break;
		i++;
	}
	return (longitudPalabra);
}

/**
 * obtener_cantidad_palabras - obtiene la cantidad de palabras de una cadena
 *
 * @str: cadena para obtener la cantidad de palabras
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: la cantidad de palabras de la cadena
 */

int obtener_cantidad_palabras(char *str, char *delims)
{
	int wc = 0, pendiente = 1, i = 0;

	while (*(str + i))
	{
		if (es_delim(str[i], delims))
			pendiente = 1;
		else if (pendiente)
		{
			pendiente = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * obtener_siguiente_palabra - obtiene la siguiente palabra en una cadena
 *
 * @str: cadena para obtener la siguiente palabra
 * @delims: delimitadores para usar para delimitar palabras
 *
 * Return: puntero al primer carácter de la siguiente palabra
 */

char *obtener_siguiente_palabra(char *str, char *delims)
{
	int pendiente = 0;
	int i = 0;

	while (*(str + i))
	{
		if (es_delim(str[i], delims))
			pendiente = 1;
		else if (pendiente)
			break;
		i++;
	}
	return (str + i);
}

/*----------------------------------------montyf1*/

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
 * monty_elimina - Elimina el elemento de valor superior de una lista vinculada stack_t.
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
 * monty_intercambia - Intercambia los dos elementos de valor superior de una lista vinculada stack_t.
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

/*----------------------------------------montyf2*/

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
 *             parte superior de una lista vinculada stack_t por el valor superior.
 * @stack: Un puntero al nodo modo superior de una lista vinculada stack_t.
 * @linea_numero: El número de línea actual del archivo de bytecodes Monty.
 *
 * Descripción: El resultado se almacena en el segundo nodo de valor
 *              desde la parte superior y se elimina el valor superior.
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

/*-----------------------------------------montyf3*/

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
	stack_t *temporal = (*stack)->next;

	while (temporal && temporal->n != 0 && (temporal->n > 0 && temporal->n <= 127))
	{
		printf("%c", temporal->n);
		temporal = temporal->next;
	}

	printf("\n");

	(void)linea_numero;
}
/*----------------------------------------montyf4*/

/**
 * monty_rotl - Rota el valor superior de una lista vinculada stack_t hacia abajo.
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
 * monty_rotr - Rota el valor inferior de una lista vinculada stack_t hacia arriba.
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


/*----------------------------------------ejecutarmonty*/

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
 * Retorno: Longitud de op_toks actual (como int).
 */
unsigned int longitud_arr_token(void)
{
	unsigned int longitud_toks = 0;

	while (op_toks[longitud_toks])
		longitud_toks++;
	return (longitud_toks);
}

/**
 * es_linea_vacia - Comprueba si una línea leída desde getline sólo contiene delimitadores.
 * @linea: Un puntero a la línea.
 * @delims: Una cadena de caracteres delimitadores.
 *
 * Retorno: Si la línea sólo contiene delimitadores - 1.
 *          De lo contrario - 0.
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
 * Retorno: Un puntero a la función correspondiente.
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
 * ejecutar_monty - Función principal para ejecutar un script de bytecodes Monty.
 * @script_fd: Descriptor de fichero para un script abierto de bytecodes Monty.
 *
 * Retorno: EXIT_SUCCESS en éxito, código de error correspondiente en fallo.
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
/*----------------------------------------establecerop*/

/**
 * establecer_error_op_tok - Establece el último elemento de op_toks como un código de error.
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

/*----------------------------------------pilas*/

/**
 * liberar_pila - Libera una pila stack_t.
 * @pila: Un puntero al tope (pila) o
 *         abajo (cola) de un stack_t.
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
 *              de pila y nodos finales de cola.
 * @pila: Un puntero a una pila stack_t no inicializada.
 *
 * Retorno: Si ocurre un error - EXIT_FAILURE.
 *         De lo contrario - EXIT_SUCCESS.
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
 * verificar_modo - Verifica si una lista enlazada stack_t está en modo pila o cola.
 * @pila: Un puntero al tope (pila) o abajo (cola)
 *         de una lista enlazada stack_t.
 *
 * Retorno: Si el stack_t está en modo pila - PILA (0).
 *         Si el stack_t está en modo cola - COLA (1).
 *         De lo contrario - 2.
 */
int verificar_modo(stack_t *pila)
{
	if (pila->n == PILA)
		return (PILA);
	else if (pila->n == COLA)
		return (COLA);
	return (2);
}



char **op_toks = NULL;

/**
 * main - el punto de entrada para Monty Interp
 *
 * @argc: el conteo de argumentos pasados al programa
 * @argv: puntero a una matriz de punteros a caracteres a argumentos
 *
 * Retorno: (EXIT_SUCCESS) en éxito (EXIT_FAILURE) en error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int codigo_salida = EXIT_SUCCESS;

	if (argc != 2)
		return (error_uso());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (error_abrir_archivo(argv[1]));
	codigo_salida = ejecutar_monty(script_fd);
	fclose(script_fd);
	return (codigo_salida);
}