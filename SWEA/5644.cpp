#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
const int dx[5] = {0,-1,0,1,0};
const int dy[5] = {0, 0,1,0,-1};
pair<int,int> p_a = make_pair(0,0);
pair<int,int> p_b = make_pair(9,9);


int check_inside_AP(const vector<vector<int> > &AP){
	int max_a =0;
	int prev_a = 0;
	int idx1 = -1;
	int idx2 = -1;
	int max_b =0;
	int prev_b=0;
	for (int i=0; i<AP.size(); i++){
		if (abs(p_a.first-AP[i][1]) + abs(p_a.second-AP[i][0]) <= AP[i][2]){
			if (max_a < AP[i][3]){
				idx1 = i;
				prev_a = max_a;
				max_a = AP[i][3];
			} else if (prev_a < AP[i][3])
				prev_a = AP[i][3];
		}
		if (abs(p_b.first-AP[i][1]) + abs(p_b.second-AP[i][0]) <= AP[i][2]){
			if (max_b < AP[i][3]){
				idx2 = i;
				prev_b = max_b;
				max_b = AP[i][3];
			}
			else if (prev_b < AP[i][3])
				prev_b = AP[i][3];
		}

	}
	if (idx1 != -1 && idx1 == idx2)
		max_b = max(prev_a,prev_b);
	return max_a+ max_b;

}

int main(){
	int T;
	cin >>T;

	for (int t=1; t<=T; t++){
		int ans =0;
		int M, A;
		cin >>M >>A;
		vector<vector<int> > move(2, vector<int>(M));
		for (int i=0; i<2; i++){
			for (int j=0; j<M; j++){
				cin >>move[i][j];
			}
		}
		vector<vector<int> > AP(A,vector<int>(4));
		for (int i=0; i<A; i++){
			for(int j=0; j<4; j++){
				cin >>AP[i][j];
				if (j<2)
					AP[i][j]-= 1;
			}
		}
		p_a = make_pair(0,0);
		p_b = make_pair(9,9);
 		for (int i=0; i<=M; i++){

 			ans += check_inside_AP(AP);
 			if (i== M) break;
 			p_a = make_pair(p_a.first+dx[move[0][i]], p_a.second+dy[move[0][i]]);
 			p_b = make_pair(p_b.first+dx[move[1][i]], p_b.second+dy[move[1][i]]);
 		}


		cout << "#"<<t<<" " <<ans <<"\n";
	}
}