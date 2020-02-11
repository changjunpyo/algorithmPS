#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];

int binary_search(int num,int size){
	int l= 0;
	int r = size;

	while(l <r){
		int mid = (l+r)/2;
		if (arr[mid] >= num)
			r= mid;
		else
			l= mid+1;
		
	}
	return l;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >>N;
	for (int i=0; i<N; i++)
		cin >>arr[i];

	sort(arr, arr+N);
	cin >>M;
	for (int i=0; i<M; i++){
		int num;
		cin >>num;
		int idx= binary_search(num,N-1);
		int idx2= binary_search(num+1,N-1);
		if (arr[idx2] == num)
			cout <<idx2- idx+1<<" ";
		else
			cout <<idx2- idx <<" ";
	}
	cout <<"\n";
	return 0;
}