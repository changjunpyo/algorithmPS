class Solution {
public:
    int getSum(int a, int b) {
        int op=0;
        int ans =0;
        for (int i=0; i<32; i++){
            int x = 1<<i;
            op = op <<i;
            int a_i = a & x;
            int b_i = b & x;
            ans |= ((a_i ^ b_i) ^ op);
            if ((a_i & b_i) || (a_i & op) ||  (b_i & op))
                op = 1;
            else 
                op = 0;
        }
        return ans;
    }
};