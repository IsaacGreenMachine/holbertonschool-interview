#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}

/**
 * stable - checks if a sandpile is stable
 * @grid: grid to check
 *
 * Return: 1 if stable 0 if not
 */
int stable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - topples an unstable sandpile
 * @grid: sandpile to topple
 *
 */
void topple(int grid[3][3])
{
	int x, y, tmpGrid[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
			{
				tmpGrid[x][y] += grid[x][y] - 4;
				if (x - 1 >= 0)
					tmpGrid[x - 1][y] += 1;
				if (x + 1 < 3)
					tmpGrid[x + 1][y] += 1;
				if (y - 1 >= 0)
					tmpGrid[x][y - 1] += 1;
				if (y + 1 < 3)
					tmpGrid[x][y + 1] += 1;
			}
			else
			{
				tmpGrid[x][y] += grid[x][y];
			}
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid[x][y] = tmpGrid[x][y];
	}
}

/**
 * sandpiles_sum - adds 2 stable sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
	}
	while (!stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
