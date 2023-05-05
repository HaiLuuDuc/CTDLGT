#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
int n,m,u;
void DFS(int u){
	daxet[u] = true;
	cout<<u<<" ";
	for(int i=0;i<v[u].size();i++){
		int tmp = v[u][i];
		if(daxet[tmp]==false){
			DFS(tmp);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>u;
		v.clear(); v.resize(n+9);
		daxet.clear(); daxet.resize(n+9,false);
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		DFS(u);
		cout<<endl;
	}
	return 0;
}
