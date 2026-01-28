/*Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)*/
#include <stdio.h>
int main()
{
    int n, i, k, found = 0, comparisons = 0;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Read the array elements
    printf("Enter %d space-separated integers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the key to search
    printf("Enter the key to search: ");
    scanf("%d", &k);

    // Perform linear search
    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = 1;
            break;
        }
    }

    // Display results
    if(found) {
        printf("Key %d found in the array.\n", k);
    } else {
        printf("Key %d not found in the array.\n", k);
    }
    printf("Number of comparisons made: %d\n", comparisons);

    return 0;
}