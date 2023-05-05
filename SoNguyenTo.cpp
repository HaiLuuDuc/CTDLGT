#include<bits/stdc++.h>
using namespace std;
bool snt[1000];
int n,p,s;
int indexx;
int count;
int arr[1000];
int x[1000];
int y[1000];
void sang(){
	for(int i=0;i<1000;i++){
		snt[i]=true;
	}
	snt[0]=snt[1]=false;
	for(int i=0;i<1000;i++){
		if(snt[i]==true){
			for(int j=i*i;j<1000;j+=i){
				snt[j]=false;
			}
		}
	}
}
void XuatMang(int arr[],int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
}
int tong(int arr[], int n){
	int res = 0;
	for(int i=1;i<=n;i++){
		res+=arr[i];
	}
	return res;
}
void CopyMang(int x[], int y[], int n){
	for(int i=1;i<=n;i++){
		y[i] = arr[x[i]];
	}
}
void quaylui(int i){
	for(int j=x[i-1]+1;j<=indexx-n+i;j++){
		x[i]=j;
		if(i==n){
			CopyMang(x,y,i);
			if(tong(y,i)==s){
				::count++;
			}
		}
		else{
			quaylui(i+1);
		}
	}
}
void quaylui2(int i){
	for(int j=x[i-1]+1;j<=indexx-n+i;j++){
		x[i]=j;
		if(i==n){
			CopyMang(x,y,i);
			if(tong(y,i)==s){
				XuatMang(y,i);
				cout<<endl;
			}
		}
		else{
			quaylui2(i+1);
		}
	}
}
int main(){
	sang();
	int t;
	cin>>t;
	while(t--){
		indexx=1;
		cin>>n>>p>>s;
		for(int i=p+1;i<=s;i++){
			if(snt[i]==true){
				arr[indexx]=i;
				indexx++;
			}
		}
		indexx--; // set indexx = n
		::count=0;
		x[0]=0;
		quaylui(1);
		cout<<::count<<endl;
		quaylui2(1);
	}
	return 0;
}
