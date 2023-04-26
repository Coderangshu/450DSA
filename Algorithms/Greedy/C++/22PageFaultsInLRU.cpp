class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        // link list to maintain the cache memory
        list<int> l;
        
        int pageFaults = 0;
        
        for(int i=0;i<N;i++){
            auto f = find(l.begin(),l.end(),pages[i]);
            
            // if page not present
            if(f==l.end()){
                pageFaults++;
                
                // if cache is full remove least recent used
                if(l.size()==C) l.pop_front();
                l.push_back(pages[i]);
            }
            // if found
            else{
                l.erase(f);
                l.push_back(pages[i]);
            }
        }
        return pageFaults;
    }
};
