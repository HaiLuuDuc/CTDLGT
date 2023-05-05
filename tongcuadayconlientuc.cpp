#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		int dp[n+1];
		long long sum = 0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			dp[i-1]=0;
			for(int j=i;j<=n;j++){
				dp[j] = max(dp[j-1], arr[j]);
				sum+=dp[j];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
