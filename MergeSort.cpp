#include<bits/stdc++.h>
using namespace std;
int tempArr[1000000];
void NhapMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
}
void XuatMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void Merge(int arr[], int left, int mid, int right){
	int i=left,j=mid+1;
	int index=left;
	while(i<=mid&&j<=right){
		if(arr[i]<arr[j]){
			tempArr[index]=arr[i];
			i++;
		}
		else if(arr[i]>=arr[j]){
			tempArr[index]=arr[j];
			j++;
		}
		index++;
	}
	while(i<=mid){
		tempArr[index]=arr[i];
		index++;
		i++;
	}
	while(j<=right){
		tempArr[index]=arr[j];
		index++;
		j++;
	}
	for(int i=left;i<=right;i++){
		arr[i]=tempArr[i];
	}
}
void MergeSort(int arr[], int left, int right){
	if(left>=right) return;
	else{
		int mid = (left+right)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);
		Merge(arr,left,mid,right);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		NhapMang(arr,n);
		MergeSort(arr,0,n-1);
		XuatMang(arr,n);
	}
	return 0;
}
