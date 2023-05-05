#include<bits/stdc++.h>
using namespace std;
class canh{
	public:
		int start;
		int end;
		int trongso;
};
vector <canh> E;
vector <canh> T;
set<int> visited;
int sum = 0;
bool cmp(canh a, canh b){
	if(a.trongso >= b.trongso){
		return false;
	}
	else{
		return true;
	}
}
bool cmp2(canh a, canh b){
	if(a.start > b.start){
		return false;
	}
	else{
		if(a.start==b.start){
			if(a.end>b.end){
				return false;
			}
		}
	}
	return true;
}

bool CanhChuaCoTrongSet(canh e,set<int> visited){
	int x = e.start;
	int y = e.end;
	set<int>::iterator posx = visited.find(x);
	set<int>::iterator posy = visited.find(y);
	if(posx!=visited.end() && posy!=visited.end()){
		return false;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	int arr[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(arr[i][j]>0){
				canh canhtmp;
				canhtmp.start = i;
				canhtmp.end = j;
				canhtmp.trongso = arr[i][j];
				E.push_back(canhtmp);
			}
		}
	}	
	sort(E.begin(),E.end(),cmp);
	T.clear(); // khoi tao cay khung la rong
	sum=0;
	while(T.size()<n-1 && !E.empty()){
		//tim canh co do dai nho nhat
		canh e = E[0];
		//loai bo canh e khoi E
		E.erase(E.begin());
		if(CanhChuaCoTrongSet(e,visited)){
			T.push_back(e);
			sum = sum + e.trongso;
		}
		//them 2 dinh start end vao visited
		visited.insert(e.start);
		visited.insert(e.end);
	}
	//sort vector T
	sort(T.begin(),T.end(),cmp2);
	
	if(T.size()<n-1){
		cout<<"Do thi khong lien thong"<<endl;
	}
	else{
		for(int i=0;i<T.size();i++){
			cout<<T[i].start<<" "<<T[i].end<<" "<<endl;
		}
		cout<<sum<<endl;
	}
	
	
	return 0;
}
