class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int> > stc;
        int ans =0;
        for (int i=0; i<height.size(); i++){
            if (height[i] == 0) continue;
            
            int mx= 0;
            while(!stc.empty() && stc.top().first <= height[i]){
                pair<int,int> p = stc.top();
                ans += (i-p.second-1)*(min(height[i],p.first) - mx); 
                mx = max(mx, p.first);
                stc.pop();
            }
            
            if (!stc.empty() && stc.top().first > height[i]){
                pair<int,int> p = stc.top();
                ans += (i-p.second-1)*(min(height[i],p.first) - mx); 
            }
            
            stc.push(make_pair(height[i],i));
        }
        return ans;
    }
};