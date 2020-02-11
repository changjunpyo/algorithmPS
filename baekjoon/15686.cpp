#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void make_case_list(vector<vector<int> > &list, int M, int max_chicken, vector<int> &v,int idx){
	if (v.size() == M){
		list.push_back(v);
		return;
	}

	for (int i=idx; i<max_chicken; i++){
		v.push_back(i);
		make_case_list(list,M,max_chicken,v,i+1);
		v.pop_back();
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	vector<pair<int,int> > house;
	vector<pair<int,int> > chicken;
	cin >> N >> M;
	for (int i=0 ; i<N; i++){
		for(int j=0; j<N; j++){
			int v;
			cin >> v;
			if (v == 1)
				house.push_back(make_pair(i,j));
			if (v ==2)
				chicken.push_back(make_pair(i,j));
		}
	}
	vector<vector<int> > list;
	vector<int> v;
	make_case_list(list,M,chicken.size(), v, 0);

	int mn = 987654321;
	for (auto a: list){
		int ans =0;
		for (auto x : house){
			int dist = 987654321;
			for (auto y: a){
				int d = abs(x.first - chicken[y].first) + abs(x.second - chicken[y].second);
				dist = min (dist, d);
			}
			ans += dist;
		}
		mn = min(mn, ans);
	}
	cout << mn <<"\n";




}