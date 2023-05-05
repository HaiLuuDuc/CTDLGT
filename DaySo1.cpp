#include<bits/stdc++.h>
using namespace std;
int arr[100];
void NhapMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
}
void XuatMang(int arr[], int n){
	if(n)cout<<"[";
	for(int i=0;i<n;i++){
		if(i==n-1) cout<<arr[i]<<"]";
		else cout<<arr[i]<<" ";
	}
}
void XuLy(int arr[], int n){
	XuatMang(arr,n);
	while(n--){
		//xuly logic
		cout<<endl;

		for(int i=0;i<n;i++){
			arr[i]+=arr[i+1];
		}
		XuatMang(arr,n);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		NhapMang(arr,n);
		XuLy(arr,n);
	}
	return 0;
}
