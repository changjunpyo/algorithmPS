class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans=0;
        for (int dx= -1*(int)A.size()+1; dx<(int)A.size(); dx++){
            for (int dy=-1*(int)A.size()+1; dy<(int)A.size(); dy++){
                int count=0;
                for (int i=0; i<A.size(); i++){
                    for (int j=0; j<A.size(); j++){
                        if (i+dx<0 || i+dx >=A.size()|| j+dy<0 || j+dy>=A.size()) continue; 
                        if (A[i][j]==1  && B[i+dx][j+dy]==1) {
                            count++;
                        }
                    }
                }
                ans = max(count,ans);
            }
        }
        return ans;
    }
};
