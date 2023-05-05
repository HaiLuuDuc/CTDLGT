#include<bits/stdc++.h>
using namespace std;
void NhapMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
}
void XuatMang(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int Length(int n){
	int count=0;
	while(n){
		count++;
		n/=10;
	}
	return count;
}

void RadixSort(int arr[], int n){
	// xac dinh so cac chu so lon nhat	
	int maxLength = 0;
	for(int i=0;i<n;i++){
		if(Length(arr[i])>maxLength){
			maxLength=arr[i];
		}
	}

	map<int,queue<int> > mp;
	for(int k=0;k<maxLength;k++){

		// day tu arr vao map
		for(int i=0;i<n;i++){
			int tmp = ((arr[i]) % ((int)pow(10,k+1)))/(int)(pow(10,k));
			mp[tmp].push(arr[i]);
		}

		// day tu map vao arr 
		int index=0;		
		for(int i=0;i<10;i++){
			while(!mp[i].empty()){
				arr[index] = mp[i].front();
				mp[i].pop(); 
				index++;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	NhapMang(arr,n);
	RadixSort(arr,n);
	XuatMang(arr,n);
	return 0;
}
