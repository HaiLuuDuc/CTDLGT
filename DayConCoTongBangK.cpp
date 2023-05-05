#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int x[10000];
int arr[10000];
int currentSum=0;
void NhapMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
}
void XuatMang(int arr[], int n){
	cout<<"[";
	for(int i=1;i<=n;i++){
		if(i==n){
			cout<<arr[i];
			continue;
		}
		cout<<arr[i]<<" ";
	}
	cout<<"]";
}
void Try(int i){
	for(int j=i;j<=n;j++){
		if(arr[j]>x[i-1]&&currentSum+arr[j]<=k){
			x[i]=arr[j];
			currentSum+=arr[j];
			if(currentSum==k){
				XuatMang(x,i);
			}
			else
			{
				Try(i+1);
			}
			currentSum-=arr[j];
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>k;
		NhapMang(arr,n);
		sort(arr,arr+n);
		x[0] = -100;
		::currentSum=0;
		Try(1);
		cout<<endl;
	}
	return 0;
}
