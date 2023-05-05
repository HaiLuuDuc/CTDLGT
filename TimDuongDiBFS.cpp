#include<bits/stdc++.h>
using namespace std;
int n,m;
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
				truoc[adj[x][i]] = x;
			}
		}
	}
}
int main(){
	memset(visited,false,sizeof(visited));
	memset(truoc,0,sizeof(truoc));
	input();
	int s,t;
	cin>>s>>t;
	BFS(s);
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
