class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(S==0){
            if(D==1) return "0";
            else return "-1";
        }
        
        // if S > largest D digit #
        if(S>9*D) return "-1";
        
        if(D==1) return to_string(S);
        // fill from right to left
        // fill with 9 if possible and
        // go to left filling
        
        // keeping 1 from S to fill at the MSB
        // if S becomes 0 before filling all places
        // all the rest in between are filled with 0
        S -= 1;
        string ans = "";
        for(int i=0;i<D-1;i++){
            if(S>=9){
                ans = to_string(9)+ans;
                S -= 9;
            }
            else{
                ans = to_string(S)+ans;
                S -= S;
            }
        }
        // if S is not 0 after filling D-1 digits
        // add the MSB as S+1
        if(S!=0) ans = to_string(S+1)+ans;
        // else add the previously kept 1 in MSB
        else ans = "1"+ans;
        return ans;
    }
};