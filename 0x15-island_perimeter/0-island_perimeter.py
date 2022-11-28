#!/usr/bin/python3
""" module for island_perimeter function """


def island_perimeter(grid):
    '''
    returns the perimeter of the island described in grid:
        grid is a list of list of integers:
            0 represents water
            1 represents land
        Each cell is square, with a side length of 1
        Cells are connected horizontally/vertically (not diagonally).
        grid is rectangular, with its width and height not exceeding 100
        The grid is completely surrounded by water
        There is only one island (or nothing).
        The island doesnt have “lakes”
        (water inside that isnt connected to the water surrounding the island).
    '''
    perimeter = 0
    for row in range(len(grid)):
        for column in range(len(grid[row])):
            if grid[row][column] == 1:
                # only checking top and left sides of island since all islands
                # have equal number of top and bottom, left and right sides
                sides = []
                if row == 0:
                    sides.append(0)
                else:
                    sides.append(grid[row - 1][column])
                if column == 0:
                    sides.append(0)
                else:
                    sides.append(grid[row][column - 1])
                perimeter += sides.count(0)
    return perimeter * 2
