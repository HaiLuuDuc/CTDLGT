#include<bits/stdc++.h>
using namespace std;
int lastArr[10000];	
int currentArr[10000];
int k;
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
	cout<<endl;
}
bool Check(int arr[], int n, int k){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(arr[i]){
			sum++;
		}
	}
	if(sum==k)
	return true;
	return false;
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
		currentArr[i]=0;
	}
	while(!Compare(currentArr,lastArr,n)){
		if(Check(currentArr,n,k)) XuatMang(currentArr,n);
		Sinh(currentArr,n);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>k;
		XuLy(n);
	}
	return 0;
}
