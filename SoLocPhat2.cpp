#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> v;
		string str;
		queue<string> q;
		q.push("6");
		q.push("8");
		while(true){
			string s = q.front();
			if(s.length()>n){
				break;
			}
			q.pop();
			v.push_back(s);
			q.push(s+"6");
			q.push(s+"8");
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
