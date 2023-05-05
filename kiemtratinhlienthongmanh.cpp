#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
int n,m,u;

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
		v.clear();  v.resize(n+9);
		daxet.clear();  daxet.resize(n+9,false);
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
		}

		for(int h=1;h<=n;h++){
			daxet.clear();  daxet.resize(n+9,false);
			DFS(h);
			int count=1;
			for(int i=1;i<=n&&i!=h;i++){
				if(daxet[i]==false){
					DFS(i);
					count++;
				}
			}
			if(count>1){
				cout<<"NO";
				goto label;
			}
		}
		cout<<"YES";
		label:;
		cout<<endl;
	}
	return 0;
}
