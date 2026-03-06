#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    long long total = 0;
    int start = -1;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
        total += w;
        if(start == -1){start = u;}
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>> pq; 
    pq.push({0, start});

    long long keep = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        keep += weight;

        for (auto [v, w] : graph[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << total - keep << "\n";
    return 0;
}