class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26]={0};
        for (int i=0; i<s.size(); i++){
            hash[s[i]-'a'] +=1;
        }
        
        for (int i=0; i<t.size(); i++){
            hash[t[i]-'a'] -=1;
            if (hash[t[i]-'a'] < 0) return t[i];
        }
        return 'E';
    }
};