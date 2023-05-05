#include<bits/stdc++.h>
using namespace std;
bool lonhon(string a, string b){
	if(a.length()>b.length()){
		return true;
	}
	else if(a.length()<b.length()){
		return false;
	}
	else{
		return (a>b);
	}
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		vector<string> v;
		queue<string> q;
		string str;
		cin>>str;
		q.push("1");
		while(true){
			string s = q.front();
			q.pop();
			if(!lonhon(s,str)) {
				v.push_back(s);	
			}
			else{
				break;
			}
			q.push(s+"0");
			q.push(s+"1");
		}
		cout<<v.size();
//		for(int i=0;i<v.size();i++){
//			cout<<v[i]<<" ";
//		}
		cout<<endl;
	}
	return 0;
}
