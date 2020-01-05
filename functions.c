#include "monty.h"
/**
 * f_push - Function to add element to stack
 * @stack: Pointer to the head
 * @line_number: value to be inserted
 * Return: nothing
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	char *operation = NULL;
	int n = 0, i = 0;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	operation = strtok(NULL, "\n \t\r");
	if (!operation || (isdigit(*operation) == 0 && *operation != '-'))
	{
		free(global.ops);
		free(newnode);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 1; operation[i] != '\0'; i++)
	{
		if (isdigit(operation[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(operation);
	newnode->n = n;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (newnode->next != NULL)
	{
		newnode->next->prev = newnode;
	}
	*stack = newnode;
}

/**
 * f_pall - Function to print the stack
 * @stack: Pointer to the head
 * @line_number: value in the node
 * Return: Nothing
 */

void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	UNUSED(line_number);
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * f_pint - prints value at top of stack
 * @stack: pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */

void f_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
