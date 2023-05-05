#include<bits/stdc++.h>
using namespace std;
int lastArr[10000];	
int currentArr[10000];
int arr[10000];
int k;
void NhapMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
}
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
bool Check(int currentArr[], int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(currentArr[i]==1){
			sum += currentArr[i] * arr[i];
		}
	}
	if(sum==k)return true;
	else return false;
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
	int count = 0;
	for(int i=1;i<=n;i++){
		lastArr[i]=1;
	}
	for(int i=1;i<=n;i++){
		currentArr[i]=0;
	}
	while(!Compare(currentArr,lastArr,n)){
		if(Check(currentArr,n)){
			count++;
			for(int i=1;i<=n;i++){
				if(currentArr[i]){
					cout<<arr[i]<<" ";
				}
			}
			cout<<endl;
		} 
		Sinh(currentArr,n);
	}
	if(Check(currentArr,n)){
		count++;
		for(int i=1;i<=n;i++){
			if(currentArr[i]){
				cout<<arr[i]<<" ";
			}
		}
		cout<<endl;
	} 
	cout<<count<<endl;
}
int main(){
	int t;
	t=1;
	while(t--){
		int n;
		cin>>n;
		cin>>k;
		NhapMang(arr,n);
		XuLy(n);
	}
	return 0;
}
