#include<bits/stdc++.h>
using namespace std;
int sum;
int n;
int arr[1000];
int x[1000];
bool isok;
void xuly(int arr[], int n){
	sort(arr+1,arr+1+n);
	
	cout<<"YES"<<endl;
}
void quaylui(int i, int s){
	if(isok) return;
	for(int j=i;j<=n;j++){
		if(isok) return;
		if(s+arr[j]<=sum/2){
			x[i]=j;
			s+=arr[j];
			if(s==sum){
				isok=true;
			}
			else if(s<sum/2){
				quaylui(i+1,s);
			}
			s-=arr[j];
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		sum=0; isok = false;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%2!=0){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			sort(arr+1,arr+1+n);
			quaylui(1,0);
			if(isok){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}
