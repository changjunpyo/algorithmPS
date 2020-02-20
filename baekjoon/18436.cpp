#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

pair<int,int> init (vector<int> &a, vector<pair<int,int> > &tree, int node, int start, int end){
    if (start == end){
    	if (a[start] % 2 ==0)
        	tree[node].first++;
        else
        	tree[node].second++;
    }

    else {
        pair<int,int> x = init(a,tree,node*2,start,(start+end)/2);
        pair<int,int> y = init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node]= make_pair(x.first+y.first,x.second+y.second);
    }
    return tree[node];
}

pair<int,int> find (vector<pair<int,int> > &tree,int node ,int start, int end, int left , int right ){
    if (end < left || start > right)
        return make_pair(0,0);
    if (left <= start && end <= right)
        return tree[node];
    else{
        pair<int,int> x= find(tree, node*2,start,(start+end)/2,left,right);
        pair<int,int> y= find(tree, node*2+1,(start+end)/2+1,end,left,right);
        return make_pair(x.first+y.first,x.second+y.second);
    }
}

void update(vector<pair<int,int> > &tree,int node ,int start, int end, int idx, int val){
    if (end < idx || start > idx)
        return ;

    if (start == end){
    	if (val % 2 == 0)
    		tree[node] = make_pair(1, 0);
    	else
    		tree[node] = make_pair(0,1);
        return;
    }

    update(tree,node*2,start,(start+end)/2,idx,val);
    update(tree,node*2+1,(start+end)/2+1,end,idx,val);

    tree[node] = make_pair(tree[node*2].first+tree[node*2+1].first, tree[node*2].second+tree[node*2+1].second);
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
    vector <pair<int,int> > t(tree_size, make_pair(0,0));

    for (int i=1; i<=N; i++)
        cin >>a[i];
    init(a,t,1,1,N);
    cin >>M;
    for (int i=0; i<M; i++){
        int x,y,z;
        cin >>x;
        if (x==1){
            cin >>y >>z;
            update(t,1,1,N,y,z);
            a[y]=z;
        }
        else if (x==2){
            cin >> y>>z;
            cout <<find(t,1,1,N,y,z).first<<"\n";
        }
        else{
        	cin >>y >>z;
        	cout <<find(t,1,1,N,y,z).second<<"\n";
        }
    }
    return 0;
}
