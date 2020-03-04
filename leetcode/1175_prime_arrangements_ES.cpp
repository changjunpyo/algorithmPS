class Solution {
public:
    int numPrimeArrangements(int n) {
        long long int arr[101]={0};
        bool notPrime[101]={false,};
        notPrime[1] = true;
        arr[0] = 1;
        for (int i=2; i<=n; i++){
            for (int j=i+i; j<=n; j+=i){
                if (!notPrime[j])
                    notPrime[j] = true;
            }
        }
        
        
        for (int i=1; i<=n; i++){
            arr[i] = (i*arr[i-1]) %1000000007;
        }
        
        int count =0;
        
        for (int i=1; i<=n; i++){
            if (notPrime[i]){
                count++;
            }
        }
        return(arr[count] * arr[n-count] ) %1000000007;
    }
};