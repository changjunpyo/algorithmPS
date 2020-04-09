class Solution {
public:
    static bool cmp(const pair<string,int> &a,const pair<string,int> &b){
        return a.first < b.first;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string,int>> strs2(strs.size());
        for (int i=0; i<strs.size(); i++){
            strs2[i] = {strs[i],i};
            sort(strs2[i].first.begin(),strs2[i].first.end());
        }
        
        sort(strs2.begin(), strs2.end(), cmp);
        
        for(int i=0; i<strs2.size(); i++){
            vector<string> par_v ={strs[strs2[i].second]};
            while(i<strs2.size()-1){
                if (strs2[i].first == strs2[i+1].first){
                    par_v.push_back(strs[strs2[i+1].second]);
                    i++;
                }
                else break;
            }
            ans.push_back(par_v);
        }
        return ans;
    }
};