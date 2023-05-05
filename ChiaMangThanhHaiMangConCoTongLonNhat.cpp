#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		int ans;
		cin>>n>>k;
		int arr[n];
		for(int i=1;i<=n;i++) cin>>arr[i];
		sort(arr+1,arr+n+1);
		if(n==1){
			cout<<arr[0]<<endl;
			continue;
		}
		if(n%2==0){
			int mid = n/2;
			int sum1 = 0;
			int sum2 = 0;
			if(k<=mid){
				for(int i=1;i<=k;i++){
					sum1+=arr[i];
				}
				for(int i=k+1;i<=n;i++){
					sum2+=arr[i];
				}
			}
			else{
				k = n - k;
				for(int i=1;i<=k;i++){
					sum1+=arr[i];
				}
				for(int i=k+1;i<=n;i++){
					sum2+=arr[i];
				}
			}
			ans = sum2 - sum1;
		}
		else{
			int mid = n/2;
			int sum1 = 0;
			int sum2 = 0;
			if(k<=mid){
				for(int i=1;i<=k;i++){
					sum1+=arr[i];
				}
				for(int i=k+1;i<=n;i++){
					sum2+=arr[i];
				}
			}
			else{
				k = n - k;
				for(int i=1;i<=k;i++){
					sum1+=arr[i];
				}
				for(int i=k+1;i<=n;i++){
					sum2+=arr[i];
				}
			}
			ans = sum2 - sum1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
