#include <iostream>
using namespace std;

const int MAXN = 100;


bool isEulerian(int graph[][MAXN], int V) {
    int degree[MAXN] = {0};


    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(graph[i][j]) {
                degree[i]++;
            }
        }
    }


    for(int i=0; i<V; i++) {
        if(degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int V;
    int graph[MAXN][MAXN];

 
    cin >> V;
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cin >> graph[i][j];
        }
    }


    if(isEulerian(graph, V)) {
        cout << "La do thi Euler" << endl;
    } else {
        cout << "Khong phai do thi Euler" << endl;
    }

    return 0;
}
