#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,maxWeight;
		cin>>n>>maxWeight;
		int value[n+1],weight[n+1];
		for(int i=1;i<=n;++i){
			cin>>weight[i];
		}
		for(int i=1;i<=n;++i){
			cin>>value[i];
		}
		int dp[n+1][maxWeight+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=maxWeight;j++){
				dp[i][j] = 0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=maxWeight;j++){
				if(weight[i]>j){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
				}
			}
		}
		cout<<dp[n][maxWeight]<<endl;
//		for(int i=0;i<=n;i++){
//			for(int j=0;j<=maxWeight;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		
		
		
		
		
		
	}
	return 0;
}
