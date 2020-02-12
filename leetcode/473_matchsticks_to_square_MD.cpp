class Solution {
public:
    
    bool check(const vector<int> &nums,vector<bool> &visited, int length,int sum, int idx,int sides){
        if (idx == nums.size())
            return sides == 4;
            
        int ans =false;
        for (int i=0; i<nums.size(); i++){
            if (visited[i])
                continue;
            visited[i] = true;
            int _sum = sum;
            int _sides = sides;
            if (sum + nums[i] > length){
                visited[i] = false;
                return false;
            } 
            else if (sum + nums[i] == length){
                _sum = 0;
                _sides++;
            }
            else 
                _sum += nums[i];
            
            if (check(nums,visited,length,_sum, idx+1,_sides))
                return true;
            visited[i] =false;
        }
        
        return ans;
        
        
    }
    
    
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4)
            return false;
        vector<bool> visited(nums.size(),false);
        int sum=0;
        for (int i=0; i<nums.size(); i++){
            sum+= nums[i];
        }
        int side = sum/4;
        sort(nums.begin(), nums.end(), greater<int>());
        if (sum %4 != 0 || side ==0)
            return false;
        return check( nums,visited, side,0,0,0);
        
        
    }
};