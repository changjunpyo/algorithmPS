#include <iostream>
#include <vector>
#include <queue>
using namespace std;
pair<int,int> reception[10];
pair<int,int> repair[10];
int reception_time[10]={0,};
int repair_time[10]={0,};
int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		queue<int> waitA;
		queue<int> waitB;
		int N,M,K,A,B;
		cin >>N >>M>> K>> A>>B;
		int count_reception = N;
		int count_repair = M;
		vector<bool> flag(K, false);
		for (int i=0; i<N; i++){
			reception[i].second =0;
			cin >>reception_time[i];
		}

		for (int i=0; i<M; i++){
			repair[i].second =0;
			cin >>repair_time[i];
		}

		vector<int> time(K);
		for (int i=0; i<K; i++)
			cin >>time[i];
		int ans =0;
		int idx =0;
		for (int i=0; i<20000; i++){
			if (idx == K && count_reception == N && count_repair == M && waitA.size() ==0 && waitB.size() ==0) break;
			while (idx < K && time[idx] == i){
				waitA.push(idx);
				idx++;
			}
			if (count_reception < N){
				for (int j=0; j<N; j++){
					if (reception[j].second == 0) continue;
					else{
						reception[j].second--;
						if (reception[j].second ==0) {
							count_reception++;
							waitB.push(reception[j].first);
						}
					}
				}
			}

			while(!waitA.empty() && count_reception >0){
				int num = waitA.front();
				waitA.pop();
				for (int j=0; j<N; j++){
					if (reception[j].second > 0) continue;
					else{
						reception[j] = make_pair(num,reception_time[j]);
						if (j == A-1) flag[num] = true;
						count_reception--;
						break;
					}
				}
			}
			if (count_repair < M){
				for (int j=0; j<M; j++){
					if (repair[j].second == 0) continue;
					else{
						repair[j].second--;
						if (repair[j].second ==0) {
							count_repair++;
						}
					}
				}
			}

			while(!waitB.empty() && count_repair >0){
				int num = waitB.front();
				waitB.pop();
				for (int j=0; j<M; j++){
					if (repair[j].second > 0) continue;
					else{
						repair[j] = make_pair(num,repair_time[j]);
						if (j == B-1 && flag[num]){
							ans += (num+1);
						}
						count_repair--;
						break;
					}
				}
			}
		}
		if (ans == 0) ans =-1;
		cout <<"#"<<t<<" "<<ans<<"\n";
	}
}