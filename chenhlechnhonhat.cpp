//3 3
//
//010    quayluihoanvi 123 132 213 231 312 321, sau do tinh hieu max-min, kq=min(kq,hieu)
//
//909
//
//012
#include<bits/stdc++.h>
using namespace std;
int n; int k;
string arr[1000];
bool daxet[1000];
int x[1000];
long long kq;
long long stringtolonglong(string str){
	long long res = 0;
	int mu = 0;
	int length=str.length();
	for(int i=length-1;i>=0;i--){
		res += (str[i]-'0')*pow(10,mu);
		mu++;
	}
	return res;
}
void quaylui(int i){
	for(int j=1;j<=k;j++){
		if(daxet[j]==false){
			x[i]=j;
			daxet[j]=true;
			if(i==k){
				//do something
				// 132
				// 909 -> 990
				for(int h=1;h<=n;h++){ //duyet cac phan tu cua mang string arr
					string tmp = "";
					for(int u=0;u<k;u++){
						tmp += arr[h][u];
					}
					// now tmp = arr[h]
					for(int u=1;u<=k;u++){ // gan lai vao arr[h]
						arr[h][u-1] = tmp[x[u]-1];
					}
				}
				string maxx = *max_element(arr+1,arr+1+n);
				string minn = *min_element(arr+1,arr+1+n);
				kq=min(kq,stringtolonglong(maxx)-stringtolonglong(minn));
				cout<<maxx<<" "<<minn<<endl;
			}
			else{
				quaylui(i+1);
			}
			daxet[j]=false;
		}
	}
}
int main(){
	for(int i=0;i<1000;i++){
		daxet[i]=false;
	}
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	kq=9999999999;
	quaylui(1);
	cout<<kq;
	
	
	
	return 0;
}
