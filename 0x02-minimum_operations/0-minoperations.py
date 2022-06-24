#!/usr/bin/python3
"""module for minOperations function"""


def smallestPrimeFactors(n):
    """
    O(log(n))
    finds the smasllest prime factor of n
    """
    min = n
    c = 2
    while(n > 1):
        if(n % c == 0):
            if c < min:
                min = c
            n = n / c
        else:
            c = c + 1
    return min


def minOperations(n):
    """
    O(log(n) * log(n)) = O(n)
    In a text file, there is a single character H.
    Your text editor can execute only two operations in this file:
    Copy All and Paste. Given a number n, write a method that
    calculates the fewest number of operations needed to result
    in exactly n H characters in the file.

    Returns an integer
    If n is impossible to achieve, return 0
    """
    if type(n) != int or n <= 1:
        return 0
    sum = 0
    # O(log(n))
    while n != 1:
        gcf = n // smallestPrimeFactors(n)
        sum += (n / gcf)
        n = gcf
    return int(sum)
