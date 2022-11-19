#!/usr/bin/python3
"""module for makeChange function"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.

    Return: fewest number of coins needed to meet total
            If total is 0 or less, return 0
            If total cannot be met , return -1
    total - int, number to be made by coins
    coins - list of the values of the coins in your possession
            The value of a coin will always be an integer greater than 0
    you have an infinite number of each denomination of coin in the list
    This is a (2n)log(n) solution.
    """
    # bad solution:
    '''
    if total <= 0:
        return 0
    count = 0
    # nlog(n)
    coins.sort(reverse=True)
    # n
    for coin in coins:
        count += total // coin
        total %= coin
    return -1 if total else count
    '''
    dynamic = [total + 1] * (total + 1)
    dynamic[0] = 0
    for i, val in enumerate(dynamic):
        smallest = val
        for coin in coins:
            if coin <= i:
                smallest = min([dynamic[i - coin] + 1, smallest])
        if smallest != total + 1:
            dynamic[i] = smallest
    return -1 if dynamic[-1] == total + 1 else dynamic[-1]
