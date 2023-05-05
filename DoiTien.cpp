#include<bits/stdc++.h>
using namespace std;
int menhGia[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int currentSum = 0;
		int count = 0;
		while(n){
			for(int i = 9;i>=0;i--){
				if(::menhGia[i]<=n){
					count++;
					n-=::menhGia[i];
					break;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
