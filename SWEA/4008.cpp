#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
int ans_min = 100000001;
int ans_max =-100000001;
void count(int cnt, vector<int> &num , vector<int> &op,int N, int now){
	if (cnt == N-1){
		ans_max = max(now, ans_max);
		ans_min = min(now, ans_min);
		return;
	}

	for (int i=0; i<4; i++){
		if (op[i] >0){
			op[i]--;
			if (i==0){
				count(cnt+1, num, op, N, now+num[cnt+1]);
			}
			else if (i==1){
				count(cnt+1, num, op, N, now-num[cnt+1]);
			}
			else if (i==2){
				count(cnt+1, num, op, N, now*num[cnt+1]);
			}
			else if (i==3){
				count(cnt+1, num, op, N, now/num[cnt+1]);
			}
			op[i]++;
		}
	}
	return ;
}

int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		ans_min = 100000001;
		ans_max =-100000001;
		int N;
		vector<int> op(4);
		cin >>N;
		vector<int> num(N);
		for (int i=0; i<4; i++)
			cin >>op[i];
		for (int i=0; i<N; i++)
			cin >>num[i];
		count(0,num,op,N,num[0]);
		cout << "#"<<t<<" " <<ans_max- ans_min <<"\n";
	}
}