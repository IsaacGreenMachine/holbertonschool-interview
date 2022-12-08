#!/usr/bin/python3
'''
Maria and Ben are playing a game.
Given a set of consecutive integers starting from 1 up to and including n,
they take turns choosing a prime number from the set and removing
that number and its multiples from the set.
The player that cannot make a move loses the game.

They play x rounds of the game, where n may be different for each round.
Assuming Maria always goes first and both players play optimally,
determine who the winner of each game is.

Example:
    x = 3, nums = [4, 5, 1]
    First round: 4

    Maria picks 2 and removes 2, 4, leaving 1, 3
    Ben picks 3 and removes 3, leaving 1
    Ben wins because there are no prime numbers left for Maria to choose
    Second round: 5

    Maria picks 2 and removes 2, 4, leaving 1, 3, 5
    Ben picks 3 and removes 3, leaving 1, 5
    Maria picks 5 and removes 5, leaving 1
    Maria wins because there are no prime numbers left for Ben to choose
    Third round: 1

    Ben wins because there are no prime numbers for Maria to choose
    Result: Ben has the most wins
'''


def primes1(n):
    """ Returns  a list of primes < n """
    sieve = [True] * (n//2)
    for i in range(3, int(n**0.5)+1, 2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1, n//2) if sieve[i]]


def isWinner(x, nums):
    '''
    x - the number of rounds
    nums - array of n
    n - consecutive int max of the game like [1 -> n]
    Return: name of the player that won the most rounds
    If the winner cannot be determined, return None
    n, x <= 10,000
    '''
    if x <= 0 or x > 10000 or type(nums) != list or len(nums) == 0:
        return None
    maria, ben = 0, 0
    for n in nums:
        if n == 1:
            ben += 1
        else:
            if n < 0 or n > 10000:
                return None
            primes = len(primes1(n+1))
            if x*2 <= primes:
                pass
            elif primes % 2 == 0:
                ben += 1
            else:
                maria += 1
    if ben > maria:
        return ('Ben')
    elif maria > ben:
        return ('Maria')
    else:
        return (None)
