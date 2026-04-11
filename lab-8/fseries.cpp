#include <stdio.h>
int fabi(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fabi(n - 1) + fabi(n - 2);
}
int main()
{
    int n;
    printf("Enter n term: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", fabi(i));
    }

    return 0;
}
