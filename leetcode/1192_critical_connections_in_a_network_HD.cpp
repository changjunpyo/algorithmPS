static int x = []() {

std::ios::sync_with_stdio(false);

cin.tie(NULL);

return 0; }();
class Solution {
public:
    
    vector<vector<int>> ans;
    int num=0;
    
    int dfs(int u, int par ,vector<int> &pre,const vector<vector<int>>& adj ){
        int ret = pre[u] = ++num;
        
        for (auto v: adj[u]){
            if (v == par) continue; // 방문한 역방향 노드
            if (pre[v] > 0) ret = min(pre[v],ret);
            else {
                int temp = dfs(v, u, pre, adj);
                ret = min(ret, temp);
                if (temp > pre[u]){
                    ans.push_back(vector<int> {u,v});
                }
            }
        }
        return ret;
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int> > adj(n);  
        vector<int> pre(n,0);
        for (int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        dfs(0,-1,pre,adj);
        
        return ans;
    }
};