#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int init (vector<int> &a, vector<int> &tree, int node, int start, int end){
    if (start == end)
        tree[node] = a[start];
    else 
        tree[node]= init(a,tree,node*2,start,(start+end)/2)*init(a,tree,node*2+1,(start+end)/2+1,end);

    return tree[node];
}

int find (vector<int> &tree,int node ,int start, int end, int left , int right ){
    if (end < left || start > right)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    else
        return find(tree, node*2,start,(start+end)/2,left,right)*find(tree, node*2+1,(start+end)/2+1,end,left,right);
}

void update (vector<int> &tree ,int node, int start, int end,int idx,int num){
	if (idx < start || end < idx)
		return;
	if (idx == start && idx== end){
		tree[node] = num;
		return;
	}
	update(tree, node*2, start, (start+end)/2, idx,num);
	update(tree, node*2+1, (start+end)/2+1, end, idx,num);
	tree[node] = tree[node*2]*tree[node*2+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;

    while(cin >> N >> M){
    int h = (int) ceil(log2(N));
    int tree_size = (1<<(h+1));
    vector <int> arr(N);
    vector <int> tree(tree_size+1);

    for (int i=0; i<N; i++){
    	int a;
    	cin >> a;
    	if (a>0)
    		arr[i]=1;
    	else if (a==0)
    		arr[i]=0;
    	else 
    		arr[i]=-1;
    }
    init(arr,tree,1,0,N-1);
    for (int i=0; i<M; i++){
        char c;
        cin >> c;
        if (c== 'C'){
        	int a, b;
        	cin >>a>>b;
        	if (b >0)
        		b=1;
        	else if (b ==0)
        		b=0;
        	else 
        		b=-1;
        	update(tree,1,0,N-1,a-1,b);
        	arr[a-1] = b; 
        }
        else{
        	int a,b;
        	cin >>a >>b;
        	int x = find(tree,1,0,N-1,a-1,b-1);
        	if (x ==-1)
        		cout << '-';
        	else if (x == 0)
        		cout << '0';
        	else
        		cout <<'+';
        }
    }
    cout << "\n";
	}
    return 0;
}
