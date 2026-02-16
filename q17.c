/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers*/
#include <stdio.h>

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency of each element
    for(int i = 0; i < n; i++) {
        int count = 1;

        // Skip if element already counted
        if(arr[i] == -999999) 
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -999999;  // mark counted element
            }
        }

        printf("%d occurs %d times\n", arr[i], count);
    }

    return 0;
}
