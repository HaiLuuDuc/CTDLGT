#include<bits/stdc++.h>
using namespace std;
vector<bool> daxet;
vector<vector<int> > v;
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
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		//in ra danh sach ke
//		for(int i=1;i<=n;i++){
//			cout<<i<<": ";
//			for(int j=0;j<v[i].size();j++){
//				cout<<v[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		int count=0;
		for(int i=1;i<=n;i++){
			if(daxet[i]==false){
				count++;
				DFS(i);
			}
		}
		//neukhonglienthong
		if(count>1){
			cout<<0;
		}
		//neulienthong
		else{
			daxet.clear(); daxet.resize(n+9,false);
			bool iscoduongdi = false;
			bool iscochutrinh = false;
			int sodinhbacle = 0;
			for(int i=1;i<=n;i++){
				if(v[i].size()%2==1){
					sodinhbacle++;
				}
			}
			if(sodinhbacle==2){
				cout<<1;
			}
			else if(sodinhbacle==0){
				cout<<2;
			}
			else{
				cout<<0;
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		cout<<endl;
	}
	return 0;
}
