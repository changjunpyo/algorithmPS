#include <bits/stdc++.h>
using namespace std;
const int dx[4]={0,-1,0,1};
const int dy[4]={1,0,-1,0};
int r1,c1,r2,c2;
int arr[50][50]={0,};
int mx;
int mx_count=0;
void find(int dir, int r, int c, int depth,int num){
	while(-depth<=r && r<=depth && -depth<=c && c<=depth){
		if (r1<=r && r<=r2  && c1 <=c && c <=c2){
			arr[r-r1][c-c1] = num;
			mx_count = max(mx_count,num);
		}
		if (r==c && depth == r){
			depth++;
			c = c+1;
			r = r;
			dir = 1;
			num++; 
			continue;
		}
		r = r+dx[dir];
		c = c+dy[dir];
		num++;
		if (abs(r) == abs(c))
			dir = (dir+1)%4;
		if (depth > mx)
			break;
	}
}



int main(){
	cin >>r1 >> c1 >> r2>> c2;
	mx = max (abs(r1), max(abs(r2), max(abs(c1),abs(c2))));
	find(3,0,0,0,1);
	int count=0;
	while(mx_count){
		mx_count /= 10;
		count++;
	}
	for (int i=0; i<r2-r1+1; i++){
		for (int j=0; j<c2-c1+1; j++){
			if (arr[i][j] == 0)
				continue;
			else{
				cout.width(count);
				cout.fill(' ');
				cout <<arr[i][j] <<" ";
			}
		}
		cout <<"\n";
	}
}