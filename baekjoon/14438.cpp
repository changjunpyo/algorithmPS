#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

pair<int,int> min_init (vector<int> &a, vector<pair<int,int> > &tree, int node, int start, int end){
    if (start == end){
        tree[node].first = a[start];
        tree[node].second = start;
    }

    else {
        pair<int,int> x = min_init(a,tree,node*2,start,(start+end)/2);
        pair<int,int> y = min_init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node]=(x.first <= y.first)? x :y;
    }
    return tree[node];
}

pair<int,int> min_find (vector<pair<int,int> > &tree,int node ,int start, int end, int left , int right ){
    if (end < left || start > right)
        return make_pair(1000000001,-1);
    if (left <= start && end <= right)
        return tree[node];
    else{
        pair<int,int> x= min_find(tree, node*2,start,(start+end)/2,left,right);
        pair<int,int> y= min_find(tree, node*2+1,(start+end)/2+1,end,left,right);
        return (x.first <= y.first)?x:y;
    }
}

void update(vector<pair<int,int> > &tree,int node ,int start, int end, int idx, int val){
    if (end < idx || start > idx)
        return ;

    if (start == end){
        tree[node] = make_pair(val, idx);
        return;
    }

    update(tree,node*2,start,(start+end)/2,idx,val);
    update(tree,node*2+1,(start+end)/2+1,end,idx,val);

    tree[node] = (tree[node*2].first <= tree[node*2+1].first) ? tree[node*2]: tree[node*2+1];
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;

    cin >> N;
    int h = (int) ceil(log2(N+1));
    int tree_size = (1<<(h+1));
    vector <int> a(N+1);
    vector <pair<int,int> > min_tree(tree_size, make_pair(0,0));

    for (int i=1; i<=N; i++)
        cin >>a[i];
    min_init(a,min_tree,1,1,N);
    cin >>M;
    for (int i=0; i<M; i++){
        int x,y,z;
        cin >>x;
        if (x==1){
            cin >>y >>z;
            update(min_tree,1,1,N,y,z);
            a[y]=z;
        }
        else{
            cin >> y>>z;
            cout <<min_find(min_tree,1,1,N,y,z).first<<"\n";
        }
    }
    return 0;
}
