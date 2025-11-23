#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, src;

    cout << "Enter number of nodes: ";
    cin >> n;

    int cost[10][10], dist[10], visited[10], parent[10];

    cout << "Enter cost matrix (use 999 for no direct link):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    cout << "Enter source node (0 to " << n - 1 << "): ";
    cin >> src;

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        parent[i] = src;
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;

    // Dijkstra's algorithm
    for (int count = 1; count < n - 1; count++) {
        int minDist = 999, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // No more reachable nodes
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    // Print routing table with Next Hop
    cout << "\nRouting Table for Node " << src << endl;
    cout << "Destination\tCost\tNext Hop\tPath\n";

    for (int i = 0; i < n; i++) {
        if (i == src) continue;

        // Find next hop
        int nextHop = i;
        while (parent[nextHop] != src) {
            nextHop = parent[nextHop];
        }

        // Build full path
        string path = to_string(i);
        int temp = i;
        while (temp != src) {
            temp = parent[temp];
            path = to_string(temp) + "->" + path;
        }

        cout << i << "\t\t" << dist[i] << "\t" << nextHop << "\t\t" << path << endl;
    }

    return 0;
}

