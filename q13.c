/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix*/
#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Input matrix elements
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Check if matrix is square
    if(m != n)
    {
        printf("Not Symmetric");
        return 0;
    }

    // Check symmetric condition
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] != A[j][i])
            {
                printf("Not Symmetric");
                return 0;
            }
        }
    }

    printf("Symmetric");
    return 0;
}
