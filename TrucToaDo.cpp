#include<bits/stdc++.h>
using namespace std;
class doanthang{
	public: 
		int batdau;
		int ketthuc;
};
bool cmp(doanthang a, doanthang b){
	return a.ketthuc<b.ketthuc;
}
int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		doanthang arr[n+1];
		for(int i=1;i<=n;i++){
			cin>>arr[i].batdau;
			cin>>arr[i].ketthuc;
		}
		sort(arr+1,arr+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<arr[i].batdau<<" ";
//			cout<<arr[i].ketthuc<<endl;
//		}
		int i=1;
		int count=1;
		for(int j=2;j<=n;j++){
			if(arr[j].batdau>=arr[i].ketthuc){
				count++;
				i=j;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
