//0 1 2 3 4 5 6 7
//2 3 4 5 6 8
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		
		//logic    2 3 4 5 6 8
		if(n==1){
			cout<<arr[0]<<endl;
			continue;
		}
		if(n%2==0){
			int mu=0;
			int ans=0;
			for(int i=n-1;i>=1;i-=2){
				int tmp = arr[i]+arr[i-1];
				ans = ans + tmp*pow(10,mu);
				mu++;
			}
			cout<<ans;
		}
		else{
			int mu=0;
			int ans=0;
			for(int i=n-1;i>=2;i-=2){
				int tmp = arr[i]+arr[i-1];
				ans = ans + tmp*pow(10,mu);
				mu++;
			}
			ans = ans + arr[0]*pow(10,mu);
			cout<<ans;
		}
		
		cout<<endl;
		
	}
	return 0;
}
