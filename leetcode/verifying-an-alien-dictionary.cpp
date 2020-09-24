class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i=0; i<words.size()-1; i++){
            int n = words[i].size();
            int m = words[i+1].size();
            int s = min(n,m);
            for(int j=0; j<s; j++){
                if (words[i][j] == words[i+1][j] && j== s-1 && n > m) return false;
                else if (words[i][j] == words[i+1][j]) continue;
                else {
                    if (order.find(words[i][j]) > order.find(words[i+1][j])) return false;    
                    break;
                }
            }
        }
        return true;
    }
};