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

void SapXep(int arr[], int n){ // 1 2 3 5 4 6 7 8
	int brr[100][100];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				swap(arr[i],arr[j]);
			}
		}
		for(int j=0;j<n;j++){
			brr[i][j]=arr[j];
		}
//		cout<<"Buoc "<<(i+1)<<": ";
//		XuatMang(arr,n);
	}
	for(int i=n-2;i>=0;i--){
		cout<<"Buoc "<<i+1<<": ";
		XuatMang(brr[i],n);
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
		SapXep(arr,n);
	}

	return 0;
}
