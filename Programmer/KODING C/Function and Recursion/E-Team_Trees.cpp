#include<stdio.h>
#include <stdio.h>

void calculateSum(int caseNumber, int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    printf("Case #%d: %d\n", caseNumber, sum);
}

int main() {
    int t; 
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);

        int numbers[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &numbers[j]);
        }

        calculateSum(i, numbers, n);
    }

    return 0;
}

