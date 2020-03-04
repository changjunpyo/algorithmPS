class Solution {
public:
    
    int smallestDivisor(vector<int>& nums, int threshold) {        
        int l =1; 
        int r = 1000000;
        
        while(l < r){
            int mid = (l+r)/2;
            int sum=0;
            for (int i=0; i<nums.size(); i++){
                sum += (int)ceil(nums[i] / (float)mid);
            }
            if (sum > threshold)
                l = mid+1;
            else
                r = mid;
        }
    return l;      
    }
};