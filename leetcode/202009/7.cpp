class Solution {
public:
    map<string,char> m;
    
    
    bool wordPattern(string pattern, string str) {
        bool check[26]={0,};
        istringstream iss(str);
        vector<string> words;
        copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(words));
        if (words.size() != pattern.size()) return false;
        for (int i=0; i<words.size(); i++){
            if (m.find(words[i]) == m.end()){
                m.insert(make_pair(words[i], pattern[i]));
                if (check[pattern[i]-'a']) return false;
                else check[pattern[i]-'a'] = true;
            } else if (m[words[i]] != pattern[i]) return false;
        }
        return true;
    }
};
