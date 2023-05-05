#include<bits/stdc++.h>
using namespace std;
// 012345678
// 1001010

bool check(string str,int l,int r){
	while(l<r){
		if(str[l]!=str[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}
int main(){
	string str;
	cin>>str;
	int m;
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		if(check(str,l-1,r-1)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
