class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int i=0; i<wall.size(); i++){
            int sum =0;
            for (int j=0; j<wall[i].size()-1; j++){
                sum += wall[i][j];
                if (m.find(sum) == m.end()){
                    m[sum] = 1;
                } else{
                    m[sum]++;
                }
                ans = max(ans, m[sum]);
            }
        }
        return wall.size() - ans;
    }
};
