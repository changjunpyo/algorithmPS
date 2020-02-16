#include <bits/stdc++.h>
using namespace std;

int init(vector<int> &tree, vector<int> &arr, int s, int e, int node){
	if (s==e){
		return tree[node] = arr[s];
	}

	else{
		tree[node] = (init(tree, arr,s,(s+e)/2,node*2)^init(tree, arr,(s+e)/2+1,e,node*2+1));
	}

	return tree[node];
}

int find_ranged_xor(vector<int> &tree,vector<int> &lazy, int s, int e, int node , int l, int r){
	if (s >r || e <l)
		return 0;

	if (lazy[node] != -1){
		if (s != e){
			if (lazy[node*2] == -1)
				lazy[node*2] = lazy[node]; 
			else
				lazy[node*2] ^= lazy[node];
			if (lazy[node*2+1] == -1)
				lazy[node*2+1] = lazy[node]; 
			else
				lazy[node*2+1] ^= lazy[node];
		}
		if ((e-s+1)%2 == 1)
			tree[node] ^=lazy[node];
		lazy[node] = -1; 
	}

	if (l <=s && e <= r)
		return tree[node];
	int left = find_ranged_xor(tree,lazy,s,(s+e)/2,node*2, l,r);
	int right = find_ranged_xor(tree,lazy,(s+e)/2+1,e,node*2+1, l,r);
	
	return (left^right);
}

void update(vector<int> &tree,vector<int> &lazy, int s, int e, int node , int l, int r, int c){
	if (s > r || e< l)
		return;

	if (l <=s && e<= r){
		if (lazy[node]== -1)
			lazy[node] = c;
		else
			lazy[node] ^= c;
		return;
	}
	else if (s<= l && l <= e && e <= r && (e-l+1)%2 == 1)
		tree[node] ^= c;
	else if (s<= r && r <= e && l <= s && (r-s+1)%2 == 1)
		tree[node] ^= c;
	else if (s<=l && r <= e && (r-l+1)%2 == 1){
		tree[node] ^=c;
	}
	if (s != e){
		update(tree,lazy,s,(s+e)/2,node*2, l,r,c);
		update(tree,lazy,(s+e)/2+1,e,node*2+1, l,r,c);
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >>N;
	vector<int> arr(N);
	int h = (int) ceil(log2(N+1));
	int tree_size = (1<<(h+1));
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size,-1);
	for (int i=0; i<N; i++)
		cin >>arr[i];

	init(tree, arr, 0,N-1, 1);
	cin >>M;

	while(M--){

		int t,a,b,c;
		cin >>t;
		if (t==1){
			cin >> a>>b>>c;
			if (a < b)
				update(tree, lazy, 0,N-1,1,a,b,c);
			else
				update(tree, lazy, 0,N-1,1,b,a,c);
		}
		else{
			cin >>a>>b;
			if (a <b)
				cout <<find_ranged_xor(tree,lazy,0,N-1,1,a,b)<<"\n";
			else
				cout <<find_ranged_xor(tree,lazy,0,N-1,1,b,a)<<"\n";
		}
	}

}