class Solution {
public:
    map<string, bool> m;
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size()==0) return true;
        if (m.find(s) != m.end()) return m[s];
        bool check = false;
        for (int i=0; i<wordDict.size(); i++){
            if (s[0] != wordDict[i][0] || s.size() < wordDict[i].size()) continue;
            if (s.substr(0,wordDict[i].size())== wordDict[i]){
                check |= wordBreak(s.substr(wordDict[i].size()), wordDict);
                
            }
        }
        m[s] = check;
        return check;
    }
};