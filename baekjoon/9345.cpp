#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
pair<int,int> init(vector<pair<int,int> > &tree, const vector<int> &dvd, int node, int s, int e){
	if (s == e)
		return tree[node] = make_pair(dvd[s],dvd[s]);
	pair<int,int> a = init(tree,dvd,node*2, s,(s+e)/2);
	pair<int,int> b = init(tree,dvd,node*2+1, (s+e)/2+1,e);
	int mx = max(a.second, b.second);
	int mn = min(a.first, b.first);
	return tree[node] = make_pair(mn,mx);
}

pair<int,int> find_min_max(vector<pair<int,int> > &tree, int node, int s, int e, int l, int r){
	if (e <l || s > r)
		return make_pair(987654321, -1);

	if (l <= s && e <= r)
		return tree[node];

	pair<int,int> a = find_min_max(tree,node*2, s,(s+e)/2,l,r);
	pair<int,int> b = find_min_max(tree,node*2+1, (s+e)/2+1,e, l,r);
	int mx = max(a.second, b.second);
	int mn = min(a.first, b.first);

	return make_pair(mn,mx);
}

pair<int,int> update(vector<pair<int,int> > &tree, int node, int s, int e, int idx, int val){
	if (e < idx || s > idx)
		return make_pair(987654321,-1);
	if (s == e){
		tree[node] = make_pair(val,val);
		return tree[node];
	}
	if (s != e){
		update(tree, node*2, s,(s+e)/2, idx,val);
		update(tree, node*2+1, (s+e)/2+1,e, idx,val);
		tree[node] = make_pair(min(tree[node*2].first,tree[node*2+1].first), max(tree[node*2].second, tree[node*2+1].second));
	}
	return tree[node];
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	vector<int> dvd(100001,0);
	int h = (int) ceil(log2(100001));
	int tree_size = (1 << (h+1));
	vector<pair<int,int> > tree(tree_size);
	cin >>T;
	for (int i=0; i<T; i++){
		int N,K;
		cin >>N >> K;
		for (int i=1; i<=N; i++)
			dvd[i] = i;
		init(tree,dvd,1,1,N);
		for (int j=0; j<K; j++){
			int a,b,c;
			cin >>a >>b >>c;
			if (a == 0){
				int temp = dvd[b+1];
				update(tree,1,1,N,b+1,dvd[c+1]);
				dvd[b+1] = dvd[c+1]; 
				update(tree,1,1,N,c+1,temp);
				dvd[c+1] = temp;
			}
			else {
				pair<int,int> x = find_min_max(tree,1,1,N,b+1,c+1);
				if (x.first== b+1 && x.second== c+1)
					cout <<"YES" <<"\n";
				else
					cout <<"NO" <<"\n";
			}
		}

	}

}