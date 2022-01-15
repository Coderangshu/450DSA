// Similar to LRU just we maintain a hashmap of multiple LRUs
// each containing the nodes belonging to the same frequency
// and we maintain a total size to keep track of the number of nodes
// in the total cache
struct node{
    int key,val,cnt;
    struct node *next, *prev;
    node(){
        key = 0;
        val = 0;
        cnt = 0;
        next = prev = NULL;
    }
    node(int key, int val, int cnt){
        this->key = key;
        this->val = val;
        this->cnt = cnt;
        next = prev = NULL;
    }
};

class dll{
    private:
    node *head, *tail;
    int size;
    
    public:
    dll(){
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int getSize(){return size;}
    
    node* getLRU(){return tail->prev;}
    
    void push(node* newNode){
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        size++;
    }
    
    void del(node* toDel){
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
        size--;
    }
    
    void remove(){
        node* toDel = tail->prev;
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
        size--;
        delete(toDel);
    }
};

class LFUCache {
public:
    int maxSize, curSize, minFreq;
    // dictionary of key, node*
    unordered_map<int,node*> dict;
    // dictionary of count, dll of node of the 
    // main list which belong to the same count
    // maintained in lru order
    unordered_map<int,dll> count;
    
    LFUCache(int capacity) {
        maxSize = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    // moves the recent used node to the new frequency in the count hashmap
    void updateCount(node *n){
        count[n->cnt].del(n);
        if(n->cnt==minFreq and count[n->cnt].getSize()==0) minFreq++;
        if(count.find(++n->cnt)==count.end()){
            count[n->cnt] = dll();
            count[n->cnt].push(n);
        }
        else count[n->cnt].push(n);
    }
    
    int get(int key) {
        if(dict.find(key)!=dict.end()){
            node *n = dict[key];
            updateCount(n);
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0) return;
        if(dict.find(key)!=dict.end()){
            node *n = dict[key];
            n->val = value;
            updateCount(n);
        }
        else{
            if(curSize==maxSize){
                dll l = count[minFreq];
                node* lru = l.getLRU();
                dict.erase(lru->key);
                count[minFreq].remove();
                curSize--;
            }
            minFreq = 1;
            node *nn = new node(key,value,1);
            count[1].push(nn);
            curSize++;
            dict[key] = nn;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */