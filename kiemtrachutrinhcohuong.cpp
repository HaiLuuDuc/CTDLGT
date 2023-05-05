#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > dske;
vector<bool> daxet;
vector<int> truoc;
bool iscochutrinh;

void resetdske(){
	dske.clear();
	dske.resize(n+1);
}

void resetdaxet(){
	daxet.clear();
	daxet.resize(n+1,false);
}

void resettruoc(){
	truoc.clear();
	truoc.resize(n+1,0);
}

void dfs(int u){
	daxet[u]=true;
	for(int i=0;i<dske[u].size();i++){
		int tmp = dske[u][i];
		if(daxet[tmp]==false){
			dfs(tmp);
		}
		if(daxet[tmp]==true){
			iscochutrinh=true;
			return;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		resetdske();
		resetdaxet();
		resettruoc();
		while(m--){
			int x,y;
			cin>>x>>y;
			dske[x].push_back(y);
		}
		
		iscochutrinh=false;
		for(int i=1;i<=n;i++){
			resetdaxet();
			resettruoc();
			if(daxet[i]==false && iscochutrinh==false){
				dfs(i);
			}
		}
		
		if(iscochutrinh){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		
	
		
		
		cout<<endl;
	}
	return 0;
}
