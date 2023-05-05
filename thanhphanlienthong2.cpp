#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10000];

void dfs(int u, bool daxet[], vector<int> &comp) {
    daxet[u] = true;
    comp.push_back(u);
    for (int v=0; v<graph[u].size();v++) {
        if (!daxet[v]) {
            dfs(v, daxet, comp);
        }
    }
}

int a(int N, bool daxet[]) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!daxet[i]) {
            vector<int> comp;
            dfs(i, daxet, comp);
            count++;
        }
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool daxet[10000] = {false};
    int components = a(N, daxet);

    for (int i = 1; i <= N; i++) {
        bool daxet[10000] = {false};
        for (int v=0; v<graph[i].size();v++) {
            daxet[v] = true;
        }
        int new_components = a(N, daxet);
        cout << components - new_components + 1 << "\n";
    }

    return 0;
}

