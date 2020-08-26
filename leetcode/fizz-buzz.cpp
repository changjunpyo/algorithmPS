class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for (int i=1; i<=n; i++){
            string s ="";
            if (i%3 ==0){
                s.append("Fizz");    
            }
            if (i%5 ==0){
                s.append("Buzz"); 
            } 
            if (i%3 != 0 && i%5 != 0){
                s.append(to_string(i));
            }
            ans[i-1]=s;
        }
        return ans;
    }
};
