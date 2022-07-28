#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
  * Return: 1 if yes, 0 if no
 */
int is_palindrome(listint_t **head)
{
listint_t *newList;
listint_t *mover;
mover = *head;
newList = NULL;
newList = add_nodeint_start(&newList, mover->n);
mover = mover->next;

while (mover->next != NULL)
{
/* potential palindrome middle has been found */

if (mover->n == newList->n)
{
if (checkPalindrome(mover, newList))
return (1);
}
else if (mover->next->n == newList->n)
{
if (checkPalindrome(mover->next, newList))
return (1);
}

newList = add_nodeint_start(&newList, mover->n);
mover = mover->next;
}

return (0);

}

/**
 * add_nodeint_start - adds a new node at the start of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_start(listint_t **head, const int n)
{
listint_t *new;
new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = n;
if (*head == NULL)
new->next = NULL;
else
{
new->next = *head;
*head = new;
}
*head = new;
return (new);
}


/**
 * checkPalindrome - adds a new node at the start of a listint_t list
 * @a: left center of palindrome
 * @b: right center of palindrome
 * Return: address of the new element or NULL if it fails
 */
int checkPalindrome(listint_t *a, listint_t *b)
{
listint_t *a_cop = a;
listint_t *b_cop = b;
while (a_cop != NULL)
{
if (a_cop->n == b_cop->n)
{
a_cop = a_cop->next;
b_cop = b_cop->next;
}
else
return (0);
}
if (b_cop == NULL && a_cop == NULL)
return (1);
else
return (0);
}
