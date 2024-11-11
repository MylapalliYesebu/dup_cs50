#include <stdio.h>

struct Edge {
    int v1, v2, w;
} edj[20], temp;

int main() {
    int i, j, n = 0, s, d, par[20], s1, d1;

    // Input the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &n);

    // Input the nodes and their weights (edges)
    for (i = 0; i < n; i++) {
        printf("Enter node1, node2, and weight: ");
        scanf("%d %d %d", &edj[i].v1, &edj[i].v2, &edj[i].w);
        par[i] = 0; // Initialize parent array to 0
    }

    // Sort edges based on weight (using bubble sort)
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (edj[j].w > edj[i].w) {
                temp = edj[i];
                edj[i] = edj[j];
                edj[j] = temp;
            }
        }
    }

    // Display the entered edges
    printf("\nENTERED VALUES\n");
    for (i = 0; i < n; i++) {
        printf("%d %d %d\n", edj[i].v1, edj[i].v2, edj[i].w);
    }

    // Broadcast tree construction
    printf("\nBROADCAST TREE FOR THE GIVEN GRAPH\n");
    for (i = 0; i < n; i++) {
        s = edj[i].v1;
        d = edj[i].v2;
        s1 = s;
        d1 = d;

        // Find the parent of the source
        while (par[s1] != 0) {
            s1 = par[s1];
        }

        // Find the parent of the destination
        while (par[d1] != 0) {
            d1 = par[d1];
        }

        // If parents are not the same, include the edge in the broadcast tree
        if (s1 != d1) {
            par[d] = s;
            printf("%d %d %d\n", s, d, edj[i].w);
        }
    }

    return 0;
}
