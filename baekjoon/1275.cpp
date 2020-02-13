#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long init (vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if (start == end)
        tree[node] = a[start];

    else {
        tree[node] = init(a,tree,node*2,start,(start+end)/2) + init(a,tree,node*2+1,(start+end)/2+1,end);
    }
    return tree[node];
}

long long sum (vector<long long> &tree,int node ,int start, int end, int left , int right ){
    if (end < left || start > right)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    else
        return sum(tree,node*2,start,(start+end)/2,left,right)+sum(tree,node*2+1,(start+end)/2+1,end,left,right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if (start > index || end < index)
        return ;
    tree[node] += diff;
    if (start != end){
        update(tree,node*2,start,(start+end)/2,index,diff);
        update(tree,node*2+1,(start+end)/2+1,end,index,diff);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;

    cin >> N >> M;
    int h = (int) ceil(log2(N));
    int tree_size = (1<<(h+1));
    vector <long long> a(N);
    vector <long long> tree(tree_size);
    for (int i=0; i<N; i++)
        cin >>a[i];
    init(a,tree,1,0,N-1);
    for (int i=0; i<M; i++){
        int w,v,x,y;
        cin >> w >>v >>x >>y;
        if (w < v)
            cout <<sum(tree,1,0,N-1,w-1,v-1) <<"\n";
        else
            cout <<sum(tree,1,0,N-1,v-1,w-1) <<"\n";
        update(tree, 1, 0,N-1,x-1,y-a[x-1]);
        a[x-1] = y;
    }
    return 0;
}
