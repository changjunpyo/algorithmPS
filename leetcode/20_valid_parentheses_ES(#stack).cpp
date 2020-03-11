class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] =='[')
                stc.push(s[i]);
            else {
                if (stc.empty()){
                    return false;
                }
                if (s[i] == ')'){
                    char c =stc.top();
                    if (c !='(')
                        return false;
                    stc.pop();
                }
                else if (s[i] =='}'){
                    char c =stc.top();
                    if (c !='{')
                        return false;
                    stc.pop();
                }
                else if (s[i] ==']'){
                    char c =stc.top();
                    if (c !='[')
                        return false;
                    stc.pop();
                }
            }
        }
        if (stc.empty())
            return true;
        else 
            return false;
    }
};