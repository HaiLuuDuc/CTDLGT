#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		int dp[n+2]={0};
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		arr[n]=0;
		dp[n-1]=arr[n-1];
		for(int i=n-2;i>=0;i--){
			if(i==0){
				dp[i]=max(dp[i+1],arr[i]+dp[i+2]);
			}
			else{
				dp[i]=max(dp[i+1],arr[i]+dp[i+2]);	
			} 
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}
