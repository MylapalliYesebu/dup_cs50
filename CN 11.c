#include<stdio.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10]; // routing table

int main() {
    int costmat[20][20];
    int nodes, i, j, k, count = 0;

    // Input the number of nodes (routers)
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    // Input the cost matrix
    printf("Enter the cost matrix:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &costmat[i][j]);
            costmat[i][i] = 0; // Distance from router to itself is always 0
            rt[i].dist[j] = costmat[i][j]; // Initialize distance to direct neighbors
            rt[i].from[j] = j; // Initialize 'from' as direct path
        }
    }

    // Distance Vector Routing Algorithm
    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    // If a shorter path is found, update the distance and route
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = costmat[i][k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0); // Repeat until no more updates

    // Print the final routing tables
    for (i = 0; i < nodes; i++) {
        printf("\nFor router %d\n", i + 1);
        for (j = 0; j < nodes; j++) {
            printf("Node %d via %d Distance %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }

    return 0;
}
