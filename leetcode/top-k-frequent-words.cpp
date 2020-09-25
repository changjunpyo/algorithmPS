struct cmp{
    bool operator()(const pair<int,string>&a ,const pair<int,string>&b){
        if (a.first == b.first)
            return a.second > b.second;
        
        return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>,vector<pair<int,string>>, cmp> pq;
        unordered_map<string, int> h;
        
        for (int i=0; i<words.size(); i++){
            h[words[i]]++;
        }
        for (auto kv : h){
            pq.push({kv.second, kv.first});
        }
        vector<string> ans;
        for (int i=0; i<k ; i++){
            auto temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        return ans;
    }
};