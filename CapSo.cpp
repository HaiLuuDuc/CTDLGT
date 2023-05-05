#include<bits/stdc++.h>
using namespace std;
class capso{
	public:
		int dau;
		int cuoi;
};
bool cmp(const capso  a, const capso b){
	if(a.cuoi<b.cuoi){
		return true;
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	capso arr[n+1];
	int dp[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i].dau;
		cin>>arr[i].cuoi;
	}
	sort(arr+1,arr+1+n,cmp);
	dp[1]=1;
	int kq=1;
	for(int i=2;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(arr[j].cuoi<arr[i].dau){
				dp[i] = max(dp[i],dp[j]+1);
				kq = max(kq,dp[i]);
			}
		}
	}
	cout<<kq<<endl;
	}
	
	
	
	
	return 0;
}
