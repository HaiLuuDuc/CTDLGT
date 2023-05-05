#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
vector<int> truoc;
int n,m,dau,cuoi;
void DFS(int u){
	daxet[u] = true;
	for(int i=0;i<v[u].size();i++){
		int tmp = v[u][i];
		if(daxet[tmp]==false){
			truoc[tmp]=u;
			DFS(tmp);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>dau>>cuoi;
		v.clear(); v.resize(n+9);
		daxet.clear(); daxet.resize(n+9,false);
		truoc.clear(); truoc.resize(n+9,-1);
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		DFS(dau);
		
		if(truoc[cuoi]==-1){
			cout<<-1;
		}
		else{
			vector<int> res;
			res.push_back(cuoi);
			int a = cuoi;
			while(truoc[a]!=dau){
				res.push_back(truoc[a]);
				a=truoc[a];
			}
			res.push_back(dau);
			for(int i=res.size()-1;i>=0;i--){
				cout<<res[i]<<" ";
			}
		}
		
		
		
		
		
		
		cout<<endl;
	}
	return 0;
}
