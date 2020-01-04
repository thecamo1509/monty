#include "monty.h"
/**
 * read_file - Will read the monty file
 * @file: file to be read 
 * @stack: Pointer to the top of the stack representation
 * Return: Failures or Success
 */
int read_file(char *file, stack_t **stack){
	size_t len;
	ssize_t reading;
	unsigned int counter = 0;
	char *line = NULL;
	FILE *fd;
	char *operation;

	fd = fopen(file, "r");

	while((reading = getline(&line, &len, fd)) != -1){
		operation = strtok(line, "\n \t\r");
		counter++;
		if(operation != NULL)
			activate_op(stack, operation, counter);
	}
	fclose(fd);
	return(0);
}