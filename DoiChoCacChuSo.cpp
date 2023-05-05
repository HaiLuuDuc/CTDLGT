#include<bits/stdc++.h>
using namespace std;
void XepMaxLenDau(string str, int start, int end){
	char maxchar = str[start];
	int vitri = start;
	for(int i=start;i<=end;i++){
		if(str[i]>maxchar){
			maxchar=str[i];
			vitri = i;
		}
	}
	swap(str[vitri],str[start]);
}
void xuly(int k, string str){	
	int length = str.length();
	string maxstring = str;
	sort(maxstring.end(),maxstring.begin());
	cout<<maxstring;
	int maxx = length/2;
	if(k>=maxx){
		cout<<maxstring;
	}
	else while(k--){
		for(int i=0;i<length;i++){
			if(str[i]!=maxstring[i]){
				XepMaxLenDau(str, i,length-1);
			}
		}
	}
	cout<<str;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		cin.ignore();
		string str;
		cin>>str;
		xuly(k, str);
		cout<<endl;
	}
	return 0;
}
