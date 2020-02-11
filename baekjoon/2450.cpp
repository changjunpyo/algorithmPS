#include <cstdio>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(){
	int N;
	//0: 123
	//1: 132
	//2: 213
	//3: 231
	//4: 312
	//5: 321
	int l[100000];
	int mo[4]={0,0,0,0};
	scanf("%d",&N);
	for (int i=0; i<N; i++){
		scanf("%d",&l[i]);
		mo[l[i]]++;
	}
	const int x[6][3]={
		{1,2,3},
		{1,3,2},
		{2,1,3},
		{2,3,1},
		{3,1,2},
		{3,2,1}
	};


	int mn = 987654321;
	for (int mx_idx=0; mx_idx<6; mx_idx++){
		int a[3][4]={0,};
		for (int i=0; i<mo[x[mx_idx][0]]; i++){
			a[0][l[i]]++;
		}
		for (int i=mo[x[mx_idx][0]]; i<mo[x[mx_idx][0]]+mo[x[mx_idx][1]]; i++){
			a[1][l[i]]++;
		}
		for (int i=mo[x[mx_idx][0]]+mo[x[mx_idx][1]]; i<mo[x[mx_idx][0]]+mo[x[mx_idx][1]]+mo[x[mx_idx][2]]; i++){
			a[2][l[i]]++;
		}
		int ans = 0;
		int q =min(a[0][x[mx_idx][1]], a[1][x[mx_idx][0]]);
		int w =min(a[0][x[mx_idx][2]], a[2][x[mx_idx][0]]);
		int e =min(a[1][x[mx_idx][2]], a[2][x[mx_idx][1]]);
		ans += (q+w+e) + 2*abs(a[0][x[mx_idx][1]]-a[1][x[mx_idx][0]]);
		mn = min(mn, ans);
	}
	 printf("%d\n", mn);

	



}