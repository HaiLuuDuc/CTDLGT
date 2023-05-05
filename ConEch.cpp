#include <iostream>
#include <vector>

using namespace std;

int countWays(int n) {
    int dp[n+1] = {0};
    dp[0] = 1; // There is only one way to reach 0 steps (i.e. don't move)

    // For each number of steps i, compute the number of ways to reach that step
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3 && j <= i; j++) {
            dp[i] += dp[i-j];
        }
    }
	for(int i=0;i<=n;i++){
		cout<<dp[i]<<" ";
	}
    return dp[n];
}

int main() {
    int n = 5;
    cin>>n;
    cout << "Number of ways to reach " << n << " steps: " << countWays(n) << endl;
    return 0;
}
