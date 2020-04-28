class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0) return 0;
        vector<vector<int> > dp (matrix.size(), vector<int>(matrix[0].size(),0));
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] =='1') dp[i][j] = 1;
            }
        }
        int ans =0;
        for (int i=matrix.size()-1; i>=0; i--){
            for (int j=matrix[i].size()-1; j>=0; j--){
                if (dp[i][j] == 0) continue;
                else{
                    if (i+1 <matrix.size() && j+1 < matrix[i].size()){
                        dp[i][j] += min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};