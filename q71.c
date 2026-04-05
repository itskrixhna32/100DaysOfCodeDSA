// Day 71 - Question 1: Hash Table Using Quadratic Probing
#include <stdio.h>

#define SIZE 7

int table[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

void insert(int key) {
    int h = key % SIZE;
    int i = 0;
    
    while(i < SIZE) {
        int index = (h + i * i) % SIZE;
        if(table[index] == -1) {
            table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        i++;
    }
    printf("Hash table is full\n");
}

int search(int key) {
    int h = key % SIZE;
    
    for(int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;
        
        if(table[index] == key)
            return index;
        
        if(table[index] == -1)
            return -1;
    }
    return -1;
}

void display() {
    printf("Hash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        if(table[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, table[i]);
    }
}

int main() {
    init();
    
    int n, key;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    
    display();
    
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    int result = search(key);
    if(result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found\n", key);
    
    return 0;
}
