#include<bits/stdc++.h>
using namespace std;

bool daxet[10000];
int truoc[10000];
vector<int> v[10000];

bool CoChuTrinh(int u){
    daxet[u] = true;
    for(int i=0;i<v[u].size();i++){
        int x = v[u][i];
        if(!daxet[x]){
            truoc[x] = u;
            if(CoChuTrinh(x)){
                return true;
            }
        } else if(truoc[u] != x){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            daxet[i]=false;
            v[i].clear();
        }
        for(int i=0;i<10000;i++){
        	daxet[i]=false;
		}
        while(m--){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=0;i<10000;i++){
        	truoc[i]=-1;
		}
        bool isok = false;
        for(int i=1;i<=n;i++){
            if(!daxet[i]){
                if(CoChuTrinh(i)){
                    isok = true;
                    break;
                }
            }
        }
        if(isok){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout<<endl;
    }
    return 0;
}
