#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    
    // dp[i][j] stores the maximum total weight of cows that can be taken with a capacity of j,
    // using only the cows from 0 to i (inclusive).
    vector<vector<int> > dp(N, vector<int>(C+1, 0));
    
    for (int j = w[0]; j <= C; j++) {
        dp[0][j] = w[0];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= C; j++) {
            // If cow i is not taken, then dp[i][j] is the same as dp[i-1][j].
            dp[i][j] = dp[i-1][j];
            
            // If cow i is taken, then dp[i][j] is the maximum of dp[i-1][j-w[i]] + w[i]
            // and dp[i-1][j]. The first term corresponds to taking cow i, and the second
            // term corresponds to not taking cow i.
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + w[i]);
            }
        }
    }
    
    cout << dp[N-1][C] << endl;
    
    return 0;
}
