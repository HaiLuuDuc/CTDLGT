#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int t, n;
string s = "";
int dx[] = {1, 0};
int dy[] = {0, 1};
void xuat(){
	cout << s << " ";
	s = "";
}
void Try(int x, int y){
	for (int i = 0; i <= 1; i++){
		int c = x + dx[i];
		int d = y + dy[i];
		if (a[c][d]){
			if (i == 1) s += "R";
			else s += "D";
			if (c == n - 1 && d == n - 1) xuat();
			Try(c, d);
			s.erase(s.size() - 1);
		}
	}
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		Try(0, 0);
		cout << endl;
	}
}
