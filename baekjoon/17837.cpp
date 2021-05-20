#include <iostream>
#include <vector>
using namespace std;
const int dx[4] ={0,0,-1,1};
const int dy[4] ={1,-1,0,0};
int N,K;
class Piece{
public:
	int num;
	pair<int,int> pos;
	int dir;
};
class Map{
public: 
	vector<Piece> pieces;
	int color;

	void erase_piece(int num){
		for (int i=0; i<pieces.size(); i++){
			if (pieces[i].num == num){
				pieces.erase(pieces.begin() + i);
				break;
			}
		}
	}
	void add_piece(vector<Piece> &p, int num){
		pieces.push_back(p[num]);
	}

	vector<Piece> find_pieces(int num){
		vector<Piece> ret;
		bool flag = false;
		for (int i=0; i<pieces.size(); i++){
			if (flag || pieces[i].num == num){
				flag = true;
				ret.push_back(pieces[i]);
			}
		}
		return ret;
	}
};
Map m[12][12];

int move(vector<Piece> &p, int num){
	pair<int,int> n_p = make_pair(p[num].pos.first+dx[p[num].dir], p[num].pos.second+dy[p[num].dir]);
	if (n_p.first >= 0 && n_p.first <N && n_p.second>=0 && n_p.second <N && m[n_p.first][n_p.second].color !=2){
		auto poss_pieces = m[p[num].pos.first][p[num].pos.second].find_pieces(num);
			if (m[n_p.first][n_p.second].color ==0){
				for (int i=0; i<poss_pieces.size(); i++){
					m[poss_pieces[i].pos.first][poss_pieces[i].pos.second].erase_piece(poss_pieces[i].num);
					p[poss_pieces[i].num].pos = n_p;
					m[n_p.first][n_p.second].add_piece(p, poss_pieces[i].num);
				}
			} else{
				for (int i=poss_pieces.size()-1; i>=0; i--){
					m[poss_pieces[i].pos.first][poss_pieces[i].pos.second].erase_piece(poss_pieces[i].num);
					p[poss_pieces[i].num].pos = n_p;
					m[n_p.first][n_p.second].add_piece(p, poss_pieces[i].num);
				}
			}
		return m[n_p.first][n_p.second].pieces.size();
	}
	else{
		if (p[num].dir %2 ==0){
			p[num].dir +=1;
		} else{
			p[num].dir -=1;
		}
		n_p = make_pair(p[num].pos.first+dx[p[num].dir], p[num].pos.second+dy[p[num].dir]);
		if (n_p.first >= 0 && n_p.first <N && n_p.second>=0 && n_p.second <N && m[n_p.first][n_p.second].color !=2){
			
			auto poss_pieces = m[p[num].pos.first][p[num].pos.second].find_pieces(num);
			if (m[n_p.first][n_p.second].color ==0){
				for (int i=0; i<poss_pieces.size(); i++){
					m[poss_pieces[i].pos.first][poss_pieces[i].pos.second].erase_piece(poss_pieces[i].num);
					p[poss_pieces[i].num].pos = n_p;
					m[n_p.first][n_p.second].add_piece(p, poss_pieces[i].num);
				}
			} else{
				for (int i=poss_pieces.size()-1; i>=0; i--){
					m[poss_pieces[i].pos.first][poss_pieces[i].pos.second].erase_piece(poss_pieces[i].num);
					p[poss_pieces[i].num].pos = n_p;
					m[n_p.first][n_p.second].add_piece(p, poss_pieces[i].num);
				}
			}
			return m[n_p.first][n_p.second].pieces.size();
		}
		return m[p[num].pos.first][p[num].pos.second].pieces.size(); 
	}
	return m[n_p.first][n_p.second].pieces.size();
}

int main(){
	cin >>N >>K;
	vector<Piece> pieces(K);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin >> m[i][j].color;
		}
	}
	for (int i=0; i<K; i++){
		int x, y, dir;
		cin >>x >>y >>dir;
		pieces[i].num = i;
		pieces[i].pos = make_pair(x-1,y-1);
		pieces[i].dir = dir-1;
		m[x-1][y-1].pieces.push_back(pieces[i]);
	}
	int count = 1;
	while (count <=1000){
		for (int i=0; i<K; i++){
			if (move(pieces, i) >=4) {
				cout << count <<"\n";
				return 0;
			}
		}
		count++;
	}
	cout <<"-1\n";
	return 0;

}