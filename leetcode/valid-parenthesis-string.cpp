class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int,int>> st;
        int jocker = 0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '*'){
                jocker++;
            }
            else if (s[i] =='(')
                st.push({s[i],jocker});
            else if (s[i] == ')'){
                if (!st.empty()) st.pop();
                else if (jocker > 0) jocker--;
                else return false;
            }
        }
        while(!st.empty()){
            if (st.top().second < jocker){
                jocker--;
                st.pop();
            }
            else return false;
        }
        return true;
    }
};