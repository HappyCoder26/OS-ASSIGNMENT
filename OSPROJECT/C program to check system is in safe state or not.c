#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
int main() {
    int curr[5][5];
    int max_claim[5][5];
    int avl[5];
    int alloc[5] = {0, 0, 0, 0, 0};
    int max_res[5];
    int running[5];
    
    int i, j, exec, m, n;
    int count = 0;
    bool safe = false;
    printf("\nEnter total number of resources: ");
    scanf("%d", &m);
    printf("\nEnter total number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        running[i] = 1;
        count++;
    }
    printf("\nEnter the Final Claim Vector: ");
    for (i = 0; i < m; i++)
        scanf("%d", &max_res[i]);
        
    printf("\nEnter the Allocated Resource Table: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &curr[i][j]);
    }
    printf("\nEnter the Max Claim table: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &max_claim[i][j]);
    }
    printf("\nThe Claim Vector is: ");
    for (i = 0; i < m; i++)
        printf("%d ", max_res[i]);
        
 
    printf("\nThe Allocated Resource Table is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("\t%d", curr[i][j]);
        printf("\n");
    }
    printf("\nThe Max Claim Table is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            alloc[j] += curr[i][j];
 
    printf("\nAllocated resources: ");
    for (i = 0; i < m; i++)
        printf("%d ", alloc[i]);
    for (i = 0; i < m; i++)
        avl[i] = max_res[i] - alloc[i];
 
    printf("\nAvailable resources: ");
    for (i = 0; i < m; i++)
        printf("%d ", avl[i]);
    printf("\n");
 
    while (count != 0) {
        safe = false;
        for (i = 0; i < n; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < m; j++) {
                    if (max_claim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }
                if (exec) {
                    printf("\nProcess%d is executing.\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < m; j++)
                        avl[j] += curr[i][j];
                    break;
                }
            }
        }
        if (!safe) {
            printf("\nThe given system are in unsafe state.");
            break;
        }
        if (safe)
            printf("\nThe given system is in safe state.");
 
        printf("\nAvailable vector: ");
        for (i = 0; i < m; i++)
            printf("%d ", avl[i]);
    }
    return 0;
}
