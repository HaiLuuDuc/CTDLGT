#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> parent;
void ResetParent(){	
	parent.clear();
	parent.resize(n+1);
	for(int i=1;i<=n;i++){
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
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			Union(x,y);
		}
		set<int> s;
		s.clear();
		for(int i=1;i<=n;i++){
			s.insert(Find(i));
		}
		cout<<s.size();
		
		
		
		
		cout<<endl;
	}
	return 0;
}
