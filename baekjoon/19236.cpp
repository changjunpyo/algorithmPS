#include <iostream>
#include <vector>
using namespace std;
pair<int,int> map[4][4];
const int dx[9] = {0,-1,-1,0,1,1,1,0,-1}; 
const int dy[9] = {0,0,-1,-1,-1,0,1,1,1}; 
vector<pair<int,int>> fish(16);
pair<int,int> shark = make_pair(0,0);
void move_fish(){

	for (int i=0; i<16; i++){
		if (fish[i].first ==-2) continue;
		int x = fish[i].first;
		int y = fish[i].second;
		int new_x = fish[i].first + dx[map[x][y].second];
		int new_y = fish[i].second + dy[map[x][y].second];
		int count = 0;
		while(new_x<0 || new_x>=4 || new_y<0 || new_y>=4 || map[new_x][new_y].first == -1){
			if (count == 8) break;
			count++;
			map[x][y].second = (map[x][y].second+1) % 9;
			if (map[x][y].second == 0) map[x][y].second = 1;
			new_x = fish[i].first + dx[map[x][y].second];
			new_y = fish[i].second + dy[map[x][y].second];
		}
		if (count ==8) continue;

		if (map[new_x][new_y].first== -2){
			auto temp = map[x][y];
			map[x][y] = map[new_x][new_y];
			map[new_x][new_y] = temp;
			fish[i]= make_pair(new_x, new_y);
		} else if (map[new_x][new_y].first>= 0) {
			auto temp = map[x][y];
			map[x][y] = map[new_x][new_y];
			map[new_x][new_y] = temp;
			fish[i]= make_pair(new_x, new_y);
			fish[map[x][y].first] = make_pair(x,y);
		}
	}
}
int all_shark_move(int total){
	
	int ret = total;
	pair<int,int> save_map[4][4];
	vector<pair<int,int>> save_fish(16);
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			save_map[i][j] = map[i][j];
	for (int i=0; i<16; i++)
		save_fish[i] = fish[i];
	move_fish();
	
	for (int i=1; i<4; i++){

		int x = shark.first;
		int y = shark.second;
		int new_x= x + dx[map[x][y].second]*i;
		int new_y= y + dy[map[x][y].second]*i;

		if (new_x < 0 || new_x >=4 || new_y <0 || new_y >=4) continue;
		if (map[new_x][new_y].first < 0) continue;
		auto restore_shart = shark;
		auto restore_map = map[x][y];
		map[x][y] = make_pair(-2,-1);
		int eaten_fith = map[new_x][new_y].first;
		map[new_x][new_y].first = -1;
		fish[eaten_fith].first = -2;
		shark = make_pair(new_x, new_y);
		ret = max(ret,all_shark_move(total+eaten_fith+1));
		fish[eaten_fith]= make_pair(new_x, new_y);
		map[x][y] = restore_map;
		map[new_x][new_y].first = eaten_fith;
		shark = restore_shart;
	}
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			map[i][j] = save_map[i][j];
	for (int i=0; i<16; i++)
		fish[i] = save_fish[i];
	return ret;
}

int main(){
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			int a,b;
			cin >>a >>b;
			map[i][j] = make_pair(a-1,b);
			fish[a-1] = make_pair(i,j);
		}
	}
	int eaten_fish = map[0][0].first+1;
	fish[eaten_fish-1].first = -2;
	map[0][0] = make_pair(-1, map[0][0].second);
	cout << all_shark_move(eaten_fish)<<"\n";

	return 0;

}