#include<bits/stdc++.h>
using namespace std;
int lastArr[10000];	
int currentArr[10000];
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
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
		for(int i=1;i<=n;i++){
			if(currentArr[i]){
				cout<<"B";
			}
			else{
				cout<<"A";
			}
		}
		cout<<" ";
		Sinh(currentArr,n);
	}
	for(int i=1;i<=n;i++){
		if(currentArr[i]){
			cout<<"B";
		}
		else{
			cout<<"A";
		}
	}
	cout<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		XuLy(n);
		cout<<endl;
	}
	return 0;
}
