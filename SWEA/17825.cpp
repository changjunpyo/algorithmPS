#include <iostream>
#include <vector>
using namespace std;

int ans= 0;
bool visited[33] = {false,};
const int map[33] ={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,40, 13,16,19,22,24,28,27,26,25,30,35};
const int START = 0;
const int END = 21;
const int TEN = 5;
const int TWENTY = 10;
const int THIRTY = 15;
const int FOURTY = 20;
const int BLUE_ONE = 22;
const int BLUE_TWO = 25;
const int BLUE_THREE = 27;
const int BLUE_FOUR = 30;

void move_dol(int num, vector<int> &dol, int move){
	if (dol[num] <= END && dol[num] != TEN && dol[num] != TWENTY && dol[num] != THIRTY){
		dol[num] += move;
		if (dol[num] > END){
			dol[num] = END;
		}
	} else if (dol[num] == TEN || (BLUE_ONE <= dol[num] &&dol[num] < BLUE_ONE+3)){
		if (dol[num] == TEN) dol[num] = BLUE_ONE-1;
		dol[num] += move;
		if ( dol[num]>= BLUE_ONE+3){
			move = dol[num]- (BLUE_ONE+3);
			dol[num] = BLUE_FOUR;
			move_dol(num, dol, move);
		} 
	} else if (dol[num] == TWENTY || (BLUE_TWO <= dol[num] &&dol[num] < BLUE_TWO+2)){
		if (dol[num] == TWENTY) dol[num] = BLUE_TWO-1;
		dol[num] += move;
		if (dol[num] >= BLUE_TWO+2){
			move = dol[num]- (BLUE_TWO+2);
			dol[num] = BLUE_FOUR;
			move_dol(num, dol, move);
		} 
	} else if (dol[num] == THIRTY || (BLUE_THREE <= dol[num] &&dol[num] < BLUE_THREE+3)){
		if (dol[num] == THIRTY) dol[num] = BLUE_THREE-1;
		dol[num] += move;
		if (dol[num]>= BLUE_THREE+3){
			move = dol[num]- (BLUE_THREE+3);
			dol[num] = BLUE_FOUR;
			move_dol(num, dol, move);
		} 
	} else{
		dol[num] += move;
		if (dol[num]>= BLUE_FOUR+3){
			move = dol[num]- (BLUE_FOUR+3);
			dol[num] = FOURTY;
			move_dol(num, dol , move);
		}
	}
}

void brute_force(vector<int> & v, vector<int> & dol, int cnt,int total){
	if (cnt == 10) {
		ans = max(ans, total);
	}

	for (int i=0; i<4; i++){
		int pos = dol[i];
		if (pos == END) continue;
		move_dol(i,dol, v[cnt]);
		if (visited[dol[i]]) {
			dol[i]= pos;
			continue;
		}
		visited[pos]= false;
		if (dol[i] != END){
			total += map[dol[i]];
			visited[dol[i]] = true;
		}
		brute_force(v,dol, cnt+1, total);
		if (dol[i] != END){
			total -= map[dol[i]];
		}
		visited[pos]= true;
		visited[dol[i]] = false;
		dol[i] = pos;
	}
}


int main(){
	vector<int> dol(4, 0);
	vector<int> v(10);
	for (int i=0; i<10; i++){
		cin >>v[i];
	}
	ans = 0;
	brute_force(v, dol, 0,0);

	cout <<ans <<"\n";
}