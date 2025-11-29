#include <iostream>
#include <vector>
using namespace std;
#define INF 100000000
// Prim's algorithm - minimum spanning tree
void prim_algo(int vertex,vector <int> weights,vector <pair<int,int>> adj[]) {
    vector <int> vis(vertex,0);
    vector <int> parent(vertex,-1);
    vector <int> key(vertex,INF);
    key[0] = 0;
    for (int count = 0;count<vertex-1;count++) {
        int u = -1; // minimum element in key vector
        for (int i=0;i<vertex;i++) {
            if (!vis[i] && (u==-1 || key[i]<key[u])) {
                u = i;
            }
        }
        vis[u] = 1;
        for (auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;
            if (!vis[v] && wt<key[v]) {
                key[v] = wt;
                parent[v] = u;
            }
        }
    }
}