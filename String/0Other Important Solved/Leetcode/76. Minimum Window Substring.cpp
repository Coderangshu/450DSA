// window length is maintained using 2 pointers
// begin and end, for each end it is incremented 
// according to validity the parameters are 
// updated and then when all the parameters are
// satisfied then the begin is incremented until
// a small part of the parameter gets unsatisfied
// then again the end is moved forward this is done
// till end reaches end of string and then the substring
// is returned accordingly maybe either smallest or largest
// or even something else
string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, winLen=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-- > 0) counter--; //in t
			// when complete substring found then start
			// shifting begin forward until a single
			// character of t is left out
            while(counter==0){
                if(end-begin<d)  winLen=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return winLen==INT_MAX? "":s.substr(head, winLen);
}
