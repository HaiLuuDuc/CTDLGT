#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=1;i<=n;i++) cin>>arr[i]; 
		sort(arr+1,arr+n+1);
		
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(n==2){
			cout<<arr[1]+arr[2]<<endl;
			continue;
		}
		
		long long  ans = 0;
		long long  sum = arr[1] + arr[2];
		ans += sum;
		for(int i=3;i<=n;i++){
			sum+=arr[i];
			ans+=sum;
		}
		cout<<ans<<endl;
	}
	return 0;
}
