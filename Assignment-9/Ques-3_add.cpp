#include <iostream>
#include <vector>
#define INT_MAX 10000000
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for(auto &t : times) graph[t[0]].push_back({t[1], t[2]});
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    dist[k] = 0;

    for(int i = 1; i <= n; i++) {
        int u = -1, minDist = INT_MAX;
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(auto &p : graph[u]) {
            int v = p.first, w = p.second;
            if(dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int main() {
    int N = 4, K = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << networkDelayTime(times, N, K) << endl;
}
