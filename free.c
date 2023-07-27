#include "monty.h"

/**
  * free_memory - memory handling function
  * @all: flag to indicate what to free
  */

void free_memory(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_array(data.words);
		data.words = NULL;
	}

	if (all)
	{
		if (data.stack)
		{
			free_dlistint(data.stack);
			data.stack = NULL;
		}

		if (data.file_ptr)
		{
			fclose(data.file_ptr);
			data.file_ptr = NULL;
		}
	}
}

/**
  * free_array - frees arrays of strings
  * @args: array of strings
  */

void free_everything(char **args)
{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}
