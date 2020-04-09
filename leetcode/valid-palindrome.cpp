class Solution {
public:
    bool isPalindrome(string s) {
        string ss ="";
        for (int i=0; i<s.size(); i++){
            if (s[i] >='A' && s[i] <='Z'){
                ss += (char)(s[i]-'A'+'a');
            }
            if (s[i] >='a' && s[i] <='z'){
                ss += s[i]; 
            }
            if (s[i] >='0' && s[i] <='9')
                ss += s[i];
        }
        stack<char> st;
        for (int i=0; i<(ss.size()/2); i++){
            st.push(ss[i]);
        }
        int start = (ss.size() %2 == 0) ? ss.size()/2 : ss.size()/2 +1;
        cout <<start;
        for (int i=start; i<ss.size(); i++){
            if (ss[i] != st.top()) return false;
            st.pop();
        }
        if (!st.empty()) false;
        return true;
    }
};