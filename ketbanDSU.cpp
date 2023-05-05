#include<bits/stdc++.h>
using namespace std;
		
int n,m;
vector<int> parent;
vector<int> soluong;

void ResetParent(){
	parent.clear();
	parent.resize(n+1);
	for(int i=1;i<parent.size();i++){
		parent[i]=i;
	}
}

void ResetSoluong(){
	soluong.clear();
	soluong.resize(n+1);
	for(int i=1;i<soluong.size();i++){
		soluong[i]=0;
	}
}

int Find(int u){
	if(parent[u]!=u){
		return parent[u] = Find(parent[u]);
	}
	return parent[u];
}

int Union(int a, int b){
	int A = Find(a);
	int B = Find(b);
	if(A==B){
		return 0;
	}
	parent[B]=A;
	return 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){	
		cin>>n>>m;
		ResetParent();
		ResetSoluong();
		while(m--){
			int x,y;
			cin>>x>>y;
			Union(x,y);
		}
		for(int i=1;i<=n;i++){
			soluong[Find(i)]++;
		}
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx = max(maxx, soluong[i]);
		}
		cout<<maxx;
		cout<<endl;
	}
	return 0;
}
