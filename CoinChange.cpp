#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,s;
		cin>>n>>s;
		int arr[n+1];
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		int dp[n+1][s+1];
		for(int i=0;i<=n;i++){
			dp[i][0] = 0;
		}
		for(int j=0;j<=s;j++){
			dp[0][j] = 0;
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s;j++){
				dp[i][j] = min(dp[i-1][j-arr[i]]+arr[i], j/arr[i]);
			}
		}
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=s;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		
		
	}
	return 0;
}
