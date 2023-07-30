#include "monty.h"

/**
  * split_string - splits a string into words
  * @str: string
  *
  * Return: pointer to an array of strings
  */

char **split_string(char *str)
{
	char **matrix, *token, *copy;
	int i, words = 0, j;

	if (str == NULL || *str == '\0')
		return (NULL);

	copy = strdup(str);
	if (copy == NULL)
		return (NULL);

	token = strtok(copy, " \t\n");

	while (token != NULL)
	{
		words++;
		token = strtok(NULL, " \t\n");
	}

	if (words == 0)
	{
		free(copy);
		return (NULL);
	}

	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
	{
		free(copy);
		return (NULL);
	}

	token = strtok(str, " \t\n");
	for (i = 0; i < words; i++)
	{
		matrix[i] = strdup(token);
		if (matrix[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(matrix[j]);
			free(matrix);
			free(copy);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
	}
	matrix[words] = NULL;
	free(copy);
	return (matrix);
}
