#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Khai báo c?u trúc c?nh
struct Edge {
    int src, dest, weight;
};

// Hàm so sánh hai c?nh theo tr?ng s? d? s?p x?p
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Hàm tìm cha c?a m?t d?nh
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Hàm h?p nh?t hai cây
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Hàm Kruskal tìm cây khung nh? nh?t
void Kruskal(vector<Edge> edges, int V) {
    // S?p x?p các c?nh theo tr?ng s?
    sort(edges.begin(), edges.end(), cmp);

    // Kh?i t?o m?ng ch?a các cha c?a các d?nh
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    // Kh?i t?o cây khung và d?m s? c?nh dã ch?n
    vector<Edge> mst;
    int count = 0;

    // Duy?t qua các c?nh theo th? t? tang d?n c?a tr?ng s?
    for (int i = 0; i < edges.size(); i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        // Ki?m tra xem c?nh này có t?o thành chu trình v?i các c?nh dã ch?n tru?c dó hay không
        if (find(parent, src) != find(parent, dest)) {
            // Thêm c?nh vào cây khung và c?p nh?t cha c?a các d?nh
            mst.push_back(edges[i]);
            Union(parent, src, dest);
            count++;

            // N?u dã ch?n d? V-1 c?nh thì d?ng thu?t toán
            if (count == V - 1)
                break;
        }
    }

    // Ki?m tra xem cây khung có ch?a d? V d?nh hay không
    if (mst.size() < V - 1) {
        cout << "Do thi khong lien thong";
        return;
    }
