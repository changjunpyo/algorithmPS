class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans=0;
        int pre=1;
        for (int i=0; i<arr.size()-1; i++){
            if (arr[i] == arr[i+1]){
                pre++;
                continue;
            }
            if (arr[i]+1 == arr[i+1]){
                ans += pre;          
            }
            pre = 1;
        }
        return ans;
    }
};