#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int degree[MAX];
int vertices;

void initGraph(int n) {
    vertices = n;
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v]++;
    graph[v][u]++;
    degree[u]++;
    degree[v]++;
}

bool isConnected() {
    bool visited[MAX] = {false};
    int i;

    for (i = 0; i < vertices; i++) {
        if (degree[i] != 0) break;
    }

    if (i == vertices) return true;

    int stack[MAX], top = -1;
    stack[++top] = i;
    visited[i] = true;

    while (top != -1) {
        int v = stack[top--];
        for (int u = 0; u < vertices; u++) {
            if (graph[v][u] && !visited[u]) {
                stack[++top] = u;
                visited[u] = true;
            }
        }
    }

    for (i = 0; i < vertices; i++) {
        if (!visited[i] && degree[i] > 0) return false;
    }

    return true;
}

int findStartVertex() {
    int odd = 0;
    int start = 0;

    for (int i = 0; i < vertices; i++) {
        if (degree[i] % 2 != 0) {
            odd++;
            start = i;
        }
    }

    if (odd == 0) {
        for (int i = 0; i < vertices; i++) {
            if (degree[i] > 0) return i;
        }
    }

    if (odd == 2) return start;

    return -1;
}

void findEulerUtil(int u) {
    for (int v = 0; v < vertices; v++) {
        if (graph[u][v] > 0) {
            graph[u][v]--;
            graph[v][u]--;
            findEulerUtil(v);
        }
    }
    printf("%d ", u);
}

void findEulerPathOrCircuit() {
    if (!isConnected()) {
        printf("The graph is not connected, no Euler Path or Circuit exists.\n");
        return;
    }

    int start = findStartVertex();
    if (start == -1) {
        printf("The graph has more than 2 vertices with an odd degree, so no Euler Path or Circuit exists.\n");
        return;
    }

    int oddDegreeVertices = 0;
    for (int i = 0; i < vertices; i++) {
        if (degree[i] % 2 != 0) oddDegreeVertices++;
    }

    if (oddDegreeVertices == 0) {
        printf("The graph has an Euler Circuit:\n");
        findEulerUtil(start);
        printf("\n");
    } else if (oddDegreeVertices == 2) {
        printf("The graph has an Euler Path:\n");
        findEulerUtil(start);
        printf("\n");
    } else {
        printf("The graph has no Euler Path or Circuit.\n");
    }
}

int main() {
    int n, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    initGraph(n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) format:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    findEulerPathOrCircuit();

    return 0;
}

