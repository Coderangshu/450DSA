class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        set<char> s;
        for(auto e:a) s.insert(e);
        for(auto e:a){
            // erase the e char from the set, as this can be
            // used to swap only once
            s.erase(e);
            if(s.empty()) break;
            // taking the smallest char to replace e
            char sc = *s.begin();
            // if sc<e then we swap
            if(sc<e){
                // swap all e with sc and vice versa
                for(int i=0;i<a.length();i++){
                    if(a[i]==e) a[i] = sc;
                    else if(a[i]==sc) a[i] = e;
                }
                break;
            }
        }
        return a;
    }
    
;
