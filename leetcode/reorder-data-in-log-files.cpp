bool cmp(const string &a, const string &b){
    int a_idx = a.find(" ");
    int b_idx = b.find(" ");
    
    if (a[a_idx+1] >= '0' && a[a_idx+1] <='9' &&b[b_idx+1] >= '0' && b[b_idx+1] <='9'){
        return false;
    } else if (a[a_idx+1] >= '0' && a[a_idx+1] <='9'){
        return false;
    } else if (b[b_idx+1] >= '0' && b[b_idx+1] <='9'){
        return true;
    } else{
        if (a.substr(a_idx+1) == b.substr(b_idx+1)){
            return a < b;
        }
        return a.substr(a_idx+1) < b.substr(b_idx+1);
    }
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(),cmp);
        return logs;
    }
};