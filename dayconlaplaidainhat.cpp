#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin.ignore();
		string str;
		cin>>str;
		map<char,int> mp;
		for(int i=0;i<n;i++){
			mp[str[i]]++;
		}
		int maxx=0;
		map<char,int>::iterator it;
		for(it=mp.begin(); it!=mp.end();it++){
			if((*it).second-1>maxx){
				maxx=(*it).second-1;
			}
		}
		cout<<maxx<<endl;
		
		
	}
	return 0;
}
