#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[1000];
int x[1000];
int y[1000];
void CopyMang(int x[], int y[], int n){
	for(int i=1;i<=n;i++){
		y[i] = arr[x[i]];
	}
}
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void quaylui(int i){
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if(i==k){
			CopyMang(x,y,i);
			XuatMang(y,i);
		}
		else{
			quaylui(i+1);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		x[0]=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		sort(arr+1,arr+1+n);
		quaylui(1);
	}
	return 0;
}
