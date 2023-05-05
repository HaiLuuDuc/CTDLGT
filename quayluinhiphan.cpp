#include<bits/stdc++.h>
using namespace std;
int n;
int x[1000];
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void quaylui(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n){
			XuatMang(x,i);
		}
		else{
			quaylui(i+1);
		}
	}
}
int main(){
	cin>>n;
	quaylui(1);
	return 0;
}
