#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
vector<int> banbacra;
vector<int> banbacvao;
int n,m;
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
		v.clear(); v.resize(n+9);
		daxet.clear(); daxet.resize(n+9,false);
		banbacra.clear(); banbacra.resize(n+9,0);
		banbacvao.clear(); banbacvao.resize(n+9,0);
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			banbacra[x]++;
			banbacvao[y]++;
		}
		
		//in ra danh sach ke
//		for(int i=1;i<=n;i++){
//			cout<<i<<": ";
//			for(int j=0;j<v[i].size();j++){
//				cout<<v[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		for(int i=1;i<=n;i++){
			if(banbacra[i]!=banbacvao[i]){
				cout<<0;
				goto label;
			}
		}
		cout<<1;
		label:;
		cout<<endl;
	}
	return 0;
}
