#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Khai b�o c?u tr�c c?nh
struct Edge {
    int src, dest, weight;
};

// H�m so s�nh hai c?nh theo tr?ng s? d? s?p x?p
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

// H�m t�m cha c?a m?t d?nh
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// H�m h?p nh?t hai c�y
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// H�m Kruskal t�m c�y khung nh? nh?t
void Kruskal(vector<Edge> edges, int V) {
    // S?p x?p c�c c?nh theo tr?ng s?
    sort(edges.begin(), edges.end(), cmp);

    // Kh?i t?o m?ng ch?a c�c cha c?a c�c d?nh
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    // Kh?i t?o c�y khung v� d?m s? c?nh d� ch?n
    vector<Edge> mst;
    int count = 0;

    // Duy?t qua c�c c?nh theo th? t? tang d?n c?a tr?ng s?
    for (int i = 0; i < edges.size(); i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        // Ki?m tra xem c?nh n�y c� t?o th�nh chu tr�nh v?i c�c c?nh d� ch?n tru?c d� hay kh�ng
        if (find(parent, src) != find(parent, dest)) {
            // Th�m c?nh v�o c�y khung v� c?p nh?t cha c?a c�c d?nh
            mst.push_back(edges[i]);
            Union(parent, src, dest);
            count++;

            // N?u d� ch?n d? V-1 c?nh th� d?ng thu?t to�n
            if (count == V - 1)
                break;
        }
    }

    // Ki?m tra xem c�y khung c� ch?a d? V d?nh hay kh�ng
    if (mst.size() < V - 1) {
        cout << "Do thi khong lien thong";
        return;
    }
