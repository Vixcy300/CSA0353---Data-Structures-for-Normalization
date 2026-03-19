#include <stdio.h>

struct edge {
    int u, v, w;
};

int parent[10];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[b] = a;
}

int main() {
    struct edge e[20];
    int n, m;
    int i, j;
    int count = 0;
    int cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }

    /* Sort edges based on weight (Bubble Sort) */
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                struct edge temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    /* Initialize parent array */
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in Minimum Spanning Tree:\n");

    for (i = 0; i < m && count < n - 1; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);

        if (a != b) {
            printf("%d - %d : %d\n", e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            unionSet(a, b);
            count++;
        }
    }

    printf("Total cost of MST: %d\n", cost);

    return 0;
}
