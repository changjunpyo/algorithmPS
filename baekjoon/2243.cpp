#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int CANDI_SIZE = 1000000;


int find (vector<int> &tree,int node ,int start, int end, int target, int total){
    if (start == end){
        	return start;
    }
    else {
    	int a = tree[2*node] + total;
    	if (target <= a)
    		return find(tree,node*2, start, (start+end)/2, target, total);
    	else
    		return find(tree,node*2+1, (start+end)/2+1, end, target, a);
    }
}

void update(vector<int> &tree, int node, int start, int end, int index, int diff){
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
    int M;

    cin >> M;
    int h = (int) ceil(log2(1000001));
    int tree_size = (1<<(h+1));
    vector <int> tree(tree_size,0);
    for (int i=0; i<M; i++){
        int x,y,z;
        cin >> x;
        if (x == 2){
        	cin >>y >>z;
        	update(tree, 1, 0,CANDI_SIZE-1,y-1,z);
        }
        if (x == 1){
        	cin >> y;
        	int ans = find(tree,1,0,CANDI_SIZE-1,y,0);
        	update(tree, 1, 0,CANDI_SIZE-1,ans,-1);
        	cout << ans+1 <<"\n";
        }
    }
    return 0;
}
