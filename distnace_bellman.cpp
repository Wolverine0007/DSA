#include <iostream>
using namespace std;

const int MAXN = 50;
const int INF = 1000000000;

int main() {
    int N;
    cout << "Enter number of nodes (<= " << MAXN << "): ";
    if (!(cin >> N) || N <= 0 || N > MAXN) return 0;

    // cost[i][j] = direct link cost from i to j, -1 if no direct link
    int cost[MAXN][MAXN];
    cout << "Enter adjacency matrix (use -1 for no direct link):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost[i][j];
            if (i == j) cost[i][j] = 0; // cost to self = 0
        }
    }
    // dist[x][d] = node x's current distance estimate to destination d
    int dist[MAXN][MAXN];

    // initialize dist from direct links (or INF). To initialize the distance table of each router.
    for (int x = 0; x < N; ++x) {  //x current router whose table is being initialized,, d destination router
        for (int d = 0; d < N; ++d) { //destination router
            if (cost[x][d] >= 0) dist[x][d] = cost[x][d];  //Distance to direct neighbors = their link cost
            else dist[x][d] = INF; //Distance to non-neighbors = INF (unknown)
        }
        dist[x][x] = 0;
    }  // cost[x][d] direct link cost from x → d (or -1 if no link),,,, dist[x][d]. current distance estimate from x → d

    // iterative exchange until no change or max rounds
    bool changed;
    int rounds = 0;
    const int MAX_ROUNDS = 1000; // safety cap
    do {
        changed = false;  //tells if any update happened in this iteration
        ++rounds; //number of DV iteration rounds
        for (int x = 0; x < N; ++x) { //x = current router
/*For router x, we try to update distance to destination d
(ex: 0→1, 0→2, 0→3, etc.) */
                for (int d = 0; d < N; ++d) {
                int best = dist[x][d]; //Try to find a better one
                for (int v = 0; v < N; ++v) { //v = possible neighbor
                    if (v == x) continue; //Skip if neighbor == itself
                    if (cost[x][v] >= 0 && dist[v][d] < INF) { //Router x is directly connected to router v and Router v knows a path to destination d
                        int via = cost[x][v] + dist[v][d];
                        if (via < best) best = via;
                    }
                }
                if (best < dist[x][d]) {
                    dist[x][d] = best;
                    changed = true;
                }
            }
        }
    } while (changed && rounds < MAX_ROUNDS);

    cout << "\nConverged in " << rounds << " round(s).\n\n";
    for (int i = 0; i < N; ++i) {
        cout << "Node " << i << " distances:\n";
        for (int d = 0; d < N; ++d) {
            if (dist[i][d] >= INF) cout << "  to " << d << " : INF\n";
            else cout << "  to " << d << " : " << dist[i][d] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
