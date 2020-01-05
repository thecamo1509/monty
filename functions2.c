#include "monty.h"
/**
 * f_add - addition of the two top elements
 * @stack: pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void f_add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	f_pop(stack, line_number);
	(*stack)->n = (*stack)->n + tmp;
}

/**
 * f_nop - doesn't do anything
 * @stack: pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void f_nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
