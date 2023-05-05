#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100;


bool isStronglyConnected(int graph[][MAXN], int V) {
    vector<int> adj[MAXN];
    bool visited[MAXN] = {false};

 
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(graph[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

 
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

 
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            return false;
        }
    }
    return true;
}

bool hasEqualDegree(int graph[][MAXN], int V) {
    int indegree[MAXN] = {0};
    int outdegree[MAXN] = {0};


    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(graph[i][j]) {
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }

    for(int i=0; i<V; i++) {
        if(indegree[i] != outdegree[i]) {
            return false;
        }
    }
    return true;
}

bool isEulerian(int graph[][MAXN], int V) {
    if(!isStronglyConnected(graph, V)) {
        return false;
    }

    if(!hasEqualDegree(graph, V)) {
        return false;
    }

    return true;
}

int main() {
    int V;
    int graph[MAXN][MAXN];

    cin >> V;
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cin >> graph[i][j];
        }
    }

    if(isEulerian(graph, V)) {
        cout << "La do thi Euler" << endl;
    } else {
        cout << "Khong phai do thi Euler" << endl;
    }

    return 0;
}
