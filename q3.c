/*Write a C program to delete the element at a given 1-based position pos from an array of n integers. 
Shift remaining elements to the left.*/
#include <stdio.h>
void createarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void displayarray(int arr[], int n)
{
    printf("Array elements are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void delete(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[100];
    int n, size = 0,index;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    createarray(arr, n);
    size = n;
    displayarray(arr, size);
    printf("Enter the position of element to be deleted (1-based): ");
    scanf("%d", &index);
    if (index < 1 || index > size)
    {
        printf("Invalid position!\n");
    }
    else
    {
        delete(arr, size, index - 1);
        size--;
        displayarray(arr, size);
    }
    return 0;
}