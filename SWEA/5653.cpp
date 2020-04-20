#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
const int dx[4] ={1,0,-1,0};
const int dy[4] ={0,1,0, -1};



int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		int N,M,K;
		cin >>N >>M>>K;
		vector<vector<int> > map(N+300, vector<int>(M+300,0));
		queue<pair<int,pair<int,int> > >activated_list;
		queue<pair<int,pair<int,int> > >prosper_list;
		queue<pair<int,pair<int,int> > >not_activated_list;
		for (int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> map[150+i][150+j];
				if (map[150+i][150+j] >0)
					not_activated_list.push(make_pair(map[150+i][150+j],make_pair(150+i,150+j)));
			}
		}
		
		while(K--){
			int n_size = not_activated_list.size();
			int p_size = prosper_list.size();
			int a_size = activated_list.size();

			for(int i=0; i<a_size; i++){
				auto item =activated_list.front();
				activated_list.pop();
				if (item.first > 1){
					item.first-=1;
					activated_list.push(item);
				}
			}
			vector<pair<int,pair<int,int> > >next_prosper;
			for (int i=0; i<n_size; i++){
				auto item = not_activated_list.front();
				not_activated_list.pop();
				if (item.first == 1){
					item.first = map[item.second.first][item.second.second];
					next_prosper.push_back(item);
				}
				else {
					item.first -=1;
					not_activated_list.push(item);
				}
			}
			sort(next_prosper.begin(), next_prosper.end(), greater<pair<int,pair<int,int> > >());
			for (int i=0; i<next_prosper.size(); i++){
				prosper_list.push(next_prosper[i]);
			}
			for (int i=0; i<p_size; i++){
				auto item = prosper_list.front();
				prosper_list.pop();
				for (int a=0; a<4; a++){
						int new_x = dx[a]+ item.second.first;
						int new_y = dy[a]+ item.second.second;
						if (map[new_x][new_y]==0){
							map[new_x][new_y] =map[item.second.first][item.second.second];
							not_activated_list.push(make_pair(map[new_x][new_y],make_pair(new_x,new_y)));
						}
				}
				item.first -= 1;
				if (item.first >0)
					activated_list.push(item);
			}
		}

		cout << "#"<<t<<" " <<activated_list.size()+ not_activated_list.size()+ prosper_list.size() <<"\n";
	}
}