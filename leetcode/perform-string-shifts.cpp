class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int x=0;
        for (int i=0; i<shift.size(); i++){
            if (shift[i][0] == 0)
                x+= shift[i][1];
            else
                x-= shift[i][1];
        }
        string ans;
        int sz = s.size();
        x = x % sz;
        if (x > 0){
            ans += s.substr(x)+ s.substr(0,x);
        }
        else if (x <0){
            ans += s.substr(s.size()+x)+ s.substr(0, s.size()+x);
        }
        else
            ans += s;
        return ans;
    }
};