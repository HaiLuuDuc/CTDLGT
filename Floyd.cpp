#include<bits/stdc++.h>
using namespace std;

const int INF = 100007;
int n,m;
vector<vector<int> >matrantrongso;


int main(){
	int t;
	t=1;
	while(t--){
		cin>>n>>m;
		matrantrongso.clear();
		matrantrongso.resize(n+1);
		for(int i=0;i<=n;i++){
			matrantrongso[i].resize(n+1,INF);
		}
		// Kh?i t?o ma tr?n kho?ng cách
	    for (int i = 1; i <= n; i++) {
	        for (int j = 1; j <= n; j++) {
	            if (i == j) matrantrongso[i][j] = 0;
	            else matrantrongso[i][j] = INF;
	        }
	    }
		

		//doc du lieu tu input
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			matrantrongso[x][y]=z;
			matrantrongso[y][x]=z;
		}
		
		
		
		//floyd
		for(int k=1;k<=n;k++){ 
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(matrantrongso[i][k]+matrantrongso[k][j]<matrantrongso[i][j]){
						matrantrongso[i][j]=matrantrongso[j][i]=matrantrongso[i][k]+matrantrongso[k][j];
					}
				}
			}
		}
		
		int q;
		cin>>q;
		while(q--){
			int a,b;
			cin>>a>>b;
			cout<<matrantrongso[a][b]<<endl;
		}
		
		

		
		

		
		
		cout<<endl;
	}
	
	
	return 0;
}
