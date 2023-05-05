#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		long x;
		cin>>x;
		long long arr[n];
		for(long i=0;i<n;i++){
			cin>>arr[i];
			if(i==0){
				if(arr[i]>x){
					cout<<-1;
					break;
				}
			}
			else{
				if(arr[i]>x){
					cout<<i;
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

