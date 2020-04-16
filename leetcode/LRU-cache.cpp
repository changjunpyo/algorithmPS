class Node{
    public:
    int value;
    int key;
    Node(int k,int v){
        key = k;
        value = v;
        next= nullptr;
        before= nullptr;
    }
    Node *next,*before;
};
class doubleLinkedList{    
    public:
    int size;
    int capa;
    Node *head;
    Node *tail;
    doubleLinkedList(int x){
        capa =x;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    void nodeToBack(Node *curr){
        if (tail == curr)
            return;
        if (head == curr)
            head = curr->next;
        if (curr != nullptr){
            if (curr->before != nullptr)
                curr->before->next= curr->next;
            if (curr->next != nullptr)
                curr->next->before= curr->before;
            
            if (tail != nullptr){
                tail->next = curr;
                curr->before = tail;
            }
            tail = curr;
            curr->next = nullptr;
        }
    }
    void removeFront(){
        if (head != nullptr){
           head= head->next;
           if (head!=nullptr)
               head->before = nullptr;
        }
        size--;
    }
    Node* addBack(int key, int value){
        Node *n = new Node(key,value);
        
        if (tail !=nullptr){
            tail->next = n;
            n->before = tail;
        }
        tail = n;
        
        size++;
        if (head == nullptr){
            head = n;
        }
        return n;
    }
};
class LRUCache {
    unordered_map<int,Node*> m;
    doubleLinkedList *l;
public:
    LRUCache(int capacity) {
        l = new doubleLinkedList(capacity);
    }
    
    int get(int key) {
        if (m.find(key)!= m.end()){
            l->nodeToBack(m[key]);
            return m[key]->value;
        }
        else
            return -1;
    }
    void put(int key, int value) {
        if (m.find(key)!=m.end()){
            l->nodeToBack(m[key]);
            m[key]->value = value;
        }
        else{
            if (l->capa == l->size){
                m.erase(l->head->key);
                l->removeFront();
            }
            m.insert({key,l->addBack(key,value)});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */