#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int dp[n+1][m+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i][j]=0;
			}
		}
		int arr[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>arr[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(arr[i][j]==1){
					if(dp[i-1][j]>0 && dp[i][j-1]>0){
						dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1;
					}
					else{
						dp[i][j] = 1;
					}
				}
			}
		}
		int maxx = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][j]>maxx){
					maxx=dp[i][j];
				}
			}
		}
		cout<<maxx<<endl;
		
	}
	return 0;
}
