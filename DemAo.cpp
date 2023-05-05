#include<bits/stdc++.h>
using namespace std;

int truoc[10000];


int Find(int v){
	if(truoc[v]==v){
		return v;
	}
	else{
		return truoc[v] = Find(truoc[v]);
	}
}

void Union(int a, int b){
	int A = truoc[a];
	int B = truoc[b];
	truoc[b] = A;
}           

int main(){
	int n,m;
	cin>>n>>m;
	char arr[n+1][m+1];
	int brr[n+1][m+1];
	int counter=0;
	//make brr
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
	
	//makeset
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(brr[i][j]>0){
				truoc[brr[i][j]] = brr[i][j];
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
	//union
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			for(int u=i-1;u<=i+1;u++){
				for(int v=j-1;v<=j+1;v++){
					if(i>=1&&i<=n&&j>=1&&j<=m){
						if(arr[i][j]=='W'){
							Union(brr[i][j], brr[u][v]);
						}
					}
				}
			}
			
		}
	}

	
	
	
	
	
	
	
	return 0;
}
