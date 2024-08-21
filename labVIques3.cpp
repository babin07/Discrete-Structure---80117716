#include <iostream>

using namespace std;

const int SIZE = 5;
const int INF = 1000000; // A large value to represent infinity

int minDistance(int dist[], bool sptSet[]) {
    int min = INF, min_index;
    for (int v = 0; v < SIZE; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int n) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < n; i++)
        cout << i << " \t\t " << dist[i] << "\n";
}

void dijkstra(int graph[SIZE][SIZE], int src) {
    int dist[SIZE];
    bool sptSet[SIZE];

    for (int i = 0; i < SIZE; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < SIZE - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < SIZE; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, SIZE);
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    int src = 0; // Initial position
    dijkstra(graph, src);

    return 0;
}
