#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int k;
int lastArr[1001];
int character[20];
bool Compare(int arr[], int brr[], int k){
	for(int i=1;i<=k;i++){
		if(arr[i]!=brr[i]){
			return false;
		}
	}
	return true;
}
void Sinh(int arr[], int n, int k){
	for(int i=k;i>=1;i--){
		if(arr[i]!=lastArr[i]){
			arr[i]++;
			for(int j=i+1;j<=n;j++){
				arr[j]=arr[j-1]+1;
			}
			break;
		}
	}	
}
void XuLy(int arr[], int n, int k){
	// thiet lap mang character
	for(int i=1;i<=n;i++){
		character[i]=i+64;
	}
	
		// xac dinh lastArr
	lastArr[k]=n;
	for(int i=k-1;i>=1;i--){
		lastArr[i] = lastArr[i+1] -1 ;
	}
	// xac dinh firstArr
	arr[1]=1;
	for(int i=2;i<=k;i++){
		arr[i] = arr[i-1] + 1 ;
	}
	
	while(!Compare(arr,lastArr,k)){
		for(int i=1;i<=k;i++){
			if(arr[i]){
				cout<<(char)character[arr[i]];
			}
		}
		cout<<endl;
		Sinh(arr,n,k);
	}
	for(int i=1;i<=k;i++){
		if(arr[i]){
			cout<<(char)character[arr[i]];
		}
	}
	cout<<endl;
	
	
	
	
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>k;
		XuLy(arr,n,k);
	}
	return 0;
}
