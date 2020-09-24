class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        int total =0;
        int start= 0;
        int n = gas.size();
        for (int i=0; i<n; i++){
            cur += gas[i] - cost[i];
            total += gas[i] - cost[i];
            
            if (cur <0){
                start = i+1;
                cur = 0;
            }
        }
        return total >= 0 ? start :-1;
    }
};