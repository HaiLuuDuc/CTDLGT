#include<bits/stdc++.h>
using namespace std;

int n,m;
set<string> s;
set<string>::iterator it;
vector<string> v;
string x[10000];

void xuatmang(string arr[], int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
}
	
void quaylui(int i, int a){
	for(int j=a;j<v.size();j++){
		x[i]=v[j];
		if(i==m){
			xuatmang(x,m);
			cout<<endl;
		}
		else{
			quaylui(i+1,j+1);
		}
	}
}

int main(){
	cin>>n>>m;
	cin.ignore();
	//nhap vao set
	while(n--){
		string tmp;
		cin>>tmp;
		s.insert(tmp);
	}
	//chuyen sang vector
	for(it=s.begin();it!=s.end();it++){
		v.push_back((*it));
	}
	

	
	quaylui(1,0);
	
	
	
	return 0;
}
