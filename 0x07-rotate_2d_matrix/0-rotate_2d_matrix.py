#!/usr/bin/python3
""" module for rotate_2d_matrix """
def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise.
    matrix is edited in-place.
    """
    # zip(*X) transposes X so:
    # 1 2 3
    # 4 5 6
    # 7 8 9
    # becomes
    # 1 4 7
    # 2 5 8
    # 3 6 9
    # then [::-1] reverses each row prev. matrix becomes:
    # 7 4 1
    # 8 5 2
    # 9 6 3

    new_mat = [list(tup)[::-1] for tup in zip(*matrix)]
    for i, row in enumerate(new_mat):
        for j, col in enumerate(row):
            matrix[i][j] = col
