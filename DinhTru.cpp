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
	int stplt = 0;
	memset(visited,false,sizeof(visited));
	input();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			stplt++;
			DFS(i);
		}
	}
	// bay gio ta da tinh duoc stplt ban dau

	for(int i=1;i<=n;i++){
		memset(visited,false,sizeof(visited));
		visited[i] = true;  //tat dinh tru
		int count = 0;
		for(int j=1;j<=n;j++){
			if(!visited[j]){
				count++;
				DFS(j);
			}
		}
		cout<<count<<" ";
	}
	
	
	//cout<<stplt<<endl;
	return 0;
}
