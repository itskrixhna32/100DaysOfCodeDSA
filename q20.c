/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers. using C*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min_sum = INT_MAX;
    int x, y;

    // check every pair
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (abs(sum) < abs(min_sum))
            {
                min_sum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("Two elements whose sum is closest to zero: %d %d", x, y);

    return 0;
}