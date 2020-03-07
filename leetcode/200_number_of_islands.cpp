static int x = []() {

std::ios::sync_with_stdio(false);

cin.tie(NULL);

return 0; }();
class Solution {
public:
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
    void dfs(int i, int j, int A,int B, vector<vector<bool>> &check,vector<vector<char>>& grid){
        
        check[i][j] = true;
        
        for (int t=0; t<4; t++){
                int x = i+dx[t];
                int y = j+ dy[t];
                if ( x>=0 && x<A && y>=0 && y<B && !check[x][y] && grid[x][y] == '1'){
                    dfs(x,y,A,B,check,grid);
                }
        }
        return ; 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() ==0)
            return 0;
        vector<vector<bool> > check(grid.size(),vector<bool>(grid[0].size(),0));
       
    
        int ans=0;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (check[i][j] || grid[i][j] =='0') continue;
                ans++;
                dfs(i,j,grid.size(),grid[i].size(),check,grid);
            }
        }
    return ans;
    }
};