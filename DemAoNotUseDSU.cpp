#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	char arr[n+1][m+1];
	int brr[n+1][m+1];
	int counter = 0;
	//nhap mang arr de bai, sau do danh so cho brr
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='W'){
				counter++;
				brr[i][j] = counter;
			}
			else{
				brr[i][j] = 0;
			}
		}
	}
	
	//xuat mang brr
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<brr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//xu ly
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(brr[i][j]>0){
				if(brr[i+1][j]>0 && i+1<=n){
					brr[i+1][j] = brr[i][j];
				}
				if(brr[i][j+1]>0 && j+1<=m){
					brr[i][j+1] = brr[i][j];
				}
				if(brr[i+1][j+1]>0 && i+1<=n && j+1<=m){
					brr[i+1][j+1] = brr[i][j];
				}
				if(brr[i+1][j-1]>0 && i+1<=n && j-1>=1){
					brr[i+1][j-1] = brr[i][j];
				}
			}
		}
	}
	
	//add to set
	set<int> s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(brr[i][j]){
				s.insert(brr[i][j]);
			}
		}
	}
	cout<<s.size()<<endl;
	//xuat mang brr
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<brr[i][j]<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}
