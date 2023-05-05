#include<bits/stdc++.h>
using namespace std;
int arr[10000];	
void XuatMang(int arr[], int n){
	cout<<"(";
	for(int i=0;i<n;i++){
		if(arr[i+1]&&arr[i+2]!=0) cout<<arr[i+1]<<" ";
		else if(arr[i+1]&&arr[i+2]==0) cout<<arr[i+1];
	}
	cout<<") ";
}
void Sinh(int arr[], int n, int &count){
	count++;
	int sum=1;
	for(int i=n;i>=1;i--){
		if(arr[i]>1){
			
			// giam arr[i]
			arr[i]--;
			// gan cac phan tu phia sau arr[i] bang 0
			for(int j=i+1;j<=n;j++){
				arr[j]=0;
			}
			// bay tong ra cac vi tri phia sau
			int div = sum / arr[i];
			int mod = sum % arr[i];
			int j=i;
			while(div--){
				++j;
				arr[j]=arr[i];
			}
			++j;
			arr[j]=mod;
			break;
		}
		else{
			// tinh tong con lai
			sum+=arr[i]; 
		}
	}
}
void XuLy(int n){
	int count=1;
	arr[1]=n;
	while(arr[1]!=1){
		XuatMang(arr,n);
		Sinh(arr,n,count);
	}
	XuatMang(arr,n);
	cout<<count<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<1000;i++){
			arr[i]=0;
		}
		int n;
		cin>>n;
		XuLy(n);
		cout<<endl;
	}
	return 0;
}
