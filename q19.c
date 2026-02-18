/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k*/
#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    int temp[n];

    // Rotate array
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}
