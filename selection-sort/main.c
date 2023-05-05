#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 20

void selection_sort(int values[], int size);

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

    selection_sort(values, ARRAY_MAX);

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

void selection_sort(int values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int lower_index = i;

        for (int j = i + 1; j < size; j++)
        {
            if (values[j] < values[lower_index])
            {
                lower_index = j;
            }
        }

        swap(values, i, lower_index);
    }
}
