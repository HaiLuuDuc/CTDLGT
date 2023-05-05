#include<bits/stdc++.h>
using namespace std;
char c;
int k;
int length;
char collection[100];
char x[100];
void XuatMang(char arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
	cout<<endl;
}//                     1   2    3   4
void quaylui(int i, int start){ // bac dong nam tay
	for(int j=start;j<=length;j++){ //j<=4
		if(true){
			x[i] = collection[j];
			if(i==k){
				XuatMang(x,k);
			}
			else{
				quaylui(i+1,j);
			}
		}
	}
}
int main(){ 
	cin>>c>>k;
	length = c-'A'+1;
	for(int i=1;i<=length;i++){
		collection[i]= (char)((int)'A' + i - 1);
	}
	quaylui(1,1);
	return 0;
}
