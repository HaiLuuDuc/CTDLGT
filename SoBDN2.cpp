#include<bits/stdc++.h>
using namespace std;
//bool lonhon(string a, string b){
//	if(a.length()>b.length()){
//		return true;
//	}
//	else if(a.length()<b.length()){
//		return false;
//	}
//	else{
//		return (a>b);
//	}
//}
long long tolonglong(string str){
	long long res = 0;
	int mu = 0;
	for(int i=str.length()-1;i>=0;i--){
		res += (str[i]-'0')*pow(10,mu);
		mu++;
	}
	return res;
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		vector<string> v;
		queue<string> q;
		int n;
		cin>>n;
		q.push("1");
		while(true){
			string s = q.front();
			q.pop();
			long long bdn = tolonglong(s);
			if(bdn%n==0){
				cout<<bdn;
				break;
			}
			q.push(s+"0");
			q.push(s+"1");
		}
		cout<<endl;
	}
	return 0;
}
