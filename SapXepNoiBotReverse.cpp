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
	int count=0;
	int brr[100][100];
	for(int i=0;i<n;i++){
		isDone=true;
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				isDone = false;
			}
		}
		if(isDone) goto label;
		count++;
		for(int j=0;j<n;j++){
			brr[i][j]=arr[j];
		}
//		cout<<"Buoc "<<(i+1)<<": ";
//		XuatMang(arr,n);
	}
	label:
	for(int i=count-1;i>=0;i--){
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
