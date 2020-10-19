class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if (prices.size()== 1) return 0;
        vector<int> v1(prices.size(),0);
        vector<int> v2(prices.size(),0);
        int mx = -1;
        int mn = 100002;
        int ans =0;
        for (int i=0; i<prices.size(); i++){
            mn = min(mn, prices[i]);
            if (ans < prices[i]- mn){
                ans = prices[i] - mn;
            }
            v1[i] = ans;
        }
        mx = -1;
        mn = 100002;
        ans =0;
        for (int i=prices.size()-1; i>=0; i--){
            mx = max(mx, prices[i]);
            if (ans < mx- prices[i]){
                ans = mx - prices[i];
            }
            v2[i] = ans;
        }
        
        
        int n = prices.size();
        ans = v1[n-1];
        for (int i=0; i<v1.size()-1; i++){
            ans = max(v1[i]+ v2[i+1] , ans);
        }
        return ans;
    }
};