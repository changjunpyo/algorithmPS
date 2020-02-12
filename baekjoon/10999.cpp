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

void update(vector<long long> &tree, int node, int start, int end, int left,int right, long long diff){
    if (start > right || end < left)
        return ;
    if (start == end)
        tree[node] += diff;
    else{
        if (left <= start && end <= right)
            tree[node] += diff*(end-start+1);
        else if (left <= start)
            tree[node] += diff*(right -start+1);
        else if (end <= right)
            tree[node] += diff*(end - left +1);
        update(tree,node*2,start,(start+end)/2,left,right,diff);
        update(tree,node*2+1,(start+end)/2+1,end,left,right,diff);
    }
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
    vector <bool> change(N);
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
           cout <<sum(tree,1,0,N-1,y-1,z-1) <<"\n";
        }
        else{
            int y;
            int _y;
            long long z;
            cin >> y >> _y >> z;
            update(tree, 1, 0,N-1,y-1, _y-1,z);
            a[y-1] = z;
        }
    }
    return 0;
}
