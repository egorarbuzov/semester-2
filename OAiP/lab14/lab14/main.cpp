#include <iostream>
#include <vector>
#include <cstdarg>

using namespace std;

const int INF = 1e9;
void addEdges(int** graph, int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int u = va_arg(args, int);
        int v = va_arg(args, int);
        int w = va_arg(args, int);
        graph[u][v] = w;
    }
    va_end(args);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 8;
    int** dist = new int*[n];
    for (int i = 0; i < n; i++) {
        dist[i] = new int[n];
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    addEdges(dist, 6,
             0, 1, 1,    // ребро 0-1
             1, 2, 1,    // ребро 1-2
             2, 3, 1,    // ребро 2-3
             4, 5, 1,    // ребро 4-5
             5, 6, 1,    // ребро 5-6
             6, 7, 1);   // ребро 6-7

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    cout << "Матрица кратчайших путей (8 вершин):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "? ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Очистка памяти
    for (int i = 0; i < n; i++) delete[] dist[i];
    delete[] dist;

    return 0;
}
