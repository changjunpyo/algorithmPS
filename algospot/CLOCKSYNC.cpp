#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 9999;
const int SWITCHES = 10;
const int CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1]={
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool checkAlign(const vector<int> &clock){
	for (auto i : clock){
		if (i != 12)
			return false;
	}
	return true;
}


void push(vector<int> &clock, int swch){
	for (int i=0; i<CLOCKS; i++){
		if (linked[swch][i] == 'x'){
			clock[i] += 3;
		}
		if (clock[i] == 15)
			clock[i] = 3;
	}
}

int solve(vector<int> &clock, int swch){
	if (swch == SWITCHES) return checkAlign(clock) ? 0 : INF;

	int ret = INF;
	for (int i=0; i<4; i++){
		ret = min(ret, i+ solve(clock, swch+1));
		push(clock, swch);
	}
	return ret;
}


int main(){
	int T;
	cin >> T;
	for (int t=0; t<T; t++){
		vector<int> clock(16);
		for (int i=0; i<CLOCKS; i++)
			cin >> clock[i];

		int ans = solve(clock,0);
		if (ans >= INF)
			ans = -1;
		cout << ans <<"\n";
	}
}