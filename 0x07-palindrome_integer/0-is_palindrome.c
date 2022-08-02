#include "palindrome.h"

/**
 * is_palindrome - checks if long int is a palindrome
 * @n: unsigned long to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
unsigned long remainder, original = n, reverse = 0;
while (original != 0)
{
remainder = original % 10;
reverse = reverse * 10 + remainder;
original /= 10;
}

while (n > 0)
{
printf("checking %lu and %lu\n", n / 10, reverse / 10);
if (n / 10 != reverse / 10)
return (0);
n /= 10;
reverse /= 10;
printf
}
return (1);
}
