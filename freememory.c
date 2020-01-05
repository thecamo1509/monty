#include "monty.h"
/**
 * freememory - This will free the memory from the
 * @head: Head of the node
 * Return: nothing
 */
void freememory(stack_t *head)
{
	stack_t *temp = head;

	while (temp)
	{
		free(head);
		head = temp->next;
		temp = temp->next;
	}
	free(head);
}
