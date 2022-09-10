#include "menger.h"
/**
 * selectChar - selects character to print for menger sponge
 * @row: current row
 * @column: current column
 * Return: character to print
 */
char selectChar(int row, int column)
{
	for (; row || column; row /= 3, column /= 3)
	{
		if (row % 3 == 1 && column % 3 == 1)
			return (' ');
	}
	return ('#');
}

/**
 * menger - prints a menger sponge
 * @level: level of menger to print
 */
void menger(int level)
{
	int row, column, size;

	if (level < 0)
		return;
	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
			putchar(selectChar(row, column));
		putchar('\n');
	}
}
