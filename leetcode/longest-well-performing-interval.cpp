class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> prefix(hours.size()+1,0);
        unordered_map<int,int> m;
        m.insert({0,0});
        int ans = 0;
        for (int i=0; i<hours.size(); i++){
            if (hours[i] >8) prefix[i+1] = prefix[i] +1;
            else prefix[i+1] = prefix[i] -1;
            if (prefix[i+1] > 0) ans = max(ans,i+1);
            else{
                if (m.find(prefix[i+1]) == m.end())
                    m.insert({prefix[i+1], i+1});
                
                if (m.find(prefix[i+1]-1) != m.end())
                    ans = max(ans, i+1- m[prefix[i+1]-1]);
            }
        }
        return ans;
    }
};