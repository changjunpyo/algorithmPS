class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        long long int x = 1;
        for (int i=s.size()-1; i>=0; i--){
            ans += (x*(s[i]-'A'+1));
            x *= 26;
        }
        return ans;
    }
};