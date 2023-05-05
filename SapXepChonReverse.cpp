#include<bits/stdc++.h>
using namespace std;
void NhapMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
}
void XuatMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}	
	cout<<endl;
}

void SapXep(int arr[], int n){ // 5 9 8 6 3 1 5 2
	int brr[100][100];
	int minIndex;
	int min;
	for(int i=0;i<n-1;i++){
		min=arr[i];
		minIndex = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<min){
				min = arr[j];
				minIndex=j;
			}
		}
		swap(arr[i],arr[minIndex]);
		for(int j=0;j<n;j++){
			brr[i][j]=arr[j];
		}
//		cout<<"Buoc "<<i+1<<": ";
//		XuatMang(arr,n);
	}	
	for(int i=n-2;i>=0;i--){
		cout<<"Buoc "<<i+1<<": ";
		XuatMang(brr[i],n);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	NhapMang(arr,n);
	SapXep(arr,n);
	return 0;
}
