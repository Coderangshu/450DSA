#include<bits/stdc++.h>
using namespace std;

// Function to find precedence of operators
int prec(char a){
    if(a=='^') return 3;
    if(a=='*' or a=='/') return 2;
    if(a=='+' or a=='-') return 1;
    // when a=='('
    else return 0;
}

//Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s){
    // stack to store the operators
    stack<char> stk;
    string postfix = "";
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(c=='(') stk.push(c);
        else if(c==')'){
            while(!stk.empty() and stk.top()!='('){
                postfix += stk.top();
                stk.pop();
            }
            if(!stk.empty()) stk.pop();
        }
        else if(c=='^' or c=='*' or c=='/' or c=='+' or c=='-'){
            while(!stk.empty() and prec(c)<=prec(stk.top())){
                postfix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        else postfix += c;
    }
    while(!stk.empty()){
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int calculate(string s){
    int ans = 0;
    // stack stores the operands
    stack<int> stk;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(c>='0' and c<='9') stk.push(c-'0');
        else{
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            if(c=='^') stk.push(pow(b,a));
            else if(c=='/') stk.push(b/a);
            else if(c=='*') stk.push(b*a);
            else if(c=='+') stk.push(b+a);
            else if(c=='-') stk.push(b-a);
        }
    }
    return stk.top();
}

int main(){
    // given infix expression
    string expression1 = "(2+4)*(4+6)";
    string expression = "((2+4)*(4+6)/6)^2";

    // converting to postfix
    string pf = infixToPostfix(expression);
    cout<<pf<<endl;

    cout<<calculate(pf)<<endl;

    return 0;
}
