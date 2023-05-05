#include<bits/stdc++.h>
using namespace std;
vector<bool> snt;
vector<int> thuasolonnhat;
void sang(){
	snt.push_back(false);
	snt.push_back(false);
	for(int i=2;i<100000;i++){
		snt.push_back(true);
	}
	for(int i=2;i<100000;i++){
		if(snt[i]==true){
			for(int j=i*i;j<=sqrt(100000);j+=i){
				snt[j]=false;
			}
		}
	}
}
int thuasolonnhatt(int n){
	if(n==0||n==1) return 1;
	int maxx=1;
	for(int i=2;i<=n;i++){
		if(n%i==0 && snt[i]==true){
			maxx=i;
		}
	}
	return maxx;
}
void setup(){
	for(int i=0;i<100001;i++){
		thuasolonnhat.push_back(thuasolonnhatt(i));
	}
}
int main(){
	sang();
	setup();
	int t;
	cin>>t;
//	while(t--){
//		int l,r;
//		long long sum = 0;
//		cin>>l>>r;
//		for(int i=l;i<=r;i++){
//			sum+=thuasolonnhat[i];
//		}
//		cout<<sum<<endl;
//	}
	return 0;
}
