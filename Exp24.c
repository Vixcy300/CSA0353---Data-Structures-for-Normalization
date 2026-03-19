#include <stdio.h>
#define MAX 10
#define INF 999

int main() {
    int n, cost[MAX][MAX];
    int selected[MAX];
    int i, j, x, y;
    int edges = 0;
    int min, totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
        selected[i] = 0;
    }

    selected[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        x = 0;
        y = 0;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, min);
        totalCost += min;
        selected[y] = 1;
        edges++;
    }

    printf("Total cost of MST: %d\n", totalCost);

    return 0;
}
