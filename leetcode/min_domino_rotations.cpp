class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n= A.size();
        int num_a[7] = {0,};
        int num_b[7] = {0,};
        for (int i=0; i< n; i++){
            num_a[A[i]]++;
            num_b[B[i]]++;
        }
        int ans =200000;
        for (int i=1; i<=6; i++){
            if (num_a[i] + num_b[i] < n) continue;
            int c_a = 0;
            int c_b = 0;
            bool check_possible= true;
            for (int j=0; j<n; j++){
                if (A[j] != i && B[j] != i) {
                    check_possible = false;
                    break;
                }
                if (A[j] != i &&  B[j] == i) c_a++;
                if (A[j] == i && B[j] != i) c_b++;
            } 
            if (!check_possible) continue;
            if (c_a < c_b) c_b = c_a;
            ans = min(ans, c_b);
        }
        if (ans == 200000) return -1;
        return ans;
    }
};