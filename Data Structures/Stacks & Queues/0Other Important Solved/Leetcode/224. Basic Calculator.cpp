class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int sign = 1;
        int ans = 0;
        int num = 0;
        for(auto c:s){
            if(c>='0' and c<='9') num = 10*num+(c-'0');
            else if(c=='+'){
                ans += sign*num;
                num = 0;
                sign = 1;
            }
            else if(c=='-'){
                ans += sign*num;
                num = 0;
                sign = -1;
            }
            else if(c=='('){
                stk.push(ans);
                stk.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(c==')'){
                ans += sign*num;
                num = 0;
                ans *= stk.top();
                stk.pop();
                ans += stk.top();
                stk.pop();
            }
        }
        if(num!=0) ans += sign*num;
        return ans;
    }
};