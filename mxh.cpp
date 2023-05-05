#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<vector<int> > G;
vector<bool> vs;

void DFS(int u) {
    vs[u] = true;
    for (int v=0; v<G[u].size();v++) {
        if (!vs[v]) {
            DFS(v);
        }
    }
}

    


int main() {
    int t = 1;
	cin >> t;
    while (t--) {
    	cin >> n >> m;
  		  for (int i = 1; i <= m; ++i) {
   			     cin >> u >> v;
   	 	    G[u].push_back(v);
    	    G[v].push_back(u);
 	   }
 	   DFS(1);
  		  for (int i = 2; i <= n; ++i) {
   			     if (!vs[i]) {
   			         cout << "NO";
   			         return 0;
    		    }
   			 }
    	cout << "YES";
        cout<<endl;
    }
    return 0;
}
