#include<bits/stdc++.h>
using namespace std;

void IncreaseLowestIndex(int arr[],int brr[], int crr[], int &i, int &j, int &h){
	int minn = min(arr[i],min(brr[j],crr[h]));
	if(arr[i]==minn){
		i++;
		return;
	}
	if(brr[j]==minn){
		j++;
		return;
	}
	if(crr[h]==minn){
		h++;
		return;
	}
}
int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr[n+1],brr[m+1],crr[k+1];
		for(int i=1;i<=n;i++) cin>>arr[i];
		for(int i=1;i<=m;i++) cin>>brr[i];
		for(int i=1;i<=k;i++) cin>>crr[i];
	
		int i=1,j=1,h=1;
		bool isOK = false;
		while(i<=n && j<=m && h<=k){
			if(arr[i]==brr[j] && arr[i]==crr[h]){
				cout<<arr[i]<<" ";
				i++;j++;h++;
				isOK = true;
			}
			else{
				IncreaseLowestIndex(arr,brr,crr,i,j,h);
			}
		}
		if(!isOK){
			cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}
