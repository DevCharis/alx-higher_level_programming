
#include <stdlib.h>
#include "lists.h"
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new_node = malloc(sizeof(listint_t));
listint_t *current = *head;

if (new_node == NULL)
return (NULL);
new_node->n = number;

if (current == NULL || current->n >= number)
{
new_node->next = current;
*head = new_node;
return (new_node);
}

while (current && current->next && current->next->n < number)
current = current->next;

new_node->next = current->next;
current->next = new_node;
return (new_node);
}
