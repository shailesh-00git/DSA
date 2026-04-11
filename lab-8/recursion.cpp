#include <stdio.h>
int sum(int n)
{
    if (n == 1)
        return 1;
    else
    {
        return sum(n - 1) + n;
    }
}
int main()
{
    int N;
    printf("Entere N: ");
    scanf("%d", &N);
    int res = sum(N);
    printf("sum = %d", res);
    return 0;
}