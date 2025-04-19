#include <iostream>

using namespace std;

#define MAX_NODES 100  
#define MAX_EDGES 1000 

struct Edge {
    int src, dest, weight;
};

class DisjointSet {
private:
    int parent[MAX_NODES];
    int rank[MAX_NODES];

public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]); 
        return parent[node];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void bubbleSort(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskalMST(Edge edges[], int V, int E) {
    bubbleSort(edges, E);

    DisjointSet ds(V);
    Edge result[MAX_NODES]; 
    int edgeCount = 0;
    
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        Edge nextEdge = edges[i];
        
        int root1 = ds.find(nextEdge.src);
        int root2 = ds.find(nextEdge.dest);

        if (root1 != root2) {
            result[edgeCount++] = nextEdge;
            ds.unionSets(root1, root2);
        }
    }

    cout << "Edges in Minimum Spanning Tree:\n";
    for (int i = 0; i < edgeCount; i++)
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
}

int main() {
    int V = 4, E = 5; 

    Edge edges[MAX_EDGES] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E);

    return 0;
}
