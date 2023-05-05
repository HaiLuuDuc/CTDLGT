#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> parent;
class canh{
	public:
		int dau;
		int cuoi;
		int trongso;
};
vector<canh> dscanh;
void XuatDscanh(){
	for(int i=0;i<m;i++){
		cout<<dscanh[i].dau<<" "<<dscanh[i].cuoi<<" "<<dscanh[i].trongso<<endl;
	}
}
void ResetParent(){	
	parent.clear();	
	parent.resize(n+1);
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
}
void ResetDscanh(){	
	dscanh.clear();
	dscanh.resize(m+1);
}
int Find(int u){
	if(parent[u]!=u){
		return parent[u] = Find(parent[u]);
	}
	return parent[u];
}
int Union(int a, int b){
	int A = Find(a);
	int B = Find(b);
	if(A==B){
		return 0;
	}
	parent[B]=A;
	return 1;
}
bool cmp(canh a, canh b){
	return a.trongso<b.trongso;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ResetParent();
		ResetDscanh();
		//nhap dscanh
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			canh tmpCanh;
			tmpCanh.dau=x;
			tmpCanh.cuoi=y;
			tmpCanh.trongso=z;
			dscanh.push_back(tmpCanh);
		}

		sort(dscanh.begin()+1,dscanh.end(),cmp);
		
		int sum = 0;
		
		for(int i=0;i<dscanh.size();i++){
			int a = dscanh[i].dau;
			int b = dscanh[i].cuoi;
			if(Union(a,b)){
				Union(a,b);
				sum+=dscanh[i].trongso;
			}
		}
		
		cout<<sum;

		
		
		
		cout<<endl;
	}
	return 0;
}
