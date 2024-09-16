#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - Checks if a linked list is a palindrome.
 * @head: Pointer to the head of the list.
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
listint_t *slow = *head, *fast = *head;
listint_t *prev = NULL, *second_half;

if (*head == NULL || (*head)->next == NULL)
return 1;

// Use fast and slow pointers to find the middle of the list
while (fast && fast->next)
{
listint_t *next_slow = slow->next; // Store next node of slow
slow->next = prev; // Reverse the first half
prev = slow; // Move prev one step forward
slow = next_slow; // Move slow one step forward
fast = fast->next->next;
}

// If the number of nodes is odd, skip the middle node
if (fast)
slow = slow->next;

second_half = slow; // The second half starts from here

// Compare the reversed first half with the second half
int result = compare_lists(prev, second_half);

// Restore the original list (optional)
reverse_list(prev);

return result;
}
