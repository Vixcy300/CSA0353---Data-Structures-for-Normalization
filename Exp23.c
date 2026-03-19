#include <stdio.h>
#define MAX 10
#define INF 999

int main() {
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    int n, source;
    int i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;
    count = 1;

    while (count < n - 1) {
        min = INF;

        for (i = 0; i < n; i++) {
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;
        count++;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[u] + cost[u][i] < dist[i]) {
                dist[i] = dist[u] + cost[u][i];
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}
