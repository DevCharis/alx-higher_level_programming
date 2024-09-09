#include "lists.h"
/**
 * check_cycle - Checks if a singly linked list contains a cycle.
 * @list: Pointer to the head of the singly linked list.
 *
 * Description:
 * This function uses Floyd's Tortoise and Hare algorithm to detect
 * if a cycle exists in a singly linked list. The algorithm uses two pointers
 * that traverse the list at different speeds. If the fast pointer (hare) and
 * the slow pointer (tortoise) meet, it indicates the presence of a cycle.
 * If the fast pointer reaches the end of the list, there is no cycle.
 *
 * Return: 1 if there is a cycle, 0 if there is no cycle.
 */

int check_cycle(listint_t *list)
{
listint_t *slow = list, *fast = list;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
return (1);
}
return (0);
}

