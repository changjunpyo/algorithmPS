#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int arr[20][20];

int abs_sum(int N, vector<int> &v){
	vector<int> t;
	for (int i=0; i<N; i++){
		bool flag= false;
		for (auto s: v){
			if (s == i)
				flag= true;
				break;
			}
		}
		if (!flag)
			t.push_back(i);
	}
	int sum_a=0;
	for (auto i:v){
		for (auto j:v){
			sum_a += arr[i][j];
		}
	}
	int sum_b=0;
	for (auto i:t){
		for (auto j:t){
			sum_b += arr[i][j];
		}
	}

	return abs(sum_b- sum_a);
}

int cmb(vector<int> &v, int N){
	if (v.size() == N/2){
		return  abs_sum(N, v);
	}
	int mn = 987654321;
	int start = v.back();
	for (int i=start+1; i<N; i++){
		v.push_back(i);
		int ret = cmb(v, NN);
		if (mn > ret)
			mn = ret;
		v.pop_back();
	}

	return mn;
}



int main(){
	int N;
	vector<int> v;
	scanf("%d",&N);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	v.push_back(0);
	printf("%d\n",cmb(v,N));

	return 0;
}