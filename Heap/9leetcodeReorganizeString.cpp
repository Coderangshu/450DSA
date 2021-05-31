class Solution {
public:
    
    // Method Used:
    // create map of characters and their frequency
    // create a max heap of each of them with respect
    // to their frequency, this gives us the highest
    // frequency characters first, now from the heap
    // heap we take the first and second characters
    // (the chracters with highest frequency and one
    // of the second highest frequency) and put them
    // in our answer string, then we update those 2 
    // nodes and push them into the heap and again
    // heapify it to bring the highest to the root
    // and continue the process till only 1 or no
    // elements are left in the heap
    
    // When 1 node remains in the heap we check its
    // frequency if its more than 1 than we return
    // empty string as output else place that char
    // int the last of the ans string and return it.
    
    void swap(pair<char,int> *x, pair<char,int> *y){
        pair<char,int> temp = *x;
        *x = *y;
        *y = temp;
    }
    
    void heapify(vector<pair<char,int>> &arr, int n, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l].second > arr[largest].second)
            largest = l;
        if (r < n && arr[r].second > arr[largest].second)
            largest = r;
        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    void pop(vector<pair<char,int>> &arr){arr.erase(arr.begin());}
    
    void push(vector<pair<char,int>> &arr, pair<char,int> p){arr.push_back(p);}
    
    void buildHeap(vector<pair<char,int>> &arr){
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    }
    
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]] = (mp.find(s[i])!=mp.end())? ++mp[s[i]] : 1;
        int heap_size = mp.size();
        vector<pair<char,int>> heap(heap_size);
        int i = 0;
        for(auto e:mp){
            heap[i] = make_pair(e.first,e.second);
            i++;
        }
        buildHeap(heap);
        string ans = "";
        i=0;
        while(heap.size()>1){
            auto p1 = heap[0], p2 = heap[1];
            char m1 = p1.first, m2 = p2.first;
            int f1 = p1.second, f2 = p2.second;
            pop(heap);
            pop(heap);
            ans += m1;
            ans += m2;
            int count = 0;
            if(f1>1){
                push(heap,make_pair(m1,f1-1));
                count++;
            }
            if(f2>1){
                push(heap,make_pair(m2,f2-1));
                count++;
            }
            buildHeap(heap);
            i++;
        }
        // for(auto e:heap) cout<<e.first<<" "<<e.second<<"\t";
        // cout<<endl;
        if(heap.size()==0) return ans;
        else if(heap[0].second>1) return "";
        else if(heap[0].second==1){
            int size = ans.length();
            if(ans[size-1]==heap[0].first) ans = heap[0].first+ans;
            else ans += heap[0].first;
        }
        return ans;
    }
};
