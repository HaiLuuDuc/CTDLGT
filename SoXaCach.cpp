#include<bits/stdc++.h>
using namespace std;
int n;
bool daxet[1000];
int x[1000];
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
	cout<<endl;
}
bool CheckHieu(int arr[], int n){
	for(int i=1;i<n;i++){
		if(abs(arr[i]-arr[i+1])==1){
			return false;
		}
	}
	return true;
}
void quaylui(int i){
	for(int j=1;j<=n;j++){
		if(daxet[j]==false){
			x[i]=j;
			daxet[j]=true;
			if(i==n){
				if(CheckHieu(x,i))
				XuatMang(x,i);
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
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		quaylui(1);
	}	
	return 0;
}
