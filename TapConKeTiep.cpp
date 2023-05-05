#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int lastArr[1001];
int firstArr[1001];
void NhapMang(int arr[], int k){
	for(int i=1;i<=k;i++){
		cin>>arr[i];
	}
}
void XuatMang(int arr[], int k){
	for(int i=1;i<=k;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
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
	// xac dinh lastArr
	lastArr[k]=n;
	for(int i=k-1;i>=1;i--){
		lastArr[i] = lastArr[i+1] -1 ;
	}
	// xac dinh firstArr
	firstArr[1]=1;
	for(int i=2;i<=k;i++){
		firstArr[i] = firstArr[i-1] + 1 ;
	}
	
	if(Compare(arr,lastArr,k)==true){
		XuatMang(firstArr,k);
	}
	else{
		Sinh(arr,n,k);
		XuatMang(arr,k);
	}
	
	
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int k;
		cin>>n>>k;
		NhapMang(arr,k);
		XuLy(arr,n,k);
	}
	return 0;
}
