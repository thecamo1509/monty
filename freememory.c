#include "monty.h"
/**
 * freememory - This will free the memory from the
 * stack
 * Return: nothing
 */
void freememory(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(global.top);
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
