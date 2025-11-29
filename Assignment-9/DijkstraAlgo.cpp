#include <iostream>
#include <vector>
using namespace std;
#define INF 10000000
void initialize(int n,int s,vector<int> &d,vector<int> &pi) {
    for (int i=0;i<n;i++) {
        d[i] = INF; // shortest distance
        pi[i] = -1; // parent
    }
    d[s] = 0;
}
int extract_min(vector<int> &d,vector<int> &visited,int n) {
    int u = -1;
    for (int i=0;i<n;i++) {
        if (!visited[i] && (u==-1 || d[i]<d[u])) {
            u = i;
        }
    }
    return u;
}
void relax(int u,int v,int w,vector<int> &d,vector <int> &pi) {
    if(d[v]>d[u]+w) {
        d[v] = d[u] + w;
        pi[v] = u;
    }
}