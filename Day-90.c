#include <stdio.h>

// Function to check if we can paint with given maxTime
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is greater than maxTime → not possible
        if (boards[i] > maxTime)
            return 0;

        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        } else {
            painters++;
            currentTime = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int minTime(int boards[], int n, int k) {
    int low = 0, high = 0, result = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];  // max element
        high += boards[i];   // sum
    }

    // Binary Search
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // increase limit
        }
    }

    return result;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));

    return 0;
}