#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int dp[100][10000];
		int maxI = (int) sqrt(n);
		for(int i=1;i<=maxI;i++){
			dp[i][0] = 0 ;
		}
		for(int j=0;j<=n;j++){
			dp[1][j] = j ;
		}
		for(int i=2;i<=maxI;i++){
			for(int j=0;j<=n;j++){
				if(i*i>j){
					dp[i][j] = dp[i-1][j];
				}
				else{
					int x = dp[i-1][j];
					int y = dp[i][j-i*i] + 1;
					dp[i][j] = min(x,y);
				}
			}
		}
		
		cout<<dp[maxI][n]<<endl;
	}
	return 0;
}
