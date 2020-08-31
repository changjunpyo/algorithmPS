#include<iostream>
using namespace std;

int main(){
 int N, M;
 cin >> N >> M;
 int arr[10001],pSum[10001];
 for (int i=1; i<=N; i++){
  cin >>arr[i];
  pSum[i] = pSum[i-1] + arr[i];
 }
 int ans =0;
 int f=0, s=1;
 while( s <= N){
  if (pSum[s] - pSum[f] == M){
	ans++;
	f++;
  } else if (pSum[s]- pSum[f] > M){
    f++; 
  } else {
    s++;
  }
 }
 cout << ans <<"\n";
 return 0;
}

