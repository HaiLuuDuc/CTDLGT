#include<bits/stdc++.h>
using namespace std;
int n,k;
int index;
string arr[100];
string x[100];
void XuatMang(string arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}//                     1   2    3   4
void quaylui(int i, int start){ // bac dong nam tay
	for(int j=start;j<index;j++){ //j<=4
		if(true){
			x[i] = arr[j];
			if(i==k){
				XuatMang(x,k);
			}
			else{
				quaylui(i+1,j+1);
			}
		}
	}
}
int main(){ // Bac Dong Nam Tay
	cin>>n>>k;
	cin.ignore();
	set<string> s;
	set<string>::iterator it;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		s.insert(str);
	}
	index=1;
	for(it=s.begin();it!=s.end();it++){
		arr[index] = *it;
		index++;
	}
	// now index = 5 = arr.length (0 1 2 3 4)
	quaylui(1,1);
	return 0;
}
