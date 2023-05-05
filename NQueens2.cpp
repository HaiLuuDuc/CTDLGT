#include<bits/stdc++.h>
using namespace std;
int n;
int x[10000];
int cot[10000];
int duongCheoXuong[10000];
int duongCheoLen[10000];
int diem[100][100];
int sum = 0;
int max = 0;
void NhapMang(int arr[][100], int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
}
void XuatMang(int arr[], int n){
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
			sum+=diem[i][j];
			if(i==n){
				if(sum>::max){
					::max = sum;
				}
				//XuatMang(x,n);
			}
			else{
				Try(i+1);
			}
			cot[j]=duongCheoXuong[i-j+n]=duongCheoLen[i+j-1]=1;
			sum-=diem[i][j];
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		n=8;
		NhapMang(diem,8);
		for(int i=0;i<10000;i++){
			cot[i]=duongCheoLen[i]=duongCheoXuong[i]=1;
		}
		::sum = 0;
		::max = 0;
		Try(1);
		cout<<::max<<endl;
	}
	return 0;
}
