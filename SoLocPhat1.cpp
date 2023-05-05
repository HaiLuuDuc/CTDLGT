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
		for(int i=v.size()-1;i>=0;i--){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
