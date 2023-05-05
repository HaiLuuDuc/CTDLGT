#include<bits/stdc++.h>
using namespace std;
int FiveToSix(int n){
	int ans = 0;
	int mu = 0;
	while(n){
		int tmp = n%10;
		if(tmp==5) tmp = 6;
		ans = ans + tmp*pow(10,mu);
		n/=10;
		mu++;
	}
	return ans;
}
int SixToFive(int n){
	int ans = 0;
	int mu = 0;
	while(n){
		int tmp = n%10;
		if(tmp==6) tmp = 5;
		ans = ans + tmp*pow(10,mu);
		n/=10;
		mu++;
	}
	return ans;
}
int main(){
	int t;
	t=1;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<SixToFive(a)+SixToFive(b)<<" ";
		cout<<FiveToSix(a)+FiveToSix(b)<<endl;
	}
	return 0;
}
