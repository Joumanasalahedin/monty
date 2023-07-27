#include "monty.h"

/**
  * free_dlistint - frees a dlistint_t list
  * @head: pointer to head of list
  */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	dlistint_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/**
  * get_dnodeint_at_index - returns the nth node of a linked list
  * @head: pointer to head of the list
  * @index: chosen node
  * Return: nth node
  */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}

/**
  * insert_dnodeint_at_index - inserts a new node at a given position
  * @h: double pointer to head of the list
  * @idx: index of the list where new node should be added
  * @n: node to be added
  * Return: adress of the new node
  */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current = *h;
	dlistint_t *previous = NULL;
	unsigned int count = 0;

	if (h == NULL)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *h;
		new_node->prev = NULL;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	while (current != NULL && count < idx)
	{
		previous = current;
		current = current->next;
		count++;
	}
	if (count == idx)
	{
		if (current != NULL)
			current->prev = new_node;
		new_node->prev = previous;
		new_node->next = current;
		if (previous != NULL)
			previous->next = new_node;
		return (new_node);
	}
	free(new_node);
	return (NULL);
}

/**
  * delete_dnodeint_at_index - deletes the node at index of a linked list
  * @head: double pointer to head of the list
  * @index: index to delete the node
  * Return: 1 (Success)
  */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current != NULL)
	{
		if (count == index)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			if (current->prev != NULL)
				current->prev->next = current->next;
			free(current);
			return (1);
		}
		current = current->next;
		count++;
	}
	return (-1);
}
