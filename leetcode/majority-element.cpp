class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for (int i=0; i<nums.size(); i++){
            if (hash.find(nums[i]) == hash.end()){
                hash.insert(make_pair(nums[i],1));
                if (hash[nums[i]] > nums.size()/2)
                    return nums[i];
            } else{
                hash[nums[i]] += 1;
                if (hash[nums[i]] > nums.size()/2)
                    return nums[i];
            }
        }
    return -1
    }
};
