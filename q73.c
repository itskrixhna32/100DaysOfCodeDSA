// Day 73 Question 1: First Non-Repeating Character
// Find the first character that does not repeat in a string

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

char firstNonRepeatingChar(char* str) {
    int count[MAX_CHAR] = {0};
    
    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    // Find first character with count 1
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    
    return '\0'; // No non-repeating character
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    char result = firstNonRepeatingChar(str);
    
    if (result != '\0') {
        printf("First non-repeating character: %c\n", result);
    } else {
        printf("No non-repeating character found\n");
    }
    
    return 0;
}
