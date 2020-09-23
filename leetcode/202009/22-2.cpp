class Solution {
public:
    unordered_map<int,int> m;
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        for (int i=0; i<nums.size(); i++){
            if (m.find(nums[i]) == m.end()) m[nums[i]] = 1;
            else m[nums[i]] +=1;
        }
        for (auto x : m){
            if (x.second > (nums.size()/3))
                ans.push_back(x.first);
        }
        return ans;
    }
};