#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
int n,m,u;
bool isCoDuongDi;
void DFS(int u){
	daxet[u] = true;
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
		cin>>n>>m;
		v.clear();  v.resize(n+1);


		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int q; cin>>q;
		while(q--){
			daxet.clear();  daxet.resize(n+1,false);
			int x,y;
			cin>>x>>y;
			DFS(x);
			if(daxet[y]){
				isCoDuongDi = true;
				cout<<"YES";
			}
			else{
				isCoDuongDi = false;
				cout<<"NO";
			}
			cout<<endl;
		}
		
		cout<<endl;
	}
	return 0;
}
