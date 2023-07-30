#include "monty.h"

data_t data = {NULL, NULL, NULL, NULL, 0};

/**
  * main - entry point
  * @argc: number of arguments
  * @argv: array of arguments
  *
  * Return: EXIT_SUCCESS
  */

int main(int argc, char *argv[])
{
	args_t args;

	size_t length = 0;
	int get_line = 0;
	void (*function)(stack_t **, unsigned int);

	args.av = argv[1];
	args.ac = argc;
	args.line_no = 0;
	if (args.ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.file_ptr = fopen(args.av, "r");
	if (data.file_ptr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", args.av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args.line_no++;
		get_line = getline(&(data.line), &length, data.file_ptr);
		if (get_line < 0)
			break;
		data.words = split_string(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_memory(0);
			continue;
		}
		function = use_func(data.words);
		if (function == NULL)
		{
			dprintf(STDERR_FILENO, UNKOWN, args.line_no, data.words[0]);
			free_memory(1);
			exit(EXIT_FAILURE);
		}
		function(&(data.stack), args.line_no);
		free_memory(0);
	}
	free_memory(1);
	return (EXIT_SUCCESS);
}
