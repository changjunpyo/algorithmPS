class Solution {
public:
    
    int binary_sc(int val, vector<pair<int,int>> &start){
        int l = 0;
        int r = start.size();
        if (val > start.back().first) return -1;
        while(l < r){
            int m= (l+r)/2;
            if (start[m].first < val){
                l = m +1;
            } else {
                r = m;
            }
        }
        return start[l].second;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        vector<pair<int,int>> start;
        for (int i=0; i<intervals.size(); i++){
            start.push_back(make_pair(intervals[i][0],i));
        }
        sort(start.begin(), start.end());
        for (int i=0; i<intervals.size(); i++){
            int idx = binary_sc(intervals[i][1], start);
            ans.push_back(idx);
        }
        
        
     return ans;   
    }
};
