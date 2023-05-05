#include<bits/stdc++.h>
using namespace std;


int n,m;
vector<vector<int> > v;
vector<bool> daxet;


void ResetVector(){
	v.clear();
	v.resize(n+1);
}

void InRaVector(){
	for(int i=1;i<=n;i++){
			cout<<i<<": ";
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
	}
}

void DFS(int u){
	daxet[u]=true;
	for(int j=0;j<v[u].size();j++){
		if(daxet[v[u][j]]==false){
			DFS(v[u][j]);
		}
	}
}

void ResetDaxet(){
	daxet.clear();
	daxet.resize(n+1);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ResetVector();
	
		//nhap du lieu tu input
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	
		InRaVector();
		
		
		
		
		
		
		
		cout<<endl;
	}
	return 0;
}
