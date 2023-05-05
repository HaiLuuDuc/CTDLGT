#include <bits/stdc++.h>
using namespace std;

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void outputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr1[n];
        int arr2[m];
        int intersection[min(n, m)];
        int unionArray[n + m];
        int intersectionIndex = 0;
        int unionIndex = 0;
        
        inputArray(arr1, n);
        inputArray(arr2, m);
        
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (arr1[i] == arr2[j]) {
                intersection[intersectionIndex] = arr1[i];
                intersectionIndex++;
                unionArray[unionIndex] = arr1[i];
                unionIndex++;
                i++;
                j++;
            } else if (arr1[i] < arr2[j]) {
                unionArray[unionIndex] = arr1[i];
                unionIndex++;
                i++;
            } else if (arr1[i] > arr2[j]) {
                unionArray[unionIndex] = arr2[j];
                unionIndex++;
                j++;
            }
        }
        
        // Add the remaining elements from arr1 to unionArray
        while (i < n) {
            unionArray[unionIndex] = arr1[i];
            unionIndex++;
            i++;
        }
        
        // Add the remaining elements from arr2 to unionArray
        while (j < m) {
            unionArray[unionIndex] = arr2[j];
            unionIndex++;
            j++;
        }
        
        outputArray(unionArray, unionIndex);
        outputArray(intersection, intersectionIndex);
    }
    return 0;
}
