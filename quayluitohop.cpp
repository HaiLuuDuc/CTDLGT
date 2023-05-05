#include<bits/stdc++.h>
using namespace std;
int n,k;
int x[1000];
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
			XuatMang(x,i);
		}
		else{
			quaylui(i+1);
		}
	}
}
int main(){
	x[0]=0;
	cin>>n>>k;
	quaylui(1);
	return 0;
}
