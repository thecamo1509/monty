#include "monty.h"
/**
 * main - Main function
 * @argc: Argument counter
 * @argv: Array of arguments
 * Return: 0 for success
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	global.top = &head;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &head);
	return (0);
}
