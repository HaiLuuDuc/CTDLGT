#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		int dp[n+1]={0};
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		dp[1]=arr[1];
		for(int i=2;i<=n;i++){
			dp[i]=arr[i];
			int maxx=-9999;
			for(int j=1;j<i;j++){
				if(arr[j]<arr[i]){
					dp[i] = max(dp[i],dp[j]+arr[i]);
				}
			}
		}
		int maxDp = dp[0];
		for(int i=1;i<n;i++){
			if(dp[i]>maxDp){
				maxDp = dp[i];
			}
		}
		cout<<maxDp<<endl;
	}
	return 0;
}
