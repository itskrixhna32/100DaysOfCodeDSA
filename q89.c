// Day 89 Question 1: Allocate Minimum Pages
// Allocate books to students to minimize maximum pages

#include <stdio.h>
#include <stdbool.h>

bool isPossible(int books[], int n, int students, int maxPages) {
    int studentCount = 1;
    int currentPages = 0;
    
    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) {
            return false;
        }
        
        if (currentPages + books[i] > maxPages) {
            studentCount++;
            currentPages = books[i];
            
            if (studentCount > students) {
                return false;
            }
        } else {
            currentPages += books[i];
        }
    }
    
    return true;
}

int allocateMinPages(int books[], int n, int students) {
    if (students > n) {
        return -1;
    }
    
    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i];
        if (books[i] > maxBook) {
            maxBook = books[i];
        }
    }
    
    int left = maxBook, right = sum;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isPossible(books, n, students, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int n, students;
    printf("Enter number of books: ");
    scanf("%d", &n);
    
    int books[n];
    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }
    
    printf("Enter number of students: ");
    scanf("%d", &students);
    
    int result = allocateMinPages(books, n, students);
    
    if (result != -1) {
        printf("Minimum maximum pages: %d\n", result);
    } else {
        printf("Allocation not possible\n");
    }
    
    return 0;
}
