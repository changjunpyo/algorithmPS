class Solution {
public:
    
    void find_recurcive(int num,int depth, int N,int K, vector<int> &ans){
        if (depth == N){
            ans.push_back(num);
            return;
        }
        int last_digit = num % 10;
        if (last_digit +K <=9)
            find_recurcive(num*10 +last_digit+K, depth+1, N,K, ans);
        if (K && last_digit -K >=0)
            find_recurcive(num*10 +last_digit-K, depth+1, N,K, ans);
        
        return;
        
    }
    
    
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if (N==1) {
            for (int i=0; i<10; i++)
                ans.push_back(i);
            return ans;
        }
        for (int i=1; i<10; i++){
            find_recurcive(i,1,N,K,ans);
        }
        
        return ans;
    }
};