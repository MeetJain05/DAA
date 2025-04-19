#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>>& graph, int V) {
    
    vector<vector<int>> dist = graph;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 4; 
    vector<vector<int>> graph = {
        {0, 3, INF, INF},
        {2, 0, INF, 1},
        {INF, 3, 0, 2},
        {INF, INF, 4, 0}
    };

    floydWarshall(graph, V);

    return 0;
}
