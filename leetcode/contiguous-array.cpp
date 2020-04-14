class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int count =0;
        int ans = 0;
        m.insert({0,-1});
        for (int i=0; i<nums.size(); i++){
            count = count + ((nums[i] == 0) ? -1 : 1);
            if (m.find(count) != m.end()){
                ans = max(ans, i-m[count]);
            }
            else{
                m.insert({count,i});
            }
        }
        return ans;
    }
};