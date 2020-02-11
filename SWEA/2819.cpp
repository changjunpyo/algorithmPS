#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
char map[4][4];
void find_seven_word(int depth, unordered_set<string> &v, int c,int r, string s){
	if (depth == 6){
		s += map[c][r];
		auto f = v.find(s);
		if (f == v.end()){
			v.insert(s);
		}
		return;
	}
	s += map[c][r];
	if (c < 3){
		find_seven_word(depth+1, v, c+1,r, s);
	}
	if (c > 0){
		find_seven_word(depth+1, v, c-1,r, s);
	}
	if (r < 3){
		find_seven_word(depth+1, v, c,r+1, s);
	}
	if (r > 0){
		find_seven_word(depth+1, v, c,r-1, s);
	}
	return ;
}	


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >>T;

	for (int i=0; i<T; i++){
		unordered_set<string> v;
		for (int j=0; j<4; j++){
			for (int k=0; k<4; k++){
				cin >> map[j][k];
			}
		}
		for (int j=0; j<4; j++){
			for (int k=0; k<4; k++){
				string s;
				find_seven_word(0, v, j,k,s);
			}
		}
		int sum = v.size();
		cout <<"#"<<i+1<<" "<<sum<<"\n";

	}
}