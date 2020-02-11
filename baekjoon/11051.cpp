#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool match(const string &s ,const vector<string> &w, int idx, int s_num,int N){
	int a=0;
	while(idx < s.size() && a < w[s_num].size()){
		if (s[idx] !=w[s_num][a])
			return 0;
		idx++;
		a++;
	}
	if (idx == s.size() && a==w[s_num].size())
		return 1;
	if (a== w[s_num].size()){
		for (int i=0; i<N; i++){
			if (match(s,w,idx,i,N))
				return 1;
		}
		return 0;
	}
		return 0;

}


int main(){
	string s;
	int N;
	cin >>s;
	cin >>N;
	vector<string> w(N);
	for (int i=0; i<N; i++){
			cin >> w[i];
	}

	for (int i=0; i<N; i++){
		if (match(s,w,0,i,N)){
			printf("1\n");
			return 0;
		}
	}

	printf("0\n");
	return 0;

}
