#define START_POINT 1
#define ARRAY_SIZE 5

#include "libs/libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *fill_array(void)
{
    int *array;
    int i;
    int count;

    count = 0;
    i = - (ARRAY_SIZE/2);
    array = ft_calloc(ARRAY_SIZE + 1, sizeof(int));
    if (!array)
        return (NULL);
    while (count < ARRAY_SIZE)
    {
        array[count++] = i++;
    }
    return (array);
}

int *shuffle(int *array)
{
    int i;
    int temp;
    int index;

    i = 0;
    srand(time(0));
    while (i < ARRAY_SIZE)
    {
        temp = array[i];
        index = rand() % ARRAY_SIZE;
        array[i++] = array[index];
        array[index] = temp;
    }
    return (array);
}

int main(int argc, char **argv)
{
    int file;
    int i;
    int *array;

    i = 0;
    array = fill_array();
    if (!argc)
       return (0);
    if (array)
    {
        file = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        array = shuffle(array);
        dup2(file, 1);
        while (i < ARRAY_SIZE)
            printf("%i ", array[i++]);
        close(file);
        free(array);
    }
    return (0);
}