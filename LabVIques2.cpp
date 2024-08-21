#include <iostream>

using namespace std;

const int SIZE = 5;

void DFS(int graph[SIZE][SIZE], int v, bool visited[]) {
    visited[v] = true;
    for (int i = 0; i < SIZE; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

bool isConnected(int graph[SIZE][SIZE]) {
    bool visited[SIZE] = {false};
    int i;
    for (i = 0; i < SIZE; i++) {
        if (graph[i][0] != 0) {
            break;
        }
    }
    if (i == SIZE) {
        return true;
    }
    DFS(graph, i, visited);
    for (i = 0; i < SIZE; i++) {
        if (!visited[i] && graph[i][0] != 0) {
            return false;
        }
    }
    return true;
}

bool isEulerian(int graph[SIZE][SIZE]) {
    if (!isConnected(graph)) {
        return false;
    }
    int odd = 0;
    for (int i = 0; i < SIZE; i++) {
        int degree = 0;
        for (int j = 0; j < SIZE; j++) {
            if (graph[i][j]) {
                degree++;
            }
        }
        if (degree % 2 != 0) {
            odd++;
        }
    }
    return (odd == 0 || odd == 2);
}

void printEulerUtil(int graph[SIZE][SIZE], int v) {
    for (int u = 0; u < SIZE; u++) {
        if (graph[v][u]) {
            graph[v][u] = 0;
            graph[u][v] = 0;
            printEulerUtil(graph, u);
        }
    }
    cout << v << " ";
}

void printEulerTour(int graph[SIZE][SIZE]) {
    if (!isEulerian(graph)) {
        cout << "Graph is not Eulerian\n";
        return;
    }
    int u = 0;
    for (int i = 0; i < SIZE; i++) {
        int degree = 0;
        for (int j = 0; j < SIZE; j++) {
            if (graph[i][j]) {
                degree++;
            }
        }
        if (degree % 2 != 0) {
            u = i;
            break;
        }
    }
    printEulerUtil(graph, u);
    cout << endl;
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };

    printEulerTour(graph);

    return 0;
}
