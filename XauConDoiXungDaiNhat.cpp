//2
//abcbadd  5
//aaaaa    5
#include<bits/stdc++.h>
using namespace std;
int MaxLength(string str){
	int length = str.length();
	int maxLength = 0;
	for(int i=0;i<length;i++){
		int l,r;
		//le
		l=i; r=i;
		while(l>=0 && r<length && str[l]==str[r]){
			if(r-l+1 > maxLength){
				maxLength = r-l+1;
			}
			l--; r++;
		}
		//chan
		l=i; r=i+1;
		while(l>=0 && r<length && str[l]==str[r]){
			if(r-l+1 > maxLength){
				maxLength = r-l+1;
			}
			l--; r++;
		}
	}
	return maxLength;
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string str;
		cin>>str;
		cout<<MaxLength(str)<<endl;
	}
	return 0;
}
