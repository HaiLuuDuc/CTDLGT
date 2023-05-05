#include<bits/stdc++.h>
using namespace std;
bool daxet[10000];
vector<int> v[10000];
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
		for(int i=0;i<10000;i++){
			daxet[i]=false;
			v[i].clear();
		}
		cin>>n>>m>>u;
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
		}
		DFS(u);
		cout<<endl;
	}
	return 0;
}
