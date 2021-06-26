class Solution {
public:

    
    
    // Method 1(slower):
    // Traverse through the given string
    // remove each bracket(either open or close) and check if resultant is valid
    
    
    // function to get the min number of bracket removals
    // when this returns 0 means the string is valid as no
    // further removals are required
    int getMinBrackToDel(string s){
        stack<char> stk;
        for(auto e:s){
            if(e=='(') stk.push(e);
            else if(e==')'){
                if(stk.empty()) stk.push(e);
                else if(stk.top()=='(') stk.pop();
                else stk.push(e);
            }
        }
        return stk.size();
    }
    
    // removes each bracket and checks if resultant is valid
    void removeInvalidParenthesesUtil(string s, unordered_set<string> &ans, int toDel){
        // if number of parenthesis to del is 0 and string is valid
        // add to ans
        if(toDel==0 and getMinBrackToDel(s)==0){
            ans.insert(s);
            return;
        }
        
        // if still there are brackets to be deleted
        else if(toDel>0){
            int n = s.length();
            
            // removing each parenthesis and checking the resultant string
            for(int i=0;i<n;i++){
                if(s[i]=='(' or s[i]==')'){
                    string nstr = s.substr(0,i)+s.substr(i+1,n-i-1);
                    removeInvalidParenthesesUtil(nstr,ans,toDel-1);
                }
            }
            return;
        }
    }
    
    
    
    
    
    // Method 2 (faster):
    // Get the extra number of opening and closing parenthesis
    
    // we create the possible valid strings by traversing the given string and making
    // a decision of either taking or rejecting a parenthesis changing the number of 
    // open and close brackets and also number of open pairs accordingly
    
    // if at any point any of the 3 becomes negative we know that arrangement of string
    // upto that point is wrong thus avoiding it and continuing further
    
    // this way we traverse the given string and when we reach the end we check if all
    // open and close parenthesis have been removed or not and also all open pairs have
    // been closed if so then this is a valid answer add it to ans
    
    void removeInvalidParenthesesUtil(string &s, int index,unordered_set<string> &ans, string tstr,
                                      int leftBrackToBeRemoved, int rightBrackToBeRemoved, int openPair){
        
        // base case
        // if any of the 3 parameters become negative continue
        if(leftBrackToBeRemoved<0 or rightBrackToBeRemoved<0 or openPair<0) return;
        // if given string's traversal completed
        else if(index==s.length()){
            // if all 3 parameters are 0 then valid string found
            if(leftBrackToBeRemoved==0 and rightBrackToBeRemoved==0 and openPair==0)
                ans.insert(tstr);
            // end of given string reached thus ending recursion call
            return;
        }
        
        // Every step inside is a backtraked process as no change is made permanently
        // they are worked upon in there own paths without disturbing the processes below
        else{
            if(s[index]=='('){
                // add to resultant string
                // this opens up a new open pair 
                removeInvalidParenthesesUtil(s,index+1,ans,tstr+s[index], 
                                             leftBrackToBeRemoved, rightBrackToBeRemoved, openPair+1);
                // don't add
                // this means we deleted a open/left bracket from given string
                removeInvalidParenthesesUtil(s,index+1,ans,tstr, 
                                             leftBrackToBeRemoved-1, rightBrackToBeRemoved, openPair);
            }
            else if(s[index]==')'){
                // add to resultant string
                // this closes an open pair 
                removeInvalidParenthesesUtil(s,index+1,ans,tstr+s[index], 
                                             leftBrackToBeRemoved, rightBrackToBeRemoved, openPair-1);
                // don't add
                // this means we deleted a close/right bracket from given string
                removeInvalidParenthesesUtil(s,index+1,ans,tstr, 
                                             leftBrackToBeRemoved, rightBrackToBeRemoved-1, openPair);
            }
            // if not a parenthesis(i.e. its an alphabet) add to resultant string 
            else removeInvalidParenthesesUtil(s,index+1,ans,tstr+s[index],
                                              leftBrackToBeRemoved, rightBrackToBeRemoved, openPair);
            return;
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        // stack is used to store the unique resultant strings
        unordered_set<string> ans;
        
        
        
        // Method 1 driver
        
        // int bracksToDel = getMinBrackToDel(s);
        // removeInvalidParenthesesUtil(s,ans,bracksToDel);
        
        
        
        // Method 2 driver
        
        // the open/left and close/right extra parenthesis are calculated
        int lRm = 0, rRm = 0;
        for(auto letter:s){
            if(letter=='(') lRm++;
            else if(letter==')'){
                if(lRm>0) lRm--;
                else rRm++;
            }
        }
        // index initialized to 0 and for the resultant string the
        // number of openPair at beginning is 0 as there are no characters
        // in it
        removeInvalidParenthesesUtil(s,0,ans,"",lRm,rRm,0);
        
        // set converted to vector and returned
        return vector<string>(ans.begin(),ans.end());
    }
};

