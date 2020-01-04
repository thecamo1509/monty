#include "monty.h"
/**
 * f_push - Function to add element to stack
 * @stack: Pointer to the head
 * @line_number: value to be inserted
 * Return: nothing
 */
void f_push(stack_t **stack, unsigned int line_number){
	stack_t *newnode;
	char *operation;
	int n;

	newnode = malloc(sizeof(stack_t));
	if(!newnode){
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	operation = strtok(NULL, "\n \t\r");
	if(!operation || !stack){
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = line_number;
	newnode->n = n;
	newnode->next = *stack;
	newnode->prev = NULL;
	if(newnode->next != NULL){
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

void f_pall(stack_t **stack, unsigned int line_number){
	stack_t *node = *stack;

	UNUSED(line_number);
	while(node){
		printf("%d\n", node->n);
		node = node->next;
	}
}