class Solution {
public:
    int findLastIdx(string &S, char c){
        for (int i=S.size()-1; i>=0; i--){
            if (S[i] == c) return i;
        }
        return -1;
    }
    vector<int> partitionLabels(string S) {
        int left =0;
        int right;
        int arr[26];
        for (int i=0; i<26; i++) arr[i] = -1;
        vector<int> ans;
        while(left < S.size()){
            right = findLastIdx(S, S[left]);
            arr[S[left]-'a'] = right;
            for (int i=left+1; i<=right; i++){
                if (arr[S[i]-'a'] == -1 ){
                    int next = findLastIdx(S, S[i]);
                    if (right < next) right = next;
                    arr[S[i]-'a'] = next;    
                }
            }
            
            ans.push_back(right-left+1);
            left = right+1;
        }
        return ans;
    }
};
