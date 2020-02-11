#include <cstdio>
#include <vector>
using namespace std;
const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,1,-1};
int map[101][101];

class Shark{
	public:
		Shark(int _r, int _c, int _d, int _s, int _z){
			r=_r;
			c=_c;
			d=_d;
			s=_s;
			z=_z;
			die = false;
		}
		int r;
		int c;
		int d;
		int s;
		int z;
		bool die;

		void move(int R, int C){
			int moving_r = s %(2*R-2);
			int moving_c = s %(2*C-2);
			
			if (d == 1){
				if (moving_r <= R-r){
					r += moving_r;
				}
				else if (moving_r <= R-r+ R-1){
					r += R-r -((moving_r - (R-r)));
					d= 0;
				}
				else 
					r = moving_r-(2*R-r-1) +1;
			}
			else if (d == 2){
				if (moving_c <= C-c){
					c += moving_c;
				}
				else if (moving_c <= 2*C-c-1){
					c += C-c-(moving_c -(C-c));
					d =3;
				}
				else 
					c = moving_c - (2*C-c-1) +1 ;
			}

			else if (d == 3){
				if ( c > moving_c )
					c -= moving_c;
				else if (moving_c <= C+c-2){
					c -= c -(moving_c -(c-1) +1);
					
					d = 2;
				}
				else
					c = (2*C-2)-moving_c + c ;
			}
			else {
				if ( r > moving_r )
					r -= moving_r;
				else if (moving_r <= R+r-2){
					r -= r -(moving_r -(r-1)+1);
					d = 1;
				}
				else
					r = (2*R-2)-moving_r +r ;
			}
			// 방향만 잡자
		}
};
int main(){
	int R,C,M;
	scanf("%d %d %d",&R,&C,&M);
	vector<Shark> v;
	v.reserve(M);
	int fishman_c = 0;
	int ans=0;
	memset(map, -1, sizeof(map));
	for (int i=0; i<M; i++){
		int r,c,s,d,z; 
		scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
		Shark shark(r,c,d-1,s,z);
		map[r][c] = i;
		v[i] = shark;
	}
	while(fishman_c <=C){
		// 낚시왕 움직 step1
		fishman_c++;
		// 낚시함 
		int catch_r=-1;
		// find shark
		for (int i=1; i<=R; i++){
			if (map[i][fishman_c] >=0){
				catch_r=i;
				map[i][fishman_c]=-1;
				break;
			}
		}
		// catch shark
		if (catch_r != -1){
			for (int i=0; i<M; i++){
				if (v[i].die)
					continue;
				if (v[i].r == catch_r && v[i].c == fishman_c){
					ans+= v[i].z;
					v[i].die = true;
				}
			}
		}
		// 상어 움직임
		int moved_map[101][101]={0,};
		memset(moved_map, -1, sizeof(moved_map));
		for (int i=0; i<M; i++){
			if (v[i].die)
				continue;
			v[i].move(R,C);
			if (moved_map[v[i].r][v[i].c] >= 0){
				int other = moved_map[v[i].r][v[i].c];
				if (v[i].z > v[other].z){
					moved_map[v[i].r][v[i].c] = i;
					v[other].die = true;
				}
				else
					v[i].die=true;
			}
			else 
				moved_map[v[i].r][v[i].c] = i;
		}
		for (int i=1; i<=R; i++){
			for (int j=1; j<=C; j++)
				map[i][j] = moved_map[i][j];
		}
	}
	printf("%d\n",ans);
}