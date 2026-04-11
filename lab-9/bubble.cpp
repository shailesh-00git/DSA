#include <stdio.h>
#include <conio.h>
#define N 7

int Data[N] = {45, 12, 66, 7, 1, 88, 10};

void BubbleSort()
{
    int temp; // temp variable for swapping data
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (Data[j] > Data[j + 1]) // comapre current element to next element
            {
                // Swapping those elements
                temp = Data[j];
                Data[j] = Data[j + 1];
                Data[j + 1] = temp;
            }
        }
    }
}

void Display()
{
    for (int i = 0; i < N; i++)
    {
        printf("%d\t", Data[i]);
    }
}

int main()
{
    printf("Array Before sorting:\n");
    Display();
    BubbleSort();
    printf("\nArray after sorting:\n");
    Display();

    return 0;
}