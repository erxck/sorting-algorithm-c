#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 20
#define LOW 0

void quick_sort(int values[], int low, int size);

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

    quick_sort(values, LOW, ARRAY_MAX);

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

int partition(int values[], int low, int size)
{
    int pivot = values[low];
    int i = low;

    for (int j = low + 1; j < size; j++)
    {
        if (values[j] < pivot)
        {
            i++;
            swap(values, i, j);
        }
    }

    swap(values, low, i);

    return i;
}

void quick_sort(int values[], int low, int size)
{
    if (low < size)
    {
        int pivot = partition(values, low, size);
        quick_sort(values, low, pivot - 1);
        quick_sort(values, pivot + 1, size);
    }
}
