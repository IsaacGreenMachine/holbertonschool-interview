#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * Return: void
 * A level 0 sponge is represented by the # character
 * A level 1 sponge is a 3x3 square of level 0 sponges,
 *      except for the center one, which is left empty
 * A level 2 sponge is a 3x3 square of level 1 sponges,
 *      except for the center one, which is left empty
 * A level N sponge is a 3x3 square of level N-1 sponges,
 *      except for the center one, which is left empty
 * A level N Menger sponge has dimensions sized at 3^N
 */
void menger(int level)
{
int i;
int j;
int meng[1000][1000];
int *mptr = &meng[0][0];
if (level < 0)
return;
else if (level == 0)
{
printf("#\n");
return;
}
else
{
drawMenger(level, 0, 0, mptr, pow(3, level));
for (i = 0; i < pow(3, level); i++)
{
for (j = 0; j < pow(3, level); j++)
{
if (meng[i][j] == 1)
printf("#");
else
printf(" ");
}
printf("\n");

}
}
}

/**
 * drawMenger - draws a 2D Menger Sponge recursively
 * @level: the level of the Menger Sponge to draw
 * @x: x position to start drawing
 * @y: y position to start drawing
 * @mptr: pointer to array
 * @size: size of one dimension of menger sponge
 * Return: void
 */
void drawMenger(int level, int x, int y, int *mptr, int size)
{
int i;
int j;
int newx;
int newy;
if (level == 0)
*(mptr + (x) + (1000 * y)) = 1;
else
{
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (!(i == 1 && j == 1))
{
newx = (int) (pow(3, (level - 1)) * i) + x;
newy = (int) (pow(3, (level - 1)) * j) + y;
drawMenger(level - 1, newx, newy, mptr, size);
}
}
}
}
}

