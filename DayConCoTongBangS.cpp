#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,s;
		cin>>n>>s;
		int arr[n+1];
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		bool dp[n+1][s+1];
		for(int i=0;i<=n;i++){
			dp[i][0] = true;
		}
		for(int j=1;j<=s;j++){
			dp[0][j] = false;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s;j++){
				
				dp[i][j] = dp[i-1][j];
				
				if(dp[i][j]==false){
					if(j>=arr[i]){
						dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
					}	
				}
				// arr 2 3 5 7 9...
				// dang xet phan tu thu 3 cua arr, tong la 8
				// neu (2,8) = false thi`
				// xet xem (2,8-arr[3]) = (2,3) = true ?
			}
		}
		if(dp[n][s]) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=s;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
