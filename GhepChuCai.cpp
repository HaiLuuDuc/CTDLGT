#include<bits/stdc++.h>
using namespace std;
char c;
int k;
int length;
char collection[100];
char x[100];
bool daxet[1000];
void XuatMang(char arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
	cout<<endl;
}//                     1   2    3   4
bool NguyenAmKhongBiKep(char arr[], int n){
	for(int i=1;i<=n;i++){
		if(arr[i]=='A'){
			if(i>1 && i<n){
				if(arr[i-1]!='E' && arr[i+1]!='E'){
					return false;
				}
			}
		}
		else if(arr[i]=='E'){
			if(i>1 && i<n){
				if(arr[i-1]!='A' && arr[i+1]!='A'){
					return false;
				}
			}
		}
	}
	return true;
}
void quaylui(int i){
	for(int j=1;j<=k;j++){
		if(daxet[j]==false){
			x[i]=(char)((int)'A' + j - 1);
			daxet[j]=true;
			if(i==k){
				if(NguyenAmKhongBiKep(x,i)){
					XuatMang(x,i);
				}
			}
			else{
				quaylui(i+1);
			}
			daxet[j]=false;
		}
	}
}
int main(){ 
	for(int i=0;i<999;i++){
		daxet[i]=false;
	}
	cin>>c;
	length = c-'A'+1;
	k = length;
	for(int i=1;i<=length;i++){
		collection[i]= (char)((int)'A' + i - 1);
	}
	quaylui(1);
	return 0;
}
