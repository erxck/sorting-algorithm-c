#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 20

void insertion_sort(int values[], int size);

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

    insertion_sort(values, ARRAY_MAX);

    printf("After: ");
    for (int i = 0; i < ARRAY_MAX; i++)
    {
        printf("%d ", values[i]);
    }

    return 0;
}

void insertion_sort(int values[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int x = values[i];
        int j = i - 1;

        while (j >= 0 && values[j] > x)
        {
            values[j + 1] = values[j];
            j--;
        }

        values[j + 1] = x;
    }
}