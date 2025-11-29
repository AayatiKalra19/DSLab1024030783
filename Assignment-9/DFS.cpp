#include <iostream>
#include <vector>
using namespace std;
void DFS(int vertices,vector <int> adj[],int start,vector <int> &vis) {
    vis[start] = 1;
    cout<<start<<" ";
    for (int x:adj[start]) {
        if (!vis[x]) {
            DFS(vertices,adj,x,vis);
        }
    }
}