class Solution {
public:
    
    int recursive_with_memo(int idx, const string &s, vector<int> &dp){
        if (idx == s.size()) return 1;
        
        if (s[idx] == '0') return 0;
        
        if (idx == s.size()-1) return 1;
        
        if (dp[idx] != -1){
            return dp[idx];
        }
        
        int ans = recursive_with_memo(idx + 1, s,dp);
        
        if (s[idx] == '1'  || (s[idx] == '2' && s[idx+1] <='6'))
            ans += recursive_with_memo(idx+2, s,dp);
        
        dp[idx] = ans;
        return dp[idx];
    }
    
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        vector<int> dp(s.size(), -1);
        return recursive_with_memo(0,s, dp);
        
    }
};