#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int map[20][20];
int N,M,oil;
// return 
pair<int,int> find_shortest_passenger(int x,int y){
	if (map[x][y] < 0){
		int pass =  map[x][y]*-1;
		map[x][y] = 0;
		return make_pair(0, pass -1);
	}
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	int count =0;
	bool visited[20][20] = {false};
	vector<pair<int,int>> ans;
	bool finish = false;
	visited[x][y] = true;
	while(!q.empty()){
		count++;
		int q_size = q.size();
		for (int i=0; i<q_size; i++){
			pair<int,int> pos = q.front();
			q.pop();
			for (int k=0; k<4; k++){
				int new_x = dx[k] + pos.first;
				int new_y = dy[k] + pos.second;
				if (new_x <0 || new_x>=N || new_y <0 || new_y >=N) continue;
				if (map[new_x][new_y] == 1||  visited[new_x][new_y]) continue;
				if (map[new_x][new_y] <0) {
					ans.push_back(make_pair(new_x,new_y));
					visited[new_x][new_y]= true;
					finish= true;

				}
				q.push(make_pair(new_x,new_y));
				visited[new_x][new_y]= true;
			}
		}
		if (finish){
			sort( ans.begin(),ans.end());
			int pass = map[ans[0].first][ans[0].second] *-1;
			map[ans[0].first][ans[0].second] = 0;
			return make_pair(count, pass-1);
		}
	}

	return make_pair(-1,-1);
}

int find_min_way(pair<int,int> s , pair<int,int> e){
	queue<pair<int,int>> q;
	q.push(make_pair(s.first,s.second));
	int count =0;
	bool visited[20][20] = {false};
	while(!q.empty()){
		int q_size = q.size();
		count++;
		for (int i=0; i<q_size; i++){
			pair<int,int> pos = q.front();
			q.pop();
			for (int k=0; k<4; k++){
				int new_x = dx[k] + pos.first;
				int new_y = dy[k] + pos.second;
				if (new_x <0 || new_x>=N || new_y <0 || new_y >=N) continue;
				if (map[new_x][new_y] == 1||  visited[new_x][new_y]) continue;
				if (e == make_pair(new_x, new_y)) return count;
				q.push(make_pair(new_x,new_y)); 
				visited[new_x][new_y]= true;
			}
		}
	}
	return -1;
}

int main(){
	cin>>N>>M>>oil;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin >>map[i][j];
		}
	}

	int x, y;
	vector<pair<int,int>> s(M);
	vector<pair<int,int>> e(M);
	cin >>x >>y;
	x--;
	y--;
	for (int i=0; i<M; i++){
		cin >>s[i].first >>s[i].second;
		cin >>e[i].first >>e[i].second;
		s[i].first--;
		s[i].second--;
		e[i].first--;
		e[i].second--;
		map[s[i].first][s[i].second] = -1*(i+1);
	}
		
	while (oil >= 0){
		if (M ==0) {cout <<oil<<"\n"; return 0;};
		pair<int,int> p = find_shortest_passenger(x,y);
		if (p.first== -1) break;
		oil -= p.first;
		if (oil <= 0) break;
		int dis =  find_min_way(s[p.second], e[p.second]);
		if (dis == -1) break;
		oil -= dis;
		if (oil <0) break;
		oil += 2*dis;
		M--;
		x = e[p.second].first;
		y = e[p.second].second;
	
	}
	cout <<"-1\n";
	return 0;
}