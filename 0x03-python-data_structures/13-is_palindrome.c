#include "lists.h"


/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the singly linked list.
 *
 * This function checks if the given linked list is a palindrome. It
 * uses the fast and slow pointer technique to find the middle of the list,
 * then reverses the second half of the list. The function compares both
 * halves of the list element by element. If all elements match, it
 * returns 1 (true), indicating that the list is a palindrome. Otherwise,
 * it returns 0 (false).
 *
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */





int is_palindrome(listint_t **head)
{
listint_t *slow = *head, *fast = *head, *prev = NULL, *second_half;
listint_t *midnode = NULL;
if (*head == NULL || (*head)->next == NULL)
return (1);

while (fast && fast->next)
{
fast = fast->next->next;
prev = slow;
slow = slow->next;
}

if (fast != NULL)
{
midnode = slow;
slow = slow->next;
}

second_half = slow;
prev->next = NULL;

second_half = reverse_list(second_half);

int result = compare_lists(*head, second_half);

second_half = reverse_list(second_half);

if (midnode)
prev->next = midnode;
midnode->next = second_half;

return (result);
}

