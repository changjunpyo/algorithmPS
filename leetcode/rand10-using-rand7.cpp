// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int idx = 31;
        while (idx >30){
            idx = rand7()+ (rand7()-1)*7;
        }
        return 1+ (idx-1)%10;
    }
};
