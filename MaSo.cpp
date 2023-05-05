#include<bits/stdc++.h>
using namespace std;
int n;
char x[1000];
int y[1000];
bool daxet[1000];
vector<string> v;
vector<int> v2;
int indexx;
void XuatMang(int arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
}
void XuatMangChar(char arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
}
void quaylui1(int i){
	for(int j=1;j<=n;j++){
		if(daxet[j]==false){
			x[i]= (char)(j+(int)'A'-1);
			daxet[j]=true;
			if(i==n){
				string tmp = "";	
				for(int k=1;k<=n;k++){
					tmp = tmp + x[k];
				}
				v.push_back(tmp);
			}
			else{
				quaylui1(i+1);
			}
			daxet[j]=false;
		}
	}
}
void quaylui2(int i){
	for(int j=1;j<=n;j++){
		y[i]=j;
		if(i==n){
			int tmp = 0;
			int mu = 0;
			for(int k=i;k>=1;k--){
				tmp = tmp + y[k]*pow(10,mu);
				mu++;
			}
			v2.push_back(tmp);
		}
		else{
			quaylui2(i+1);
		}
	}
}

int main(){
	for(int i=0;i<1000;i++){
		daxet[i]=false;
	}
	cin>>n;
	quaylui1(1);
//	for(int i=0;i<v.size();i++){
//		cout<<v[i]<<" ";
//	}
	quaylui2(1);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v2.size();j++){
			cout<<v[i]<<v2[j]<<endl;
		}
	}
	return 0;
}
