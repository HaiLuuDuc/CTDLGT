#include<bits/stdc++.h>
using namespace std;
int PalindromSubstrings(string str){
	int res = 0;
	int length = str.length();
	for(int i=0;i<length;i++){
		//le
		int l=i,r=i;
		while(l>=0 && r<length && str[l]==str[r]){
			res+=1;
			l--; r++;
		}
		//chan
		l=i; r=i+1;
		while(l>=0 && r<length && str[l]==str[r]){
			res+=1;
			l--; r++;
		}
	}
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin.ignore();
		cin>>str;
		cout<<PalindromSubstrings(str)<<endl;
	}
	return 0;
}
