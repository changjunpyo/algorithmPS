#include <iostream>
#include <cmath>
using namespace std;

int main (){
  int dp[50001]={0,};
  dp[1] = 1;
  int n;
  cin >>n;  

  for (int i=2 ; i<=n; i++){
   int x = (int)sqrt(i);
   dp[i] = 10;
   for (int j=x; j>0; j--){
    dp[i] = min(dp[i], dp[i-j*j] +1);
   }
  }
 cout << dp[n]<<"\n";



}
