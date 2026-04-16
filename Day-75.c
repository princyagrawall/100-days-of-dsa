#include <stdio.h>
#include <stdlib.h>

// Simple hash map using arrays (since constraints are unknown)
#define MAX 10000

int maxLenZeroSum(int arr[], int n) {
    int prefixSum = 0, maxLen = 0;

    // Initialize hashmap with -1
    int hash[MAX];
    for(int i = 0; i < MAX; i++)
        hash[i] = -2;   // -2 means not visited

    // To handle negative sums, we shift index
    int offset = MAX / 2;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum becomes 0
        if(prefixSum == 0) {
            maxLen = i + 1;
        }

        // Check if this prefix sum seen before
        if(hash[prefixSum + offset] != -2) {
            int prevIndex = hash[prefixSum + offset];
            if(i - prevIndex > maxLen)
                maxLen = i - prevIndex;
        } else {
            // Store first occurrence
            hash[prefixSum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSum(arr, n);
    printf("%d\n", result);

    return 0;
}