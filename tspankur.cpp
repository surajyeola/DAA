#include <iostream>
#include <limits.h>
using namespace std;

#define N 4  

int calcBound(int cost, int adj[N][N], bool vis[N], int curr) {
    int bound = cost;
    int minCost = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (!vis[i] && adj[curr][i] < minCost) {
            minCost = adj[curr][i];
        }
    }

    if (minCost == INT_MAX) minCost = 0;  
    return bound + minCost;
}


void explore(int lvl, int curr, int adj[N][N], int path[N], bool vis[N], int &cost, int &minCost, int best[N]);

void tspBnB(int adj[N][N], int best[N], int &minCost) {
    int path[N];  
    bool vis[N] = {false}; 
    int cost = 0;

    path[0] = 0;  
    vis[0] = true;  

   
    explore(0, 0, adj, path, vis, cost, minCost, best);
}

void explore(int lvl, int curr, int adj[N][N], int path[N], bool vis[N], int &cost, int &minCost, int best[N]) {
    if (lvl == N - 1) {
        int totalCost = cost + adj[curr][0];
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < N; i++) {
                best[i] = path[i];
            }
        }
        return;
    }

    for (int next = 0; next < N; next++) {
        if (!vis[next]) {
            int newCost = cost + adj[curr][next];
            int bound = calcBound(newCost, adj, vis, next);

            if (bound < minCost) {
                vis[next] = true;
                path[lvl + 1] = next;
                cost = newCost;

                explore(lvl + 1, next, adj, path, vis, cost, minCost, best);

                vis[next] = false;
                cost -= adj[curr][next];
            }
        }
    }
}

int main() {
    int adj[N][N];
    cout << "Enter the adjacency matrix (" << N << "x" << N << "):" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    int best[N];  
    int minCost = INT_MAX;  

    tspBnB(adj, best, minCost);

    cout << "Minimum cost: " << minCost << endl;
    cout << "Best path: ";
    for (int i = 0; i < N; i++) {
        cout << best[i] << " -> ";
    }
    cout << "0" << endl;  

    return 0;
}