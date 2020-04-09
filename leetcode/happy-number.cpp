class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int num = n;
        while (num != 1){
            int next = 0;
            if (s.find(num) == s.end())
                s.insert(num);
            else
                return false;
            while(num>0){
                next += (num %10)*(num %10);
                num /= 10;
            }
            num = next;
        }
        return true;
    }
};