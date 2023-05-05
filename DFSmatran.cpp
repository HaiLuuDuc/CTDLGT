#include<bits/stdc++.h>
using namespace std;

int n,m;
bool daxet[1000][1000];
int arr[1000][1000];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void ResetDaxet(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			daxet[i][j] = false;
		}
	}
}

void DFS(int row, int col){
	daxet[row][col] = true;
	for (int i = 0; i < 8; i++) {
        int new_row = row + dx[i];
        int new_col = col + dy[i];
        if (new_row >= 1 && new_row <= n && new_col >= 1 && new_col <= m && !daxet[new_row][new_col] && arr[new_row][new_col]==1) {
            DFS(new_row, new_col);
        }
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;

	ResetDaxet();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(daxet[i][j]==false && arr[i][j]==1){
				count++;
				DFS(i,j);
			}
		}
	}
	cout<<count<<endl;
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	
	return 0;
}
