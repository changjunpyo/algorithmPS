class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int ans =-1;
        for (int i=0; i<A.size(); i++){
            for(int j=0; j<A.size(); j++){
                if (i == j) continue;
                for (int k=0; k<A.size(); k++){
                    if (i==k || j== k) continue;
                    for (int l=0; l<A.size(); l++){
                        if (i==l || l== j || l== k) continue;
                        int hour = A[i]*10+ A[j];
                        int minute = A[k]*10+ A[l];
                        if (hour<=23 && minute<=59){
                            ans = max(hour*60 + minute, ans);
                        } 
                    } 
                }
            }          
        }
        if (ans == -1) return "";
        
        return to_string((ans/60) /10 ) + to_string((ans/60)%10) +":"+ to_string((ans%60)/10) + to_string((ans%60)%10);
    }
};
