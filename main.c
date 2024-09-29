#include "monty.h"
int main(int argc, char **argv);
char **op_toks = NULL;

/**
 * main - el punto de entrada para Monty Interp
 *
 * @argc: el conteo de argumentos pasados al programa
 * @argv: puntero a una matriz de punteros a caracteres a argumentos
 *
 * Return: (EXIT_SUCCESS) en éxito (EXIT_FAILURE) en error
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
