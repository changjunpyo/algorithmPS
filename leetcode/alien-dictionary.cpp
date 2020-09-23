

class Solution {
    
public:
    vector<vector<int> > a= vector<vector<int> >(26, vector<int>(0));
    int in_arr[26]={0,};
    bool exist[26] = {false};
    bool visited[26] = {false};
    bool on_stack[26] = {false};
    bool check_cycle(int x){
        visited[x] = true;
        on_stack[x] =true;
        bool cycle =false;
        for (auto next: a[x]){
            if (on_stack[next]) return true;
            if (visited[next]) continue;
            cycle |= check_cycle(next);
        }
        on_stack[x] = false;
        
        return cycle;
    }
    string alienOrder(vector<string>& words) {
        
        string ans;
        for (int i=0; i<words.size(); i++)
            for (int j=0; j<words[i].size(); j++)
                exist[words[i][j]-'a'] = true;
    
        for (int i=0; i<words.size()-1; i++){
            bool same = false;
            for (int j=0; j<words[i].size(); j++){
                if (same &&words[i+1].size() <= j) return "";
                if (words[i][j]== words[i+1][j]){
                    same = true;
                    continue;
                }else{
                    bool exit = false;
                    for (int k=0; k<a[words[i][j]-'a'].size(); k++){
                        if (a[words[i][j]-'a'][k] == words[i+1][j]-'a') 
                        {exit= true; 
                         break;}
                    }
                    if (exit) break;
                    a[words[i][j]-'a'].push_back(words[i+1][j]-'a');
                    in_arr[words[i+1][j]-'a']++;
                    break;
                }
            }
        }
        
        int cnt=0;
        for (int i=0; i<26; i++){
            if (exist[i]) cnt++;
            if(check_cycle(words[0][0]-'a')) return "";
        }
        
        while(cnt != 0){
            for (int i=0; i<26; i++){
                if (exist[i] && in_arr[i]==0) {
                    cnt--;
                    exist[i] = false;
                    for (auto next: a[i]){
                        in_arr[next]--;
                    }
                    ans += 'a' + i;
                }
            }
        } 
        return ans;
    }
};