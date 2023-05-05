#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+2];
		int dp[n+1];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		arr[n]=arr[n+1]=0;
		for(int i=n-1;i>=0;i--){
			dp[i]=min(arr[i]+dp[i+1],arr[i]+dp[i+2]);
		}
		cout<<min(dp[0],dp[1])<<endl;
	}
	return 0;
}
