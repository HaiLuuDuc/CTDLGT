#include<bits/stdc++.h>
using namespace std;
		
int n,m;
vector<int> parent;


void ResetParent(){
	parent.clear();
	parent.resize(n+1);
	for(int i=1;i<parent.size();i++){
		parent[i]=i;
	}
}

int Find(int u){
	if(parent[u]!=u){
		return parent[u] = Find(parent[u]);
	}
	return parent[u];
}

int Union(int a, int b){
	int A = parent[a];
	int B = parent[b];
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

		cout<<endl;
	}
	return 0;
}
