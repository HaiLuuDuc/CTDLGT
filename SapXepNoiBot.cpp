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
	bool isDone;
	for(int i=0;i<n;i++){
		isDone=true;
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				isDone = false;
			}
		}
		if(isDone) return;
		cout<<"Buoc "<<(i+1)<<": ";
		XuatMang(arr,n);
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
