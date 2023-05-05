#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
vector<pair<int,int> > dscanh;
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
void canhcau(int u, int s, int t){
	daxet[u] = true;
	for(int i=0;i<v[u].size();i++){
		int tmp = v[u][i];
		if((u==s&&tmp==t)||(u==t&&tmp==s)){
			continue;
		}
		if(daxet[tmp]==false){
			canhcau(tmp,s,t);
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
		dscanh.clear();
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
			dscanh.push_back({x,y});
		}
		
		for(int i=0;i<dscanh.size();i++){
			int x = dscanh[i].first;
			int y = dscanh[i].second;
			//demsothanhphanlienthongtruoc
			daxet.clear(); daxet.resize(n+9,false);
			int count = 0;
			for(int i=1;i<=n;i++){
				if(daxet[i]==false){
					count++;
					DFS(i);
				}
			}
			//canhcau function
			daxet.clear(); daxet.resize(n+9,false);
			int count2 = 0;
			for(int i=1;i<=n;i++){
				if(daxet[i]==false){
					count2++;
					canhcau(i,x,y);
				}
			}
		
			if(count!=count2){
				cout<<x<<" "<<y<<" ";
			}

		}
		
		
		
		
		
		
		cout<<endl;
	}
	return 0;
}
