#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 20

void bubble_sort(int values[], int size);

int main()
{
    int values[ARRAY_MAX];

    srand(time(NULL));

    printf("Before: ");
    for (int i = 0; i < ARRAY_MAX; i++)
    {
        values[i] = 1 + rand() % 50;
        printf("%d ", values[i]);
    }

    printf("\n");

    bubble_sort(values, ARRAY_MAX);

    printf("After: ");
    for (int i = 0; i < ARRAY_MAX; i++)
    {
        printf("%d ", values[i]);
    }

    return 0;
}

void swap(int values[], int a, int b)
{
    int aux = values[a];
    values[a] = values[b];
    values[b] = aux;
}

void bubble_sort(int values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (values[j] > values[j + 1])
            {
                swap(values, j, j + 1);
            }
        }
    }
}
