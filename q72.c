// Day 72 Question 1: First Repeated Character
// Find the first character that repeats in a string

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 256

char firstRepeatedChar(char* str) {
    bool visited[MAX_CHAR] = {false};
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (visited[(unsigned char)str[i]]) {
            return str[i];
        }
        visited[(unsigned char)str[i]] = true;
    }
    
    return '\0'; // No repeated character
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    char result = firstRepeatedChar(str);
    
    if (result != '\0') {
        printf("First repeated character: %c\n", result);
    } else {
        printf("No repeated character found\n");
    }
    
    return 0;
}
