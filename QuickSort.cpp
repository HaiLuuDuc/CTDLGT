#include<bits/stdc++.h>
using namespace std;
int tempArr[100];
int n;
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
void QuickSort(int arr[], int left, int right){
	if(left>=right) return;
	else{
		XuatMang(arr,n);
		int mid = (left+right)/2;
		int pivot = arr[mid];
		int index=left;
		// gan cac phan tu nho hon pivot vao tempArr
		for(int i=left;i<=right;i++){
			if(arr[i]<pivot){
				tempArr[index]=arr[i];
				index++;
			}
		}
		// gan pivot vao tempArr
		tempArr[index]=pivot;
		mid = index; //sau khi gan pivot vao tempArr thi vi tri cua pivot != mid nen can update mid
		index++;
		// gan cac phan tu lon hon pivot vao tempArr
		for(int i=left;i<=right;i++){
			if(arr[i]>pivot){
				tempArr[index]=arr[i];
				index++;
			}
		}
		// copy mang tempArr vao mang arr ban dau
		for(int i=left;i<=right;i++){
			arr[i]=tempArr[i];
		}

		QuickSort(arr,left,mid);
		QuickSort(arr,mid+1,right);
	}
}
int main(){
	cin>>n;
	int arr[n];
	NhapMang(arr,n);
	QuickSort(arr,0,n-1);
	XuatMang(arr,n);
	return 0;
}
