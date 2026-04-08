// Day 74 Question 1: Winner of an Election
// Find the candidate with the most votes

#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} Candidate;

void findWinner(char votes[][MAX_NAME_LEN], int n) {
    Candidate candidates[MAX_CANDIDATES];
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(candidates[j].name, votes[i]) == 0) {
                candidates[j].votes++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(candidates[count].name, votes[i]);
            candidates[count].votes = 1;
            count++;
        }
    }
    
    // Find winner
    int maxVotes = 0;
    char winner[MAX_NAME_LEN];
    
    for (int i = 0; i < count; i++) {
        if (candidates[i].votes > maxVotes || 
            (candidates[i].votes == maxVotes && strcmp(candidates[i].name, winner) < 0)) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        }
    }
    
    printf("Winner: %s with %d votes\n", winner, maxVotes);
}

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);
    
    char votes[n][MAX_NAME_LEN];
    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }
    
    findWinner(votes, n);
    
    return 0;
}
