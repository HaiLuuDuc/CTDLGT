#include<bits/stdc++.h>
using namespace std;
void NhapMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
}
int BinarySearch(int arr[], int left, int right, int x){
	if(left<=right){
		int mid = (left+right)/2;
		if(arr[mid]==x){
			return mid;
		}
		else if(x>arr[mid]){
			return BinarySearch(arr,mid+1,right,x);
		}
		else if(x<arr[mid]){
			return BinarySearch(arr,left,mid-1,x);
		}
	}
	else return -1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int x;
		cin>>n>>x;
		int arr[n];
		NhapMang(arr,n);
		if(BinarySearch(arr,0,n-1,x)>=0) cout<<1;
		else cout<<-1;
		cout<<endl;
	}
	return 0;
}
