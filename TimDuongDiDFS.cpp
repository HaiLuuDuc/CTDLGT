#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector <int> adj[1001];
bool visited[1001];
int truoc[1001];
void input(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x); // neu la do thi co huong thi k co dong nay
	}
}
void DFS(int u){
	visited[u] = true;
	for(int i = 0; i < adj[u].size(); i++){
		if(!visited[adj[u][i]]){
			truoc[adj[u][i]] = u;
			DFS(adj[u][i]);
		}
	}
}
int main(){
	memset(visited,false,sizeof(visited));
	memset(truoc,0,sizeof(truoc));
	input();
	cin>>s>>t;
	DFS(s);
	if(visited[t]){
		int x = t;
		while(truoc[x]!=0){
			cout<<x<<" ";
			x=truoc[x];		
		}
		if(x==s){
			cout<<s<<endl;
		}
	}
	else{
		cout<<"Khong co duong di "<<endl;
	}
	return 0;
}
