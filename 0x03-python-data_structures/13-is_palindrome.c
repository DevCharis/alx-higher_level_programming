#include "lists.h"
#include <stddef.h>
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

int is_palindrome(listint_t **head) {
    listint_t *slow = *head, *fast = *head, *prev = NULL;
    listint_t *second_half, *midnode = NULL;
    int result = 1;  // Assume it's a palindrome unless proven otherwise

    // Check if the list is empty or has only one element
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return 1; // Empty or single-node list is a palindrome
    }

    // Use fast and slow pointer technique to find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // If fast is not NULL, list is odd length, so skip the middle node
    if (fast != NULL) {
        midnode = slow;
        slow = slow->next;
    }

    // Reverse the second half of the list
    second_half = reverse_list(slow);
    prev->next = NULL;  // Terminate the first half

    // Compare both halves
    result = compare_lists(*head, second_half);

    // Restore the original list (reverse the second half back)
    second_half = reverse_list(second_half);

    // Reattach the middle node if it existed
    if (midnode != NULL) {
        prev->next = midnode;
        midnode->next = second_half;
    } else {
        prev->next = second_half;
    }

    return result; // Return whether the list is a palindrome
}
