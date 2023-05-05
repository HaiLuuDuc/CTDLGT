#include<bits/stdc++.h>
using namespace std;
vector<int> v[10000];
bool daxet[10000];
int n,m,u;
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int x = q.front();  q.pop();
		cout<<x<<" ";
		daxet[x]=true;
		for(int i=0;i<v[x].size();i++){
			int tmp = v[x][i];
			if(daxet[tmp]==false){
				daxet[tmp]=true;
				q.push(tmp);
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<10000;i++){
			daxet[i]=false;
			v[i].clear();
		}
		cin>>n>>m>>u;
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		BFS(u);
		cout<<endl;
	}
	return 0;
}
