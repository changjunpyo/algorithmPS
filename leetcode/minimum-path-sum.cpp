class Solution {
public:
    void dfs(vector<vector<int>> &dp, vector<vector<int>>& grid, int x, int y, int now){
        if (dp[x][y] != -1){
            if (now >= dp[x][y])
                return;    
            else
                dp[x][y] = now;
        }
        else if (dp[x][y] == -1){
            dp[x][y] = now;
        }
        
        if (x+1 < grid.size())
            dfs(dp, grid, x+1,y,dp[x][y]+grid[x+1][y]);
        if (y+1 <grid[0].size())
            dfs(dp,grid, x,y+1,dp[x][y]+grid[x][y+1]);
        
     
        return ;   
        
    }
    int minPathSum(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        
       dfs(dp,grid,0,0,grid[0][0]);
       return dp[dp.size()-1][dp[0].size()-1];
    }
};