static auto x = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return NULL;
}();

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (int i=0; i<strs.size(); i++){
            ans += to_string(strs[i].size()) +" " + strs[i];
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        string sz="";
        for (int i=0; i<s.size(); i++){
            if (s[i] !=' ')
                sz += s[i];
            else if (s[i] ==' '){
                int str_size = stoi(sz);
                sz ="";
                string str = s.substr(i+1, str_size);
                ans.push_back(str);
                i+= str_size;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));