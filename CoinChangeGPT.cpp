#include <iostream>
#include <cstring>

using namespace std;

int coin_change(int n, int coins[], int num_coins) {
    int dp[n + 1];
    memset(dp, 0x3f, sizeof(dp)); // initialize all elements to a large value

    dp[0] = 0; // base case: 0 coins needed to make change for 0 cents
	for (int j = 0; j <= n; j++) {
        cout<<dp[j]<<" ";
    }
    cout<<endl;
    for (int i = 1; i <= num_coins; i++) {
        for (int j = coins[i-1]; j <= n; j++) {
            dp[j] = min(dp[j], dp[j-coins[i-1]] + 1);
        }
        for (int j = 0; j <= n; j++) {
            cout<<dp[j]<<" ";
        }
        cout<<endl;
        
    }

    return dp[n];
}

int main() {
    int n = 7;
    int coins[] = {1, 3, 4, 5};
    int num_coins = sizeof(coins) / sizeof(coins[0]);

    int num_coins_needed = coin_change(n, coins, num_coins);

    cout << "Smallest number of coins needed to make change for " << n << " cents: " << num_coins_needed << endl;

    return 0;
}
