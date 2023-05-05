#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int lastArr[1001];
int firstArr[1001];
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
bool Compare(int arr[], int brr[], int n){
	for(int i=1;i<=n;i++){
		if(arr[i]!=brr[i]){
			return false;
		}
	}
	return true;
}
void Sinh(int arr[], int n){
	
	//- duyet tu cuoi len dau, neu arr[i]<arr[i+1] thi doi cho
	//arr[i] cho so be nhat lon hon arr[i]
	//- sort phia sau
	//
	for(int i=n-1;i>=1;i--){
		if(arr[i]<arr[i+1]){
			for(int j=n;j>=i+1;j--){
				if(arr[j]>arr[i]){
					swap(arr[i],arr[j]);
					break;
				}
			}
			sort(arr+i+1,arr+n+1);
			
			
			break;
		}
	}

}
void XuLy(int arr[], int n){
	// xac dinh lastArr
	for(int i=n;i>=1;i--){
		lastArr[n-i+1]=i;
	}
	// xac dinh firstArr
	for(int i=1;i<=n;i++){
		firstArr[i]=i;
	}
	
	if(Compare(arr,lastArr,n)==true){
		XuatMang(firstArr,n);
	}
	else{
		Sinh(arr,n);
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
