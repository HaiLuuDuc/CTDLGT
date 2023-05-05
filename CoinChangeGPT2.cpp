#include <bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int amount) {
    int dp[n+1][amount+1];
    // Initialize DP matrix
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=amount; j++) {
            if(j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INT_MAX-1;
            }
        }
    }
    // Calculate values for DP matrix
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=amount; j++) {
            if(coins[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
            }
        }
    }
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=amount;j++){
    		cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
    return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
}

int main() {
    int coins[] = {1, 3, 4, 5};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 7;
    cout << coinChange(coins, n, amount) << endl;
    return 0;
}
