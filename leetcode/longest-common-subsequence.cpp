class Solution {
public:
    
    
    int max_dp(int i, int j,string &text1, string &text2, vector<vector<int> > &dp ){
        if (i <0 || j<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]){
            dp[i][j] = 1+max_dp(i-1,j-1, text1,text2,dp);
        }
        else{
            int a = max_dp(i-1, j, text1, text2, dp);
            int b = max_dp(i, j-1, text1,text2, dp);
            if (a  > b){
                dp[i][j] = a;
            }
            else
                dp[i][j] = b;
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size() ,vector<int>(text2.size(), -1));
        return max_dp(text1.size()-1, text2.size()-1, text1,text2,dp);
    }
};