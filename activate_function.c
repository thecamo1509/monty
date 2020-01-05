#include "monty.h"
/**
 * activate_op - This will execute the function
 * according to the opcode given
 * @stack: Pointer to the head of the stack
 * @operation: Opcode to be executed
 * @line_number: Line number counter
 * Return: nothing
 */
void activate_op(stack_t **stack, char *operation, unsigned int line_number)
{
	int i = 0;

	instruction_t operations[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{NULL, NULL}
	};
	if (operation == NULL)
	{
		return;
	}
	for (i = 0; operations[i].opcode; i++)
	{
		if (strcmp(operation, operations[i].opcode) == 0)
		{
			global.ops = operation;
			operations[i].f(stack, line_number);
			return;
		}
	}
	if (strlen(operation) != 0 && operation[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, operation);
		exit(EXIT_FAILURE);
	}
}
