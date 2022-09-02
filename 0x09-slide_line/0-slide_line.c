#include "slide_line.h"


/**
 * slide_line - Slides a line of integers to the left or right
 *
 * @line: Pointer to the array of integer to be moved
 * @size: Number of elements in line
 * @direction: Direction to move. 0 is L, 1 is R
 *
 * Return: 1 if successful, 0 if failed
 */

int slide_line(int *line, size_t size, int direction)
{
    int i;
    int pos;
    int curr = 0;
    int hold = 0;
    size = (int) size;
        /* Left */
    if (direction == 0)
    {
        pos = 0;
        for (i = 0; i < (int) size; i++)
            {
                if (line[i] != 0)
                {
                    curr = line[i];
                    if (pos != i)
                    {
                        line[i] = 0;
                    }
                    if (hold == 0)
                    {
                       hold = curr;
                    }
                    else if (hold == curr)
                    {
                        line[pos] = curr + hold;
                        pos++;
                        hold = 0;
                    }
                    else
                    {
                        line[pos] = hold;
                        line[pos + 1] = curr;
                        pos += 2;
                        hold = 0;
                    }

                }
            }
            if (hold != 0)
            {
                line[pos] = hold;
            }
    }
    /* Right */
    if (direction == 1)
    {
        pos = size - 1;
        for (i = size - 1; i >= 0; i--)
        {
            if (i >= 0)
            {
            if (line[i] != 0)
            {
                curr = line[i];
                if (pos != i)
                {
                    line[i] = 0;
                }
                if (hold == 0)
                {
                    hold = curr;
                }
                else if (hold == curr)
                {
                    line[pos] = curr + hold;
                    pos--;
                    hold = 0;
                }
                else
                {
                    line[pos] = hold;
                    line[pos - 1] = curr;
                    pos -= 2;
                    hold = 0;
                }
            }
            if (hold != 0)
            {
                line[pos] = hold;
            }
        }
        }

    }
    return 1;
}
