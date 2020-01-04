#include "monty.h"
/**
 * read_file - Will read the monty file
 * @file: file to be read
 * @stack: Pointer to the top of the stack representation
 * Return: Failures or Success
 */
int read_file(char *file, stack_t **stack)
{
	/** Here I will read the file*/
	size_t len = 0;
	ssize_t reading;
	unsigned int counter = 0;
	char *line = NULL;
	FILE *fd;
	char *operation;

	if(!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	fd = fopen(file, "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((reading = getline(&line, &len, fd)) != -1)
	{
		operation = strtok(line, "\n \t\r");
		counter++;
		if (operation != NULL)
			activate_op(stack, operation, counter);
	}
	free(line);
	fclose(fd);
	return (0);
}
