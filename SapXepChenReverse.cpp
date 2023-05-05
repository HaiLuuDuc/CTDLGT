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
	for(int i=1;i<n;i++){
		int key = arr[i];
		for(int j=i-1;j>=0;j--){			
			if(arr[j]>arr[j+1]){
				arr[j+1]=arr[j];
				arr[j]=key;
			}
			else{
				break;
			}
		}
		for(int j=0;j<n;j++){
			brr[i][j]=arr[j];
		}
	}
	for(int i=n-1;i>=1;i--){
		cout<<"Buoc "<<i<<": ";
		for(int j=0;j<=i;j++){
			cout<<brr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	NhapMang(arr,n);
	int x=arr[0];
	SapXep(arr,n);
	cout<<"Buoc "<<0<<": "<<x<<endl;
	return 0;
}
