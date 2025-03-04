#include <stdio.h>

int main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Number of processes should not exceed 10.\n");
        return 1;
    }

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the completion times
    g[0] = a[0] + b[0]; // First process completion time

    for (i = 1; i < n; i++) {
        g[i] = g[i - 1] + b[i]; // Completion time for other processes
    }

    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i] - b[i]; // Waiting time
        t[i] = g[i] - a[i]; // Turnaround time
        awt += w[i];
        att += t[i];
    }

    awt /= n; // Average waiting time
    att /= n; // Average turnaround time

    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);

    return 0;
}

