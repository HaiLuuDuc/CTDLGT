#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int correctArr[n];
		for(int i=1;i<=n;i++) cin>>arr[i];
		for(int i=1;i<=n;i++) correctArr[i]=arr[i];
		sort(correctArr+1,correctArr+n+1);
		//index     : 1 2 3 4 5 6 7
		//arr       : 1 6 3 4 5 2 7
		//correctarr: 1 2 3 4 5 6 7

		for(int i=1;i<=n/2+1;i++){
			//cout<<arr[i]<<" "<<correctArr[i]<<endl;
			//cout<<arr[n-i+1]<<" "<<correctArr[n-i+1]<<endl;
			if(!((arr[i]==correctArr[i]&&arr[n-i+1]==correctArr[n-i+1])
			||(arr[i]==correctArr[n-i+1]&&arr[n-i+1]==correctArr[i])
			))
			
			{
				cout<<"No"<<endl;
				goto label;
			}
			
		}
		cout<<"Yes"<<endl;
		label:;
	}
	return 0;
}
