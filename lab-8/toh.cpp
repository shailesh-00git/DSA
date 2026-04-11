#include <stdio.h>
void TOH(int N, char A, char B, char C)
{
    if (N == 1)
    {
        printf("Move %d from %c to %c\n", N, A, C);
        return;
    }
    TOH(N - 1, A, C, B);
    printf("Move %d from %c to %c\n", N, A, C);
    TOH(N - 1, B, A, C);
}
int main()
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    TOH(N, 'A', 'B', 'C');
    return 0;
}