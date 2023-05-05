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
		bool isHaveChuTrinh = false;
		cin>>n>>m;
		ResetParent();
		while(m--){
			int x,y;
			cin>>x>>y;
			if(Union(x,y)==0){ // chung parent
				isHaveChuTrinh = true;
			}
			else{
				Union(x,y);
			}
		}
		
		if(isHaveChuTrinh){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		
		
	
		cout<<endl;
	}
	return 0;
}
