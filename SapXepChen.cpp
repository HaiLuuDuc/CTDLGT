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
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){			
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
			else{
				break;
			}
		}
		cout<<"Buoc "<<i<<": ";
		for(int j=0;j<=i;j++){
			cout<<arr[j]<< " ";
		}
		cout<<endl;
	}
}
//void SapXep(int arr[], int n){ // 5 9 8 6 3 1 5 2
//	for(int i=1;i<n;i++){
//		int key = arr[i];
//		for(int j=i-1;j>=0;j--){			
//			if(arr[j]>arr[j+1]){
//				arr[j+1]=arr[j];
//				arr[j]=key;
//			}
//			else{
//				break;
//			}
//		}
//		cout<<"Buoc "<<i<<": ";
//		for(int j=0;j<=i;j++){
//			cout<<arr[j]<< " ";
//		}
//		cout<<endl;
//	}
//}

int main(){
	int n;
	cin>>n;
	int arr[n];
	NhapMang(arr,n);
	cout<<"Buoc "<<0<<": "<<arr[0]<<endl;
	SapXep(arr,n);
	return 0;
}
