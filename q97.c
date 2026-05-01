// Day 97 Question 1: Meeting Rooms Scheduling
// Check if a person can attend all meetings

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int start;
    int end;
} Meeting;

void swap(Meeting* a, Meeting* b) {
    Meeting temp = *a;
    *a = *b;
    *b = temp;
}

void sortMeetings(Meeting meetings[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (meetings[j].start > meetings[j + 1].start) {
                swap(&meetings[j], &meetings[j + 1]);
            }
        }
    }
}

bool canAttendMeetings(Meeting meetings[], int n) {
    if (n == 0) {
        return true;
    }
    
    sortMeetings(meetings, n);
    
    for (int i = 0; i < n - 1; i++) {
        if (meetings[i].end > meetings[i + 1].start) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);
    
    Meeting meetings[n];
    printf("Enter meeting times (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }
    
    if (canAttendMeetings(meetings, n)) {
        printf("Can attend all meetings\n");
    } else {
        printf("Cannot attend all meetings\n");
    }
    
    return 0;
}
