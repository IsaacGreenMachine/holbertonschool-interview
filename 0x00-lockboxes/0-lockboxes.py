#!/usr/bin/python3
"""module for canUnlockAll function"""


def canUnlockAll(boxes):
    """
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked

    Write a method that determines if all the boxes can be opened.

    boxes - a list of lists

    Return True if all boxes can be opened, else return False
    """

    '''
    if type(boxes) is not list or len(boxes) == 0:
        return False
    if type(boxes[0]) is not list or len(boxes[0]) == 0:
        return False

    keys = [0]
    opened_boxes = 0
    while opened_boxes < len(boxes):
        if boxes[keys[0]] != [-1]:
            keys += boxes[keys[0]]
            boxes[keys[0]] = [-1]
            opened_boxes += 1
        keys.remove(keys[0])
        if all(box == [-1] for box in boxes):
            return True
        if keys == []:
            return False
    return True
    '''
    if type(boxes) is not list or len(boxes) == 0:
        return False

    keys = boxes[0]
    checked = [0]

    if type(keys) is not list or len(keys) == 0:
        return False

    while True:

        checked, keys = check_boxes(checked, keys, boxes)

        if len(keys) == 0:
            return len(checked) == len(boxes)


def check_boxes(checked, keys, boxes):
    """
        Checks each unchecked box corresponding to each key
            in keys.
        Args:
            checked: list of indecies of checked boxes
            keys: newest set of found keys
            boxes: list of boxes to be searched
        Return:
        checked: appended checked box indecies
        new_keys: newly found keys
    """

    new_keys = []

    for key in keys:
        if key not in checked and key < len(boxes):
            new_keys = list(set(new_keys + boxes[key]))
            checked.append(key)

    return checked, new_keys
