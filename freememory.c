#include "monty.h"
/**
 * freememory - This will free the memory from the
 * @head: Head of the node
 * Return: nothing
 */
void freememory(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
}
