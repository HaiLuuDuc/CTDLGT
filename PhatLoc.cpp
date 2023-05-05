#include<bits/stdc++.h>
using namespace std;
int lastArr[10000];	
int arr[10000];
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		if(arr[i]){
			cout<<8;
		}
		else cout<<6;
	}
	cout<<endl;
}
bool CheckFirstLast(int arr[], int n){
	if(arr[1]!=1){
		return false;		
	}
	if(arr[n]!=0){
		return false;
	}
	return true;
}
bool Check2(int arr[], int n){
	for(int i=1;i<n;i++){
		if(arr[i]==1&&arr[i+1]==1){
			return false;
		}
	}
	return true;
}
bool Check3(int arr[], int n){
	for(int i=1;i<n-2;i++){
		if(arr[i]==0&&arr[i+1]==0&&arr[i+2]==0&&arr[i+3]==0){
			return false;
		}
	}
	return true;
}
bool Compare(int arr[], int brr[], int n){
	for(int i=1;i<=n;i++){
		if(arr[i]!=brr[i]){
			return false;
		}
	}
	return true;
}
void Sinh(int arr[], int n){
	for(int i=n;i>=1;i--){
		if(arr[i]==0){
			arr[i]=1;
			for(int j=i+1;j<=n;j++){
				arr[j]=0;
			}
			break;
		}
	}
}
void XuLy(int n){
	for(int i=1;i<=n;i++){
		lastArr[i]=1;
	}
	for(int i=1;i<=n;i++){
		arr[i]=0;
	}
	while(!Compare(arr,lastArr,n)){
		if(CheckFirstLast(arr,n)&&Check2(arr,n)&&Check3(arr,n)) {
			XuatMang(arr,n);
		}
		
		Sinh(arr,n);
	}
}
int main(){
	int t;
	t=1;
	while(t--){
		int n;
		cin>>n;
		XuLy(n);
	}
	return 0;
}
