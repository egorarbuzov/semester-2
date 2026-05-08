#include <iostream>
#include <vector>
#include <queue>
#include <cstdarg>

using namespace std;


void printPartitions(int* colors, int count, ...) {
    va_list args;
    va_start(args, count);
    cout << "Проверка долей для выбранных вершин: ";
    for (int i = 0; i < count; i++) {
        int v = va_arg(args, int);
        if (colors[v] == 1) cout << v << "(Доля А) ";
        else if (colors[v] == 2) cout << v << "(Доля Б) ";
    }
    cout << endl;
    va_end(args);
}

bool isBipartite(int** adj, int n, int* colors) {
    for (int i = 0; i < n; i++) colors[i] = 0;

    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            queue<int> q;
            q.push(i);
            colors[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < n; v++) {
                    if (adj[u][v]) {
                        if (colors[v] == 0) {
                            colors[v] = 3 - colors[u];
                            q.push(v);
                        } else if (colors[v] == colors[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 6;
    
    int** adj = new int*[n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n]();
    }

    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[4][5] = adj[5][4] = 1;
    adj[5][0] = adj[0][5] = 1;

    int* colors = new int[n];
    if (isBipartite(adj, n, colors)) {
        cout << "Граф является двудольным." << endl;
        printPartitions(colors, 2, 0, 1);
        printPartitions(colors, 3, 0, 2, 4);
        printPartitions(colors, 4, 1, 3, 5, 0);
    } else {
        cout << "Граф не является двудольным." << endl;
    }

    for (int i = 0; i < n; i++) delete[] adj[i];
    delete[] adj;
    delete[] colors;

    return 0;
}
