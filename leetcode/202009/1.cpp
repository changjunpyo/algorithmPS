// O(n^2)
/*
class Solution {
public:
    

    
    bool repeatedSubstringPattern(string s) {
        for (int i=1; i<=s.size()/2; i++){
            if (s.size() % i != 0) continue;
            for (int j=i; j<=s.size()-i; j+=i){
                if (s.substr(0,i) != s.substr(j,i)) break;
                if (j == s.size()-i) return true;
                
            }
        }        
        return false;
    }
};
*/
class Solution {
public:
    

    // O(n)
    bool repeatedSubstringPattern(string s) {
        string ss = s.substr(1) + s.substr(0,s.size()-1);
            
        return ss.find(s) != string::npos;
    }
};
