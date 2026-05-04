#include <iostream>
#include <vector>
using namespace std;

void dfs(int current, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
    visited[current] = true;

    for (int next : graph[current]) {
        if (!visited[next]) {
            count++;
            dfs(next, graph, visited, count);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    int count = 0;

    dfs(1, graph, visited, count);

    cout << count << endl;

    return 0;
}