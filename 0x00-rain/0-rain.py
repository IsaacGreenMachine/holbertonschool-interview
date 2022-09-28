#!/usr/bin/python3
"""module for rain function"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    walls - list of non-negative integers.

    Return: Integer indicating total amount of rainwater retained.

    Assume that the ends of the list (before index 0 and after
    index walls[-1]) are not walls,
    meaning they will not retain water.

    If the list is empty return 0.
    """
    left, right, curr_max, flag, sum = -1, -1, -1, 0, 0
    size = len(walls)
    i = 0
    while i < size:
        if left == -1:
            if walls[i] >= curr_max:
                curr_max = walls[i]
            else:
                left = i-1
                curr_max = 0
        else:
            if walls[i] >= walls[left]:
                right = i
                for j, value in enumerate(walls[left+1:right]):
                    sum += walls[left] - value
                left, right, curr_max, flag = -1, -1, -1, 0
                i -= 1
            elif walls[i] >= curr_max:
                curr_max = walls[i]
                curr_max_idx = i
        if i == size - 1 and left != -1:
            for j, value in enumerate(walls[left+1:curr_max_idx]):
                if value < curr_max:
                    sum += curr_max - value
        i += 1
    return sum
