class Solution {
public:
    int countPrimes(int n) {
        bool notPrime[n+1];
        memset(notPrime, false, sizeof(notPrime));
        if (n == 0 || n == 1) return 0;
    
        int count=n-2;
        for (int i=2; i*i<n; i++){
            if (!notPrime[i]){
            for (int j=i*i;j< n; j+=i){
                if (!notPrime[j]){
                    count--;
                    notPrime[j] = true;
                }
            }
            }
        }
        return count;
    }
};
