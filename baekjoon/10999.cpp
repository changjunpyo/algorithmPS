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

long long lazy_propa_sum(vector<long long> &tree, vector<long long> &change,int node ,int start, int end, int left , int right ){
    if (change[node] != 0){
        tree[node] += change[node]*(end-start+1);
        if (start != end){
            change[node*2] += change[node];
            change[node*2+1] += change[node];
        }
        change[node] = 0;
    }
    if (end < left || start > right)
        return 0;

    if (left <= start && end <= right){
        return tree[node];
    }
    else{
        change[node*2] += change[node];
        change[node*2+1] += change[node];
        change[node] = 0;
        return lazy_propa_sum(tree,change,node*2,start,(start+end)/2,left,right)+lazy_propa_sum(tree,change,node*2+1,(start+end)/2+1,end,left,right);
    }
}

void update(vector<long long> &tree, vector<long long> &change, int node, int start, int end, int left,int right, long long diff){
    if (start > right || end < left)
        return ;
    if (left <= start && end <= right){
        change[node] += diff;
        return;
    }
    if (start <= left && right <= end)
        tree[node] += (right-left+1)*diff;
    else if (start <= left && left <= end)
        tree[node] += (end - left+1)*diff;
    else if (start <= right && right <=end)
        tree[node] += (right - start+1)*diff;
    update(tree,change,node*2,start,(start+end)/2,left,right,diff);
    update(tree,change,node*2+1,(start+end)/2+1,end,left,right,diff);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;

    cin >> N >> M >> K;
    int h = (int) ceil(log2(N));
    int tree_size = (1<<(h+1));
    vector <long long> a(N);
    vector <long long> change(tree_size,0);
    vector <long long> tree(tree_size);
    for (int i=0; i<N; i++)
        cin >>a[i];
    init(a,tree,1,0,N-1);
    for (int i=0; i<K+M; i++){
        int x;
        cin >> x;
        if (x==2){
           int y,z;
           cin >>y >>z;
           cout <<lazy_propa_sum(tree,change,1,0,N-1,y-1,z-1) <<"\n";
        }
        else{
            int y;
            int _y;
            long long z;
            cin >> y >> _y >> z;
            update(tree,change, 1, 0,N-1,y-1, _y-1,z);
            a[y-1] = z;
        }
    }
    return 0;
}
