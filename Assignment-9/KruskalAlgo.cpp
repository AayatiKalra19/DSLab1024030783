#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void make_set(int x,vector<int> &parent,vector<int> &rank) {
    parent[x] = x;
    rank[x] = 0;
}
int find_set(int x,vector<int> &parent) {
    if (x!=parent[x]) {
        parent[x] = find_set(parent[x],parent);
    }
    return parent[x];
}
void link_set(int x,int y,vector<int> &parent,vector<int> &rank) {
    if(rank[x]>rank[y]) {
        parent[y] = x;
    }
    else {
        parent[x] = y;
        if (rank[x] ==  rank[y]) {
            rank[y]++;
        }
    }
}
void union_set(int x,int y,vector<int> &parent,vector<int> &rank) {
    link_set(find_set(x,parent),find_set(y,parent),parent,rank);
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<int> U(E), V2(E), W(E);
    for (int i = 0; i < E; i++) {
        cin >> U[i] >> V2[i] >> W[i];
    }
    vector<int> idx(E);
    for (int i = 0; i < E; i++) idx[i] = i;

    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return W[a] < W[b];
    });
    vector<int> parent(V), rank(V);
    for (int i = 0; i < V; i++)
        make_set(i, parent, rank);
    cout << "Edges in MST:\n";
    for (int i = 0; i < E; i++) {
        int e = idx[i];
        int u = U[e];
        int v = V2[e];
        if (find_set(u, parent) != find_set(v, parent)) {
            cout << u << " - " << v << " (" << W[e] << ")\n";
            union_set(u, v, parent, rank);
        }
    }
    return 0;
}