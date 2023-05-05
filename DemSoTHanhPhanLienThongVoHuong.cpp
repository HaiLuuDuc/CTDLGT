#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> adj[1001];
bool visited[1001];
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
			DFS(adj[u][i]);
		}
	}
}
int main(){
	int count = 0;
	memset(visited,false,sizeof(visited));
	input();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			count++;
			cout<<"count++ at "<<i<<endl;;
			DFS(i);
		}
	}
	cout<<count<<endl;
	return 0;
}
