#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > G;
vector<int> truoc;
int n,m,dau,cuoi;
bool isok;
void DFS2(int u){
	daxet[u] = true;
	for(int i=0;i<G[u].size();i++){
		int tmp = G[u][i];
		if(daxet[tmp]==false){
			truoc[tmp]=u;
			if(tmp==cuoi){
				isok=true;
				return;
			}
			DFS2(tmp);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>dau>>cuoi;
		G.clear(); G.resize(n + 1);
   	 	daxet.clear(); daxet.resize(n + 1, false);
    	truoc.clear(); truoc.resize(n + 1, -1);
		while(m--){
			int x,y;
			cin>>x>>y;
			G[x].push_back(y);
		}
		
		isok = false;
		DFS2(dau);
		
		//truong hop k co duong di
		if(isok == false){
			cout<<-1<<endl;
			continue;
		}
		//truong hop co duong di
		vector<int> result;
		result.push_back(cuoi);
		int a=cuoi;
		while(truoc[a]!=dau){
			result.push_back(truoc[a]);
			a=truoc[a];
		}
		result.push_back(dau);
		
		//in ket qua
		for(int i=result.size()-1;i>=0;i--){
			cout<<result[i]<<" ";
		}
		
		
		
		cout<<endl;
	}
	return 0;
}
