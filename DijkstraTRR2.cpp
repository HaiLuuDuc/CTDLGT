#include<bits/stdc++.h>

using namespace std;

#define MAX 50 
#define TRUE 1 
#define FALSE 0
#define VOCUNG 10000000 
int n; // S? d?nh c?a d? th?
int s; // �?nh b?t d?u du?ng di
int t; // �?nh cu?i
int truoc[MAX]; //M?ng d�nh d?u du?ng di
int d[MAX]; // M?ng d�nh d?u kho?ng c�ch
int CP[MAX][MAX]; //Ma tr?n tr?ng s?
int final[MAX]; // M?ng d�nh d?u c�c d?nh du?c g�n nh�n


void Init(){
ifstream fpi("BT1.in");
	fpi>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fpi>>CP[i][j];
            if (CP[i][j]==0) CP[i][j]=VOCUNG;
		}
	}
}

void Result(){ 
    int i,j;
    printf("\n Duong di ngan nhat tu %d den %d la\n", s,t); printf("%d <-",t);
    i=truoc[t];
    while(i!=s){
        printf("%d <- ",i);
        i=truoc[i]; 
        }
    printf("%d",s);
    printf("\n Do dai duong di la:%d", d[t]); 
}

void Dijkstra(){
    int v, u, minp;
    printf("\n Tim duong di tu s=");
    scanf("%d", &s); 
    printf(" den ");
    scanf("%d", &t);
    //Kh?i t?o nh�n t?m th?i cho c�c d?nh.
    for(v=1; v<=n; v++){
        d[v]=CP[s][v]; 
        truoc[v]=s; 
        final[v]=FALSE;}
    truoc[s]=0; d[s]=0;final[s]=TRUE; 
    //L?p
    while(!final[t]){
        minp=VOCUNG;
        //T�m d?nh u sao cho d[u] l� nh? nh?t
        for(v=1; v<=n; v++){
        if((!final[v]) && (minp>d[v]) ){ 
            u=v;
            minp=d[v];}
    }
    final[u]=TRUE;// u l� d?nh c� nh�n t?m th?i nh? nh?t 
    if(!final[t]){
        //G�n nh�n l?i cho c�c d?nh.
        for(v=1; v<=n; v++){
            if ((!final[v]) && (d[u]+ CP[u][v]< d[v])){
                d[v]=d[u]+CP[u][v];
                truoc[v]=u; }
            } 
        }
    } 
}
int main(){
    Init(); 
    Dijkstra(); 
    Result(); 
}
