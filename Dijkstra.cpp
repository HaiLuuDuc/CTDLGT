#include<bits/stdc++.h>
using namespace std;

const int INF = 100007;
int n,m,u;
vector<int> value;
vector<bool> daxet;
vector<vector<int> > vt;
vector<vector<int> >matrantrongso;


int MinIndex(vector<int> arr, int n){
	int minn=0;
	int minIndex=0;
	
	//tim ra phan tu dau tien chua xet de gan minn
	for(int i=1;i<=n;i++){
		if(daxet[i]==false){
			minn = arr[i];
			minIndex = i;
			break;
		}
	}
	
	for(int i=minIndex+1;i<=n;i++){
		if(arr[i]<minn&&daxet[i]==false){
			minn = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void InRaDske(){
	for(int i=1;i<=n;i++){
		cout<<i<<": ";
		for(int j=0;j<vt[i].size();j++){
			cout<<vt[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>u;
		daxet.clear();
		daxet.resize(n+1,false);
		value.clear();
		value.resize(n+1,INF);
		matrantrongso.clear();
		matrantrongso.resize(n+1);
		for(int i=0;i<=n;i++){
			matrantrongso[i].resize(n+1,INF);
		}
		
		value[u] = 0;

		//doc du lieu tu input
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			matrantrongso[x][y]=z;
		}
		
		//dijkstra
		for(int i=1;i<=n;i++){ // dong nay tuong duong !st.empty()
//			for(int j=1;j<=n;j++){
//				cout<<value[j]<<" ";
//			}
//			cout<<endl;
			int minIndex = MinIndex(value,n); //minIndex la dinh co value nho nhat
			if(minIndex==0){
				continue;
			}
			daxet[minIndex] = true;
			for(int j=1;j<=n;j++){
				if(daxet[j]==false)
				if(value[minIndex]+matrantrongso[minIndex][j]<value[j]){
					value[j]=value[minIndex]+matrantrongso[minIndex][j];
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			cout<<value[i]<<" ";
		}
		
		
		
		

		
		
		cout<<endl;
	}
	
	
	return 0;
}
