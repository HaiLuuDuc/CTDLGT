#include<bits/stdc++.h>
using namespace std;
int n;
int x[1000];
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void Try(int i, int sum){
	for(int j=x[i-1];j>=1;j--){
		if(sum+j<=n){
			x[i]=j;
			sum+=j;
			if(sum==n){
				XuatMang(x,i);
			}
			else{
				Try(i+1,sum);
			}
			sum-=j;
		}
	}
}
int main(){
	
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		x[0]=n;
		int sum=0;
		Try(1,sum);
	}
	
	
	return 0;
	
}
