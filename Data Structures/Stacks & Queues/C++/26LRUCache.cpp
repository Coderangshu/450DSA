        // if(lookupTable.size()==size)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

typedef struct dllNode{
    int value;
    int key;
    struct dllNode *prev, *next;
    dllNode(int k, int v){
        key = k;
        value = v;
        next = prev = NULL;
    }
}dln;

class LRUCache
{
    private:
    int size;
    // doubly linked list head and tail
    dln *head, *tail;
    
    // map used to search and return value of
    // a node from the stored address in it in
    // O(1) time
    unordered_map<int,dln*> lookupTable;
    
    // insert the most recent used next to head
    // thus the least recent used will be previous
    // to tail
    // when needed to insert a new node but cache is
    // full we delete prev of tail and insert new next
    // to head, if needed to access or update a node
    // we delete the node from the linked list return or
    // update value and put in a new node next to head
    
    // function to delete a node from dll
    void delNode(dln *current){
        // when only one node present
        if(current==head and current==tail) head = tail = NULL;
        // if last node is to be deleted
        else if(current==tail){
            current->prev->next = NULL;
            tail = current->prev;
        }
        // if first node is to be deleted
        else if(current==head) head = head->next;
        // if node in between is to be deleted
        else{
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        // delete node from map and free the node
        lookupTable.erase(current->key);
        free(current);
    }
    
    // function to insert new node at head
    void insNode(int key, int value){
        dln *nn = new dln(key,value);
        lookupTable[key] = nn;
        // if this is the first node in dll
        if(!head) head = tail = nn;
        else{
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        size = cap;
        head = tail = NULL;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        // if key not in map return -1
        if(lookupTable.find(key)==lookupTable.end()) return -1;
        else{
            dln *node = lookupTable[key];
            int item = node->value;
            // delete node from wherever it is and
            // add it at the head as it is the most
            // recent used node
            delNode(node);
            insNode(key,item);
            return item;
        }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        
        // if found in map then delete the least recent used
        // node and add the new node at head
        if(lookupTable.find(key)!=lookupTable.end()){
            dln *node = lookupTable[key];
            delNode(node);
            insNode(key,value);
        }
        // if not the first condition now we know that
        // key not in map & cache memory, so we have to
        // insert it
        else{
            // check if cache is full if full then
            // delete least recent used node and insert
            // new node at head
            if(lookupTable.size()==size){
                delNode(tail);
                insNode(key,value);
            }
            // else cache not full, just insert at head
            else insNode(key,value);
        }
    }
};


// Using link (Doubly Linked List STL)
class LRUCache {
private:
    int maxSize;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> dictionary;
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        int ans = -1;
        if(dictionary.count(key)){
            ans = (*dictionary[key]).second;
            cache.erase(dictionary[key]);
            cache.push_front({key,ans});
            dictionary[key] = cache.begin();
        }
        return ans;
    }
    
    void put(int key, int value) {
        if(dictionary.count(key)) cache.erase(dictionary[key]);
        if(cache.size()==maxSize){
            dictionary.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key,value});
        dictionary[key] = cache.begin();
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
