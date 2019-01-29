#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[] )
{
    int n, i;
    unsigned long long factorial = 1;

    
    //printf("Factorial of %d", atoi(argv[1]));

    printf("Enter an integer: ");
    scanf("%d",&n);

    // show error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");

    else
    {
        for(i=1; i<=n; ++i)
        {
            factorial *= i;              // factorial = factorial*i;
        }
        printf("Factorial of %d = %llu", n, factorial);
    }

    return 0;
}
