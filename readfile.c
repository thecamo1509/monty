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
	ssize_t reading = 0;
	unsigned int counter = 0;
	char *line = NULL;
	char *operation = NULL;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	global.fd = fopen(file, "r");

	if (!global.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		fclose(global.fd);
		exit(EXIT_FAILURE);
	}
	while ((reading = getline(&line, &len, global.fd)) != -1)
	{
		operation = strtok(line, "\n \t");
		counter++;
		if (operation != NULL)
			activate_op(stack, operation, counter);
	}
	fclose(global.fd);
	free(line);
	return (0);
}
