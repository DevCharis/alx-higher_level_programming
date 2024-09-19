#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
int is_palindrome(listint_t **head)
{
listint_t *slow = *head, *fast = *head;
listint_t *prev = NULL, *second_half;
if (*head == NULL || (*head)->next == NULL)
return 1;
while (fast && fast->next)
{
listint_t *next_slow = slow->next;
slow->next = prev;
prev = slow;
slow = next_slow;
fast = fast->next->next;
}
if (fast)
slow = slow->next;
second_half = slow;
int result = compare_lists(prev, second_half);
reverse_list(prev);
return result;
}
