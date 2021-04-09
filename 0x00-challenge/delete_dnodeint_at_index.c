#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *temp_head = *head;


	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		if (temp_head->next != NULL)
			temp_head->next->prev = NULL;
		*head = temp_head->next;
		free(temp_head);
		return (1);
	}

	while (temp_head != NULL)
	{
		if (temp_head->next == NULL)
			break;
		if (i == index)
		{
			temp_head->prev->next = temp_head->next;
			temp_head->next->prev = temp_head->prev;
			free(temp_head);
			return (1);
		}
		i++;
		temp_head = temp_head->next;
	}
	if (index > i)
		return (-1);
	temp_head->prev->next = NULL;
	free(temp_head);
	return (1);
}
