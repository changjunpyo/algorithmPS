 bool cmp(vector<int> &a, vector<int> &b){
        if (a[1] == b[1])
            return a[2] < b[2];
            
        return a[1] < b[1];
    }
class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), cmp);
        
        int left = 0;
        int right  =0;
        int p=0;
        int prev = 0;
    
        for (int i=0; i<trips.size(); i++){
            p += trips[i][0];
            for (int j=0; j<i; j++){
                if (prev < trips[j][2] &&  trips[j][2] <= trips[i][1])
                    p-= trips[j][0];
            }
            prev = trips[i][1];
            if (p> capacity) return false;
        }
        return true;
    }
};