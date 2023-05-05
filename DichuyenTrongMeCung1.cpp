#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100][100];
char x[1000];
bool isok;

void nhapmang(int arr[][100], int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
}

void xuatmang(char arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
	cout<<" ";
}

void quaylui(int i, int j){
	//uu tien di xuong 
	if(i==j && j==n){
		xuatmang(x,(n-1)*2);
		isok=true;
	}
	if(i+1<=n && arr[i+1][j]==1){
		x[i+j-1] = 'D';
		quaylui(i+1,j);
	}
	if(j+1<=n && arr[i][j+1]==1){
		x[i+j-1] = 'R';
		quaylui(i,j+1);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		nhapmang(arr,n);
		isok = false;
		if(arr[1][1]==0){
			cout<<-1<<endl;
			continue;
		}
		else{
			quaylui(1,1);
		}
		if(isok==false){
			cout<<-1;
		}
		cout<<endl;
	}
	

	return 0;
}
