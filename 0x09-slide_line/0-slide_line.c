#include "slide_line.h"

/**
 * swap - Swaps two integers
 *
 * @line: Pointer to the array of integer to be swapped
 * @i: first integer to be swapped
 * @x: second integer to be swapped
 *
 */

void swap(int *line, size_t i, size_t x)
{
	int tmp = line[i];
	line[i] = line[x];
	line[x] = tmp;
}


/**
 * moveNonZeros - Moves non-zeros to one side, depending on the direction
 *
 * @line: Pointer to the array of integer to be moved
 * @size: Number of elements in line
 * @direction: Direction to move
 *
 */

void moveNonZeros(int *line, size_t size, int direction)
{
	size_t i, x;

	/* move non zero to the left */
	for (i = 0; i < size && direction == SLIDE_LEFT; i++)
	{
		for (x = 0; x < size - i - 1; x++)
		{
			if (line[x] == 0)
			{
				swap(line, x, x + 1);
			}
		}
	}

	/* move non zero to the right */
	for (i = size - 1; i > 0 && direction == SLIDE_RIGHT; i--)
	{
		for (x = size - 1; x > 0; x--)
		{
			if (line[x] == 0)
			{
				swap(line, x, x - 1);
			}
		}
	}
}

/**
 * mergeLine - Merges duplicate nums in a line
 *
 * @line: Pointer to the array of integer to be merged
 * @size: Number of elements in line
 * @direction: Direction to move
 *
 */

void mergeLine(int *line, size_t size, int direction)
{
	size_t i;

	/* merge left */
	for (i = 0; i < size - 1 && direction == SLIDE_LEFT; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] += line[i + 1];
			line[i + 1] = 0;
		}
	}

	/* merge right */
	for (i = size - 1; i > 0 && direction == SLIDE_RIGHT; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] += line[i - 1];
			line[i - 1] = 0;
		}
	}

	/* move non-zeros */
	moveNonZeros(line, size, direction);
}

/**
 * slide_line - Slides a line of integers to the left or right
 *
 * @line: Pointer to the array of integer to be moved
 * @size: Number of elements in line
 * @direction: Direction to move
 *
 * Return: 1 if successful, 0 if failed
 */

int slide_line(int *line, size_t size, int direction)
{
	if (!line || size < 1 || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
	{
		return (0);
	}

	moveNonZeros(line, size, direction);
	mergeLine(line, size, direction);
	return (1);
}
