#include<bits/stdc++.h>
using namespace std;
int n;
int x[10000];
int cot[10000];
int duongCheoXuong[10000];
int duongCheoLen[10000];
int count = 0;
void XuatMang(int arr[], int n){
	::count++;
	for(int i=1;i<=n;i++){
		cout<<"("<<i<<" "<<arr[i]<<") ";
	}
	cout<<endl;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(cot[j]==1&&duongCheoXuong[i-j+n]==1&&duongCheoLen[i+j-1]==1){
			x[i]=j;
			cot[j]=duongCheoXuong[i-j+n]=duongCheoLen[i+j-1]=0;
			if(i==n){
				::count++;
			}
			else{
				Try(i+1);
			}
			cot[j]=duongCheoXuong[i-j+n]=duongCheoLen[i+j-1]=1;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<10000;i++){
			cot[i]=duongCheoLen[i]=duongCheoXuong[i]=1;
		}
		::count=0;
		Try(1);
		cout<<::count<<endl;
	}
	
}
