#include <bits/stdc++.h>
using namespace std;

long long init (vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if (start == end)
        tree[node] = a[start];

    else {
        tree[node] = init(a,tree,node*2,start,(start+end)/2) + init(a,tree,node*2+1,(start+end)/2+1,end);
    }
    return tree[node];
}

long long lazy_propa_sum(vector<long long> &tree, vector<pair<long long ,int > > &change,int node ,int start, int end, int left , int right ){
    if (change[node] != make_pair((long long)0,0)){
        tree[node] += (end-start+1)*change[node].first + change[node].second*(end-start+1)*(end-start)/2;
            if (start != end) {
                change[node*2].first += change[node].first;
                change[node*2].second += change[node].second;
                change[node*2+1].first += (change[node].first + change[node].second*((end-start)/2+1));
                change[node*2+1].second += change[node].second;
            }
        change[node] = make_pair(0,0);
    }
    if (end < left || start > right)
        return 0;

    if (left <= start && end <= right){
        return tree[node];
    }
    return lazy_propa_sum(tree,change,node*2,start,(start+end)/2,left,right)+lazy_propa_sum(tree,change,node*2+1,(start+end)/2+1,end,left,right);
    
}

void update(vector<long long> &tree, vector<pair<long long ,int> > &change,  int node, int start, int end, int left,int right){
    if (start > right || end < left)
        return ;
    if (left <= start && end <= right){
        change[node].first += (start-left+1);
        change[node].second++;
        return;
    }
    update(tree,change,node*2,start,(start+end)/2,left,right);
    update(tree,change,node*2+1,(start+end)/2+1,end,left,right);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;

    cin >> N;
    int h = (int) ceil(log2(N));
    int tree_size = (1<<(h+1));
    vector <long long> a(N);
    vector <pair<long long,int> > change(tree_size,make_pair((long long)0,0));
    vector <long long> tree(tree_size);
    for (int i=0; i<N; i++)
        cin >>a[i];
    init(a,tree,1,0,N-1);
    cin >>M;
    for (int i=0; i<M; i++){
        int x;
        cin >> x;
        if (x==2){
           int y,z;
           cin >>y;
           cout <<lazy_propa_sum(tree,change,1,0,N-1,y-1,y-1) <<"\n";
        }
        else{
            int y;
            int _y;
            cin >> y >> _y;
            update(tree,change, 1, 0,N-1,y-1, _y-1);
        }
    }
    return 0;
}
