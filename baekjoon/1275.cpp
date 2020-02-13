#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int max_init (vector<int> &a, vector<int> &tree, int node, int start, int end){
    if (start == end)
        tree[node-1] = a[start];

    else {
        int x = max_init(a,tree,node*2,start,(start+end)/2);
        int y = max_init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node-1]=(x > y)? x :y;
    }
    return tree[node-1];
}
int min_init (vector<int> &a, vector<int> &tree, int node, int start, int end){
    if (start == end)
        tree[node-1] = a[start];

    else {
        int x = min_init(a,tree,node*2,start,(start+end)/2);
        int y = min_init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node-1]=(x < y)? x :y;
    }
    return tree[node-1];
}

int max_find (vector<int> &tree,int node ,int start, int end, int left , int right ){
    if (end < left || start > right)
        return 0;
    if (left <= start && end <= right)
        return tree[node-1];
    else{
        int x= max_find(tree, node*2,start,(start+end)/2,left,right);
        int y= max_find(tree, node*2+1,(start+end)/2+1,end,left,right);
        return (x> y)?x:y;
    }
}
int min_find (vector<int> &tree,int node ,int start, int end, int left , int right ){
    if (end < left || start > right)
        return 1000000001;
    if (left <= start && end <= right)
        return tree[node-1];
    else{
        int x= min_find(tree, node*2,start,(start+end)/2,left,right);
        int y= min_find(tree, node*2+1,(start+end)/2+1,end,left,right);
        return (x < y)?x:y;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;

    cin >> N >> M;
    int h = (int) ceil(log2(N));
    int tree_size = (1<<(h+1));
    vector <int> a(N);
    vector <int> max_tree(tree_size);
    vector <int> min_tree(tree_size);

    for (int i=0; i<N; i++)
        cin >>a[i];
    min_init(a,min_tree,1,0,N-1);
    max_init(a,max_tree,1,0,N-1);
    for (int i=0; i<M; i++){
        int left,right;
        cin >> left >>right;
        cout << min_find(min_tree,1,0,N-1,left-1,right-1)<<" "<<max_find(max_tree,1,0,N-1,left-1,right-1)<<"\n";
    }
    return 0;
}
