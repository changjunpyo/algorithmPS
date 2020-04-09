class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b){
        return a.first > b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> h;
        
        for (int i=0; i<nums.size(); i++){
            if (h.find(nums[i]) == h.end())
                h.insert({nums[i],1});
            else
                h[nums[i]] += 1;
        }
        vector<pair<int,int>> v(h.size());
        int idx=0;
        for (auto iter: h){
            v[idx++] = make_pair(iter.second,iter.first);
        }
        
        sort(v.begin(),v.end(), comp);
        vector<int> ans(k);
        for (int i=0; i<k; i++)
            ans[i] = v[i].second;
        return ans;
    }
};