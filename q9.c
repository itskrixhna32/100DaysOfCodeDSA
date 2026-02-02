/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b*/

#include<stdio.h>
int pow(int a, int b)
{
    if(b==0)
    {
        return 1; // Any number to the power of 0 is 1
    }
    else if(b>0)
    {
        return a * pow(a, b-1); // Recursive case for positive exponent
    }
    else
    {
        return 1 / pow(a, -b); // Recursive case for negative exponent
    }
}
int main()
{
    int a, b;
    printf("Enter the base (a) and exponent (b) separated by space: ");
    scanf("%d %d", &a, &b);
    printf("%d raised to the power of %d is: %d", a, b, pow(a, b));
    return 0;
}