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
    vector <long long> a(N,0);
    vector <long long> tree(tree_size,0);

    for (int i=0; i<M; i++){
        int x,y,z;
        cin >> x >> y>> z;
        if (x ==0){
            if (y< z)
                cout <<sum(tree,1,0,N-1,y-1,z-1) <<"\n";
            else
                cout <<sum(tree,1,0,N-1,z-1,y-1) <<"\n";
            }
        else{
            update(tree, 1, 0,N-1,y-1,z-a[y-1]);
            a[y-1] = z;
        }
        
    }
    return 0;
}
