#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int init (vector<int> &a, vector<int> &tree, int node, int start, int end){
    if (start == end)
        tree[node] = a[start];
    else 
        tree[node]= ((long long int)init(a,tree,node*2,start,(start+end)/2)* (long long int)init(a,tree,node*2+1,(start+end)/2+1,end))%MOD;

    return tree[node];
}

int find (vector<int> &tree,int node ,int start, int end, int left , int right ){
    if (end < left || start > right)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    else
        return ((long long int)find(tree, node*2,start,(start+end)/2,left,right)*(long long int)find(tree, node*2+1,(start+end)/2+1,end,left,right))%MOD;
}

void update (vector<int> &tree , vector<int> &a,int node, int start, int end,int idx,int num){
	if (idx < start || end < idx)
		return;
	if (idx == start && idx== end){
		tree[node] = num;
		return;
	}
	update(tree, a, node*2, start, (start+end)/2, idx,num);
	update(tree, a, node*2+1, (start+end)/2+1, end, idx,num);
	tree[node] = ((long long int)tree[node*2]* tree[node*2+1])%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;

    cin >> N >> M >>K;
    int h = (int) ceil(log2(N));
    int tree_size = (1<<(h+1));
    vector <int> arr(N);
    vector <int> tree(tree_size+1);

    for (int i=0; i<N; i++)
        cin >>arr[i];
    init(arr,tree,1,0,N-1);
    for (int i=0; i<M+K; i++){
        int a,b,c;
        cin >> a>> b>> c;
        if (a==1){
        	update(tree,arr,1,0,N-1,b-1,c);
        	arr[b-1] = c; 
        }
        else
        	cout << find(tree,1,0,N-1,b-1,c-1)<<"\n";
    }
    return 0;
}
