#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,maxweight;
	cin>>n>>maxweight;
	int weight[n+1];
	int value[n+1];
	int dp[n+1][maxweight+1];
	for(int i=1;i<=n;i++){
		cin>>weight[i];
		cin>>value[i];
	}
	for(int j=0;j<=maxweight;j++){
		dp[0][j] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxweight;j++){
			if(j<weight[i]){
				dp[i][j]=dp[i-1][j];
			}
			else
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
		}
	}
	cout<<dp[n][maxweight];
	return 0;
}
