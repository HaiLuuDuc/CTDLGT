#include<bits/stdc++.h>
using namespace std;
bool daxet[10000];
vector<int> v[10000];
void DFS(int u){
	daxet[u] = true;
	for(int i=0;i<v[u].size();i++){
		if(daxet[v[u][i]]==false){
			DFS(v[u][i]);
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
		int n,m;
		cin>>n>>m;
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int count=0;
		for(int i=1;i<=n;i++){
			if(daxet[i]==false){
				count++;
				DFS(i);
			}
		}
		cout<<count<<endl;
		
	}
	return 0;
}
