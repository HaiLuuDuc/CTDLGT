#include<bits/stdc++.h>
using namespace std;
int n;
int k;
char x[1000];
bool chuacaba(char arr[], int n){
	bool checka=false;
	bool checkb=false;
	bool checkc=false;
	for(int i=1;i<=n;i++){
		if(arr[i]=='A'){
			checka=true;
		}
		else if(arr[i]=='B'){
			checkb=true;
		}
		else if(arr[i]=='C'){
			checkc=true;
		}
	}
	if(checka&&checkb&&checkc){
		return true;
	}
	else return false;
}
bool checkabc(char arr[], int n){
	int suma=0;
	int sumb=0;
	int sumc=0;
	for(int i=1;i<=n;i++){
		if(arr[i]=='A'){
			suma++;
		}
		else if(arr[i]=='B'){
			sumb++;
		}
		else if(arr[i]=='C'){
			sumc++;
		}
	}
	if(suma>sumb || sumb>sumc){
		return false;
	}
	else return true;
}
void XuatMang(char arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
}
void quaylui(int i){
	for(int j=1;j<=3;j++){
		x[i]=(char)('A'+j-1);
		if(i==k){
			if(chuacaba(x,i)&&checkabc(x,i)){
				XuatMang(x,i);
				cout<<endl;
			}
		}
		else{
			quaylui(i+1);
		}
	}
}
int main(){
	cin>>n;
	for(k=3;k<=n;k++){
		quaylui(1);
	}
	return 0;
}
