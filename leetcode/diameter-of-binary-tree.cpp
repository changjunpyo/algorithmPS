class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> s;
        for (int i=0; i<stones.size(); i++)
            s.push(stones[i]);
        
        while(s.size() > 1){
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            if (x!=y)
                s.push(abs(x-y));
        }
        if (s.empty())
            return 0;
        else
            return s.top();
    }
};