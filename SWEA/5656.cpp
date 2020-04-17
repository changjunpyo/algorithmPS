#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int N,H,W;
int ans;
int explode(int x,int y,int depth, vector<vector<int> > &v){
	int count =0;
	for (int i= -depth+1; i<depth; i++){
		if (x+i >= 0 && x+i< H && v[x+i][y]){
			int now = v[x+i][y];
			v[x+i][y] = 0;
			count++;
			count += explode(x+i,y,now,v);
		}
		if (y+i>=0 && y+i<W && v[x][y+i]){
			int now = v[x][y+i];
			v[x][y+i] = 0;
			count++;
			count += explode(x,y+i,now,v);
		}
	}
	return count;
}

void downTheStone(vector<vector<int> > &v){
	for (int i=0; i<W; i++){
		int idx = H-1;
		for (int j=H-1; j>=0; j--){
			if (idx == j && v[j][i] >0) idx--;
			else if (v[j][i] >0 ) v[idx--][i] = v[j][i], v[j][i]=0;
		}
	}
}
	
int throwGem(int gem_count,int stone_count, vector<vector<int> > &v) {
	if (gem_count == N || stone_count ==0) return stone_count;
	int ret = stone_count;
	for(int i=0; i<W; i++){
		vector<vector<int> > new_v = v;
		for (int j=0; j<H; j++){
			if (new_v[j][i]>0){
				int now =new_v[j][i];
				new_v[j][i] = 0;
				int exploded = explode(j,i,now,new_v)+1;
				downTheStone(new_v);
				ret = min(ret,throwGem(gem_count+1, stone_count- exploded, new_v));
				break;
			}
		}
	}
	return ret;
}


int main(){
	int T;
	cin >>T;

	for (int t=1; t<=T; t++){
		ans = 0;
		cin >>N >>W>>H;
		int stone_count = H*W;
		vector<vector<int> > v(H, vector<int>(W));
		for (int i=0; i<H; i++){
			for (int j=0; j<W; j++){
				cin >>v[i][j];
				if (v[i][j]==0) stone_count--;
			}
		}
		ans = throwGem(0,stone_count,v);
		cout << "#"<<t<<" " <<ans <<"\n";
	}
}