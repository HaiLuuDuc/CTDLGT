#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> adj[1001];
bool visited[1001];
vector< pair<int,int> > vectorcanh;
void input(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x); // neu la do thi co huong thi k co dong nay
		vectorcanh.push_back({x,y});
	}
}
void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 0; i < adj[x].size(); i++){
			if(!visited[adj[x][i]]){
				visited[adj[x][i]] = true;
				q.push(adj[x][i]);
			}
		}
	}
}
void BFS2(int u, int s, int t){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 0; i < adj[x].size(); i++){
			if(!visited[adj[x][i]] && !((x==s&&i==t)||(x==t&&i==s))){
				visited[adj[x][i]] = true;
				q.push(adj[x][i]);
			}
		}
	}
}
int main(){
	int stplt = 0;
	memset(visited,false,sizeof(visited));
	input();
	//dem stplt
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			stplt++;
			BFS(i);
		}
	}
	for(int i=0;i<vectorcanh.size();i++){
		//tat canh cau
		int x = vectorcanh[i].first;
		int y = vectorcanh[i].second;
		for(int j=1;j<=m;j++){
			BFS2(1,x,y);
		}
	}
	return 0;
}
