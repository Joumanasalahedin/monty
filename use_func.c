#include "monty.h"

/**
  * use_func - selects functions to use
  * @bytecode_tok: array of strings from bytecode
  *
  * Return: pointer to function
  */

void (*use_func(char **bytecode_tok))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", handle_push},
		{"pall", handle_pall},
	};

	int codes = 1, i;

	for (i = 0; i < codes; i++)
	{
		if (strcmp(func_arr[i].opcode, bytecode_tok[0]) == 0)
			return (func_arr[i].f);
	}

	return (NULL);
}
