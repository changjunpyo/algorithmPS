class LRUCache {
public:
    
    LRUCache(int capacity) {
        cache_size = capacity;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()){
            int val = m[key]->second;
            l.erase(m[key]);
            l.push_front(make_pair(key,val));
            m[key] = l.begin();
            return m[key]->second;
            
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end())
            l.erase(m[key]);
        if (l.size() >= cache_size){       
            auto removed_key = l.back().first;
            m.erase(removed_key);
            l.pop_back();
        }
        l.push_front(make_pair(key,value));
        m[key] = l.begin();
        
    }
private:
    list<pair<int,int> > l;
    unordered_map<int, list<pair<int,int> >::iterator> m;
    int cache_size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */