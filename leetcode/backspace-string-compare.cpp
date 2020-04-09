class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s_idx = S.size()-1;
        int t_idx = T.size()-1;
        int back_s = 0;
        int back_t = 0;
        while(s_idx >=0 && t_idx>=0){
            if (back_s && S[s_idx] != '#'){
                s_idx--;
                back_s--;
            }
            else if (S[s_idx] == '#'){
                s_idx--;
                back_s++;
            }
            if (back_t && T[t_idx] != '#'){
                t_idx--;
                back_t--;
            }
            else if (T[t_idx] == '#'){
                t_idx--;
                back_t++;
            }
            
            if (s_idx >= 0 && t_idx >=0 &&back_t ==0 && back_s ==0 &&S[s_idx] != '#' && T[t_idx] != '#'){
                if (S[s_idx] != T[t_idx]) return false;
                s_idx--;
                t_idx--;
            }
        }
        while(s_idx >=0){
            if (back_s ==0 &&S[s_idx] != '#')
                return false;
            
            else if (back_s && S[s_idx] != '#'){
                s_idx--;
                back_s--;
            }
            else if (S[s_idx] == '#'){
                s_idx--;
                back_s++;
            }
        }
        while(t_idx >=0){
            if (back_t ==0 &&T[t_idx] != '#')
                return false;
            else if (back_t && T[t_idx] != '#'){
                t_idx--;
                back_t--;
            }
            else if (T[t_idx] == '#'){
                t_idx--;
                back_t++;
            }
        }
        return true;
    }
};