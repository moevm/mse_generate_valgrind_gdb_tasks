#include <stdio.h>

int main()
{
    int i, n, sum=0;

    printf("This program will calculate the sum of numbers from 1 to n. ");
    printf(" Please enter n: ");
    scanf("%d", &n);

    // Find sum of all numbers 
    for(i=1; i<=n; i++)
    {
        sum += i+1;
    }

    printf("Sum of first %d natural numbers = %d", n, sum);

    return 0;
}
