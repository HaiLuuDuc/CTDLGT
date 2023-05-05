#include<bits/stdc++.h>
using namespace std;
long long StringToLongLong(string str, int l, int r){
	long long res=0;
	int mu=0;
	for(int i=r;i>=l;i--){
		res = res + (str[i]-'0')*pow(10,mu);
		mu++;
	}
	return res;
}
long long  TongCacXauCon(string str){
	long long  res = 0;
	int length = str.length();
	for(int i=0;i<length;i++){
		//le
		int l=i,r=i;
		while(l>=0 && r<length){
			res+=StringToLongLong(str,l,r);
			l--; r++;
		}
		//chan
		l=i; r=i+1;
		while(l>=0 && r<length){
			res+=StringToLongLong(str,l,r);
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
		cout<<TongCacXauCon(str)<<endl;
	}
	return 0;
}
