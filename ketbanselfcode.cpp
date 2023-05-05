#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
int n,m;
int count;
void DFS(int u){
	daxet[u] = true;
	for(int i=0;i<v[u].size();i++){
		int tmp = v[u][i];
		if(daxet[tmp]==false){
			::count++;
			DFS(tmp);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		v.clear(); v.resize(n+9);
		daxet.clear(); daxet.resize(n+9,false);
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		int maxx = 0;
		

		for(int i=1;i<=n;i++){
			if(daxet[i]==false){
				::count = 1;
				DFS(i);
				maxx = max(::count,maxx);
			}
		}

		cout<<maxx;
		
		cout<<endl;
	}
	return 0;
}
