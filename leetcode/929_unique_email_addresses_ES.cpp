class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_set<string> st;
        int ans=0;
        for (int i=0; i<emails.size(); i++){
            auto at_pos = emails[i].find("@");
            string local_name = emails[i].substr(0,at_pos);
            string domain = emails[i].substr(at_pos);
            string ans_local_name;
            int idx =0;
            for (int j=0; j<local_name.size(); j++){
                if (local_name[j] == '+'){
                    ans_local_name += local_name.substr(idx, j-idx);
                    break;
                }
                else if (local_name[j] == '.'){
                    ans_local_name += local_name.substr(idx, j-idx);
                    idx = j+1;
                }
                else if (j == local_name.size()-1){
                    ans_local_name += local_name.substr(idx, j-idx+1);
                }
            }
            if (st.find(ans_local_name +domain) != st.end()) continue;
            else{
                ans++;
                st.insert(ans_local_name +domain);
            }
        }
        return ans;
    }
};