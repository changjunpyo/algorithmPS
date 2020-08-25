class Solution {
public:
    const int x[3] ={1,7,30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366);
        
        for (int i=1; i<=365; i++){
            bool find = false;
            for(int j=0; j<days.size(); j++){
                if (days[j] == i){
                    find = true ;
                    break;
                }
            }
            if (!find) {
                dp[i] = dp[i-1];
            } else
            dp[i] = min(dp[max(0,i-1)]+ costs[0], min(dp[max(0,i-7)]+ costs[1], dp[max(0,i-30)]+costs[2]));
        }
    
    
    return dp.back();}
};
