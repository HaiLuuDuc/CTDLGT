#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& visited, stack<int>& stk, int u) {
    visited[u] = 1;
    for (int v = 0; v < adj.size(); ++v) {
        if (adj[u][v] && !visited[v]) {
            dfs(adj, visited, stk, v);
        }
    }
    stk.push(u);
}

bool hasEulerCycle(vector<vector<int>>& adj) {
    int n = adj.size(), cnt = 0;
    vector<int> indeg(n), outdeg(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j]) {
                ++outdeg[i], ++indeg[j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (indeg[i] != outdeg[i]) {
            return false;
        }
    }
    return true;
}

vector<int> findEulerCycle(vector<vector<int>>& adj) {
    if (!hasEulerCycle(adj)) {
        return {};
    }
    int n = adj.size(), u = 0;
    stack<int> stk;
    vector<int> eulerCycle;
    vector<int> visited(n);
    dfs(adj, visited, stk, u);
    while (!stk.empty()) {
        u = stk.top();
        stk.pop();
        if (!visited[u]) {
            continue;
        }
        vector<int> cycle;
        dfs(adj, visited, cycle, u);
        eulerCycle.insert(eulerCycle.end(), cycle.rbegin(), cycle.rend());
    }
    return eulerCycle;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    vector<int> eulerCycle = findEulerCycle(adj);
    if (eulerCycle.empty()) {
        cout << "No Euler cycle found." << endl;
    } else {
        cout << "Euler cycle: ";
        for (int u : eulerCycle) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}
