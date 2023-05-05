#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[1000];
int x[1000];
int s;
bool isok;
void XuatMang(int arr[], int n){
	cout<<"[";
	for(int i=1;i<=n;i++){
		if(i==n){
			cout<<arr[i];	
		}
		else{
			cout<<arr[i]<<" ";
		}
	}
	cout<<"]";
}
void quaylui(int i, int s, int start){
	for(int j=start;j<=n;j++){
		if(s+arr[j]<=k){
			x[i]=arr[j];
			s+=arr[j];
			if(s==k){
				XuatMang(x,i);
				isok=true;
			}
			else{
				quaylui(i+1,s,j);
			}
			s-=arr[j];
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		isok=false;
		quaylui(1,0,1);
		if(!isok){
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}
