#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int BO= 1;
const int COL = 2;
int map[101][101]={0,};
bool check_Bo(int x, int y,int n){
	if ((map[x-1][y] & COL) || (map[x-1][y+1]& COL)) return true;
	if (y >0 && y<N-1 && (map[x][y-1] &BO ) &&(map[x][y+1])) return true;
	return false;

}
bool check_Col(int x, int y){
	if (x ==0) return true;
	if (map[x][y] > 0 || (map[x-1][y] & BO) ) return true;
}	return false;

bool check(int x, int y, int a, int b, int n){
	if (b){
		if (a){
			return check_Bo(x,y,n);
		}
		else{
			return check_Col(x,y,n);
		}
	}
	else {
		if (a){
			map[x][y] ^= BO;
			bool flag = true;
			if (x <N &&(map[x+1][y] & COL)) flag = (flag && check_Col(x-1,y,n));
			if (x <N&& (map[x+1][y+1] & COL)) flag = (flag && check_Col(x-1,y+1,n));
			if (y >0 && (map[x][y-1] &BO)) flag = (flag &&check_Bo(x,y-1,n));
			if (map[x][y+1]& BO) flag = (flag && check_Bo(x,y+1,n));
			map[x][y] ^= BO;
			return flag;
		}
		else{
			map[x][y] ^= COL;
			bool flag = true;
			if (x <N && (map[x+1][y] & COL))  flag = (flag && check_Col(x-1,y,n));
			if (map[x][y] &BO) flag (flag &&check_Bo(x,y,n))
			if (y> 0 && (map[x][y-1] &BO)) flag (flag &&check_Bo(x,y-1,n))
			map[x][y] ^= COL;
			return flag;
		}
	}
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (int i=0; i<build_frame.size(); i++){
    	if (check(build_frame[i][0],build_frame[i][1],build_frame[i][2],build_frame[i][3],n)){
    		if (build_frame[2] == 1)
    			map[build_frame[i][0]][build_frame[i][1]] ^= BO;
    		else
    			map[build_frame[i][0]][build_frame[i][1]] ^= COL;
    	}
    }

    for (int i=0; i<=n; i++){
    	for (int j=0; j<=n; j++){
    		cout <<map[i][j] <<" ";
    	}
    	cout <<"\n";
    }
    return answer;
}