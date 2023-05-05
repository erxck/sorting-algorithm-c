#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 20

void merge_sort(int values[], int size);

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

    merge_sort(values, ARRAY_MAX);

    printf("After: ");
    for (int i = 0; i < ARRAY_MAX; i++)
    {
        printf("%d ", values[i]);
    }

    return 0;
}

void merge(int values[], int left[], int left_size, int right[], int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            values[k] = left[i];
            i++;
        }
        else
        {
            values[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        values[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        values[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int values[], int size)
{
    if (size < 2)
    {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = values[i];
    }

    for (int i = mid; i < size; i++)
    {
        right[i - mid] = values[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    merge(values, left, mid, right, size - mid);
}