#include<bits/stdc++.h>
using namespace std;
bool daxet[10000];
vector<int> v[10000];
int main(){
	int t;
	t=1;
	while(t--){
		for(int i=0;i<10000;i++){
			daxet[i]=false;
			v[i].clear();
		}
		int n,m,x;
		cin>>n>>m>>x;
		while(m--){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		set<int> s[10000];
		int indexx=0;
		for(int i=1;i<=n;i++){
			if(daxet[i]==false){
				s[indexx].insert(i);
				for(int j=0;j<v[i].size();j++){
					if(daxet[v[i][j]]==false){
						s[indexx].insert(v[i][j]);
						daxet[v[i][j]] = true;
					}
				}
			}
			indexx++;
		}
//		for(int i=0;i<indexx;i++){
//			set<int>::iterator it;
//			for(it=s[i].begin();it!=s[i].end();it++){
//				cout<<(*it)<<" ";
//			}
//			cout<<endl;
//		}
		int vitri;
		for(int i=0;i<indexx;i++){
			set<int>::iterator it;
			for(it=s[i].begin();it!=s[i].end();it++){
				int tmp = (*it);
				if(tmp==x){
					vitri=i;
					goto label;
				}
			}
		}
		label:;
		bool isok=false;
		vector<int> abc;
		for(int i=0;i<indexx;i++){
			if(i==vitri){
				continue;
			}
			set<int>::iterator it;
			for(it=s[i].begin();it!=s[i].end();it++){
				isok=true;
				int tmp = (*it);
				abc.push_back(tmp);
			}
		}
		
		if(!isok){
			cout<<0<<endl;
		}
		else{
			sort(abc.begin(),abc.end());
			for(int i=0;i<abc.size();i++){
				cout<<abc[i]<<endl;
			}
		}
		
		
		
		
		
		
		
		
		
		
	}
	return 0;
}
