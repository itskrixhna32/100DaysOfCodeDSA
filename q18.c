/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Assume first element as max and min
    int max = arr[0];
    int min = arr[0];

    // Find max and min
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    // Output result
    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);

    return 0;
}
