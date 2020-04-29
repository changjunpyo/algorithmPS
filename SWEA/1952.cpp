#include <iostream>
using namespace std;


int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		int d,m,q,y;
		cin >>d>>m>>q>>y;
		int month[13]={0,};
		int dp[13] ={0,};
		for (int i=1; i<13; i++){
			cin >>month[i];
		}

		dp[0] = 0;
		dp[1] = min(m , d*month[1]);
		dp[2] = min(m , d*month[2]) + dp[1];
		for (int i=3; i<=12; i++){
			dp[i] = min(min(m , d*month[i]) + dp[i-1], q+ dp[i-3]); 
		}
		dp[12] = min(y, dp[12]);
		cout <<"#"<<t<<" "<<dp[12]<<"\n";
	}
	return 0;
}