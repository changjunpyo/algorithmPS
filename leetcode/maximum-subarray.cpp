class Solution {
public:
    int cross_sum(const vector<int>& nums, int l, int r, int m){
        if (l == r) return nums[l];
        int left_sum=INT_MIN,right_sum=INT_MIN;
        int sum =0;
        for (int i=m; i>=l; i--){
            sum += nums[i];
            left_sum = max(sum,left_sum);
        }
        sum =0;
        for (int i=m+1; i<=r; i++){
            sum += nums[i];
            right_sum = max(sum,right_sum);
        }
        
        return left_sum+right_sum;
    }
    
    
    int dc (const vector<int>& nums, int l, int r){
        if (l == r) return nums[l];
        int mid = (l+r)/2;
        
        int left_max = dc(nums,l,mid);
        int right_max = dc(nums,mid+1,r);
        int cross_max = cross_sum(nums,l,r,mid);
        
        return max(left_max, max(right_max,cross_max));
    }
    
    
    
    int maxSubArray(vector<int>& nums) {
        return dc(nums,0,nums.size()-1);
    }
};