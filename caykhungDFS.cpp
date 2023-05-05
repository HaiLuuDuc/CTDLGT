#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > adj;
vector<bool> daxet;
bool isok;

void dfs(int u) {
    daxet[u] = true;
    for (int v=0;v<adj[u].size();v++) {
        if (!daxet[adj[u][v]]) {
            dfs(adj[u][v]);
        }
    }
}

void dfs2(int u) {
    daxet[u] = true;
    for (int v=0;v<adj[u].size();v++) {
        if (!daxet[adj[u][v]]) {
			cout<<u<<" ";
        	cout<<adj[u][v]<<endl;
            dfs2(adj[u][v]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, u;
        cin >> n >> m >> u;
        
        adj.clear();
        daxet.clear();
        
        adj.resize(n+1);
        daxet.resize(n+1);
        
        for (int i = 1; i <= n; i++) {
            daxet[i] = false;
        }
        
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(u);
		
		isok = true;
		//kiem tra xem da xet het cac dinh chua
        for (int i = 1; i <= n; i++) {
            if (!daxet[i]) {
                isok = false;
                break;
            }
        }
        
        if (!isok) {
            cout <<-1<<endl;
        } 
		else {
	        daxet.clear();
	        daxet.resize(n+1);      
	        for (int i = 1; i <= n; i++) {
	            daxet[i] = false;
	        }
        	dfs2(u);
        }
    }
    return 0;
}

