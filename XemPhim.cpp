#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,w;
		cin>>w;
		cin>>n;
		int wt[n+1];
		for(int i=0;i<n;i++){
			cin>>wt[i];
		}
		int K[n+1][w+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=w;j++){
				if(i==0||j==0){
					K[i][j] = 0;
				}
				else if(wt[i-1]<=j){
					K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
				}
				else K[i][j] = K[i-1][j];
			}
		}
		cout<<K[n][w]<<endl;
	}

	return 0;
}
