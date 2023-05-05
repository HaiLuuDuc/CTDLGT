#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string str1,str2;
		getline(cin,str1);
		getline(cin,str2);
		int length1 = str1.length();
		int length2 = str2.length();
		int dp[length1+1][length2+1];
		for(int i=0;i<=length1;i++){
			for(int j=0;j<=length2;j++){
				dp[i][j]=0;
			}
		}
		for(int i=1;i<=length1;i++){
			for(int j=1;j<=length2;j++){
				int tmp = max(dp[i-1][j], dp[i][j-1]);
				if(str1[i-1]==str2[j-1]){
					dp[i][j]=max(dp[i-1][j-1]+1, tmp);
				}
				else{
					dp[i][j]=tmp;
				}				
			}
		}
		cout<<dp[length1][length2]<<endl;
//		for(int i=0;i<=length1;i++){
//			for(int j=0;j<=length2;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		
		
	}
	return 0;
}
