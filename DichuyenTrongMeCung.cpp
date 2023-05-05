#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1000][1000];
char x[1000];
bool isok = false;
void XuatMang(char arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
}
void quaylui(int i, int j, int len) {
    if (i == n && j == n ) {
        isok = true;
        XuatMang(x,len);
        return;
    }
    if (i + 1 <= n && arr[i + 1][j] == 1) {
        x[len] = 'D';
        quaylui(i + 1, j, len + 1);
    }
    if (j + 1 <= n && arr[i][j + 1] == 1) {
        x[len] = 'R';
        quaylui(i, j + 1, len + 1);
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>arr[i][j];
			}
		}
		isok = false;
		if(arr[1][1]==0 || arr[n][n]==0){
			cout<<-1<<endl;
			continue;
		}
		quaylui(1,1,1);
		if(!isok){
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}
