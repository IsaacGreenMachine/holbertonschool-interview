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
char one[] = "###\n# #\n###\n";
char *final;
if (level >= 0)
{
if (level == 0)
printf("#\n");
else if (level == 1)
printf("%s", one);
else
{
final = drawMenger(level, &one[0]);
printf("%s", final);
free(final);
}
}
}

/**
 * drawMenger - draws a 2D Menger Sponge recursively
 * @level: the level of the Menger Sponge to draw
 * @str: input menger sponge (lv - 1)
 * Return: menger sponge string
 */
char *drawMenger(int level, char *str)
{
char *newstr;
char *line;
int i;
int j;
int k;
int x;
if (level > 2)
str = drawMenger(level - 1, str);
newstr = (char *) malloc((strlen(str) * sizeof(char) * 9) + 1);
line = (char *) malloc((strlen(str) * sizeof(char) * 3) + 1);
for (i = 0; i < (int) (strlen(str) * sizeof(char) * 9); i++)
newstr[i] = '\0';
for (i = 0; i < (int) (strlen(str) * sizeof(char) * 3); i++)
line[i] = '\0';
for (j = 0; j < 3; j++)
{
for (i = 0; i < (int) strlen(str); i++)
{
if (str[i] == '\n')
{
newstr = strcat(newstr, line);
if (j == 1)
{
for (x = 0; x < (int) strlen(line); x++)
newstr = strcat(newstr, " ");
}
else
newstr = strcat(newstr, line);
newstr = strcat(newstr, line);
newstr = strcat(newstr, "\n");
for (k = 0; k < (int) (strlen(str) * sizeof(char) * 3); k++)
line[k] = '\0';
}
else
line = strncat(line, &str[i], 1);
}
}

free(line);
return (newstr);
}

