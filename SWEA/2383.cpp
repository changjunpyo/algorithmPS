#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int map[10][10]={0,};
int N;
int simulate(vector<pair<int,int> > human,pair<int,pair<int,int> > stairs[], vector<bool> &check){
	int t =0;
	vector<int> s1,s2;
	int idx1=0, idx2=0;
	int count =0;
	while(1){
		//cout <<t <<" "<<count <<"idx1 "<<idx1 <<" idx2 "<<idx2 <<"\n";
		if (count == check.size()) break;
		while(idx1 <s1.size() && s1[idx1] == 0){
			idx1++;
			count++;
		}
		while(idx2 <s2.size() && s2[idx2] == 0){
			idx2++;
			count++;
		}
		for (int i=idx1; i < s1.size() &&i< idx1+3; i++){
			s1[i]--;
		}
		for (int i=idx2; i < s2.size() &&i< idx2+3; i++){
			s2[i]--;
		}
		for (int i=0; i<human.size();i++){
			//cout <<i <<" " <<human[i].first<< " "<<human[i].second<<"\n";
			if (check[i]){
				if (human[i] == stairs[0].second) continue;
				else{ 
					if (stairs[0].second.first- human[i].first >0)
						human[i].first++;
					else if (stairs[0].second.first- human[i].first <0)
						human[i].first--;
					else if (stairs[0].second.second- human[i].second >0)
						human[i].second++;
					else if (stairs[0].second.second- human[i].second <0)
						human[i].second--;

					if (human[i] == stairs[0].second)
						s1.push_back(stairs[0].first);
				}
			}
			else{
				if (human[i] == stairs[1].second) continue;
				else{
					if (stairs[1].second.first- human[i].first >0)
						human[i].first++;
					else if (stairs[1].second.first- human[i].first <0)
						human[i].first--;
					else if (stairs[1].second.second- human[i].second >0)
						human[i].second++;
					else if (stairs[1].second.second- human[i].second <0)
						human[i].second--;

					if (human[i] == stairs[1].second)
						s2.push_back(stairs[1].first);
				}
			}
		}
	t++;
	}
	return t;
}


int makeAllCase(int count,vector<bool> &check,vector<pair<int,int> > &human, pair<int,pair<int,int> > stairs[]){
	if (count == check.size()){
		return simulate(human,stairs,check);
	}
	int ret = 987654321;
	for (int i=count; i<check.size(); i++){
		check[i] = true;
		ret =min(ret,makeAllCase(i+1, check,human,stairs));
		check[i] = false;
		ret = min(ret, simulate(human,stairs,check));
	}
	return ret;
}

int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		cin >>N;
		pair<int,pair<int,int> > stairs[2];
		int idx =0;
		vector<pair<int,int> > human;

		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				cin >>map[i][j];
				if (map[i][j] == 1){
					human.push_back(make_pair(i,j));
				}
				if (map[i][j] >1){
					stairs[idx++] = make_pair(map[i][j], make_pair(i,j));
				}
			}
		}
		vector<bool> check(human.size(),0);
		int ans = makeAllCase(0,check,human, stairs);
		cout <<"#"<<t<<" "<<ans<<"\n";
	}
}