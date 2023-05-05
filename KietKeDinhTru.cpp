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
		
		
		for(int v=1;v<=n;v++){
			//dem so thp lien thong truoc
			int count = 0;
			ResetDaxet();
			for(int i=1;i<=n;i++){
				if(daxet[i]==false){
					count++;
					DFS(i);
				}
			}
			ResetDaxet();
			daxet[v]=true;
			//dem so thp lien thong sau
			int count2 = 0;
			for(int i=1;i<=n;i++){
				if(daxet[i]==false){
					count2++;
					DFS(i);
				}
			}
			if(count!=count2){
				cout<<v<<" ";
			}
		}
		
		
		
		
		
		
		
		
		
		cout<<endl;
	}
	return 0;
}
