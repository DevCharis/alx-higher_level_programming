#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current;
    unsigned int n; /* number of nodes */

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\n", current->n);
        current = current->next;
        n++;
    }

    return (n);
}

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

    return (new);
}
// Function to reverse a linked list
listint_t *reverse_list(listint_t *head) {
    listint_t *prev = NULL, *next = NULL;

    while (head != NULL) {
        next = head->next; // Store next node
        head->next = prev; // Reverse the link
        prev = head;       // Move prev up
        head = next;       // Move head up
    }
    return prev; // New head of the reversed list
}

// Function to compare two linked lists
int compare_lists(listint_t *list1, listint_t *list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->n != list2->n) {
            return 0; // Not a palindrome
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == NULL && list2 == NULL) ? 1 : 0; // Both lists should be the same length
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}

