#include<bits/stdc++.h>
using namespace std;




// Method 1 (Dynamic Programming):
// TC : O(h*a) SC : O(h*a*3)

int Max(int a, int b, int c){
    return max(a,max(b,c));
}

int memo[1001][1001][3];

int recursion(int h, int a, int curState){
    if(h<=0 or a<=0) return 0;
    
    if(memo[h][a][curState]!=-1) return memo[h][a][curState];
    
    int air = 0, water = 0, fire = 0;
    // if not air then next step can be air
    if(curState!=0) air = 1 + recursion(h+3,a+2,0);
    // if not water then next step can be water
    if(curState!=1) water = 1 + recursion(h-5,a-10,1);
    // if not fire then next step can be fire
    if(curState!=2) fire = 1 + recursion(h-20,a+5,2);
    
    return memo[h][a][curState] = Max(air,water,fire);
}

int memoization(int h, int a){
    if(h==0 or a==0) return 0;
    memset(memo,-1,sizeof(memo));
    // starting from either of 3 which gives maximum
    //            air(0)                  water(1)                 fire(2)
    int ans = Max(recursion(h+3,a+2,0),recursion(h-5,a-10,1),recursion(h-20,a+5,2));
    return ans;
}









//  Method 2 (Greedy):
// TC : O(h*a) SC : O(1)

// greedy approach
int greedy(int h, int a){
    // greedy approach
    if(h==0 or a==0) return 0;
    else{
        int time = 1;
        // going to air at start
        h += 3;
        a += 2;
        
        while(true){
            // taking 2 steps at a time
            // alternating b/w air and fire/water
            // going to water and back to air
            if(h>5 and a>10){
                h -= 2;
                a -= 8;
                time += 2;
            }
            // goin to fire and back to air
            else if(h>20){
                h -= 17;
                a += 7;
                time += 2;
            }
            // else no option left but die
            else return time;
        }
    }
}





int main(){
    int t;
    cin>>t;
    // #             H     A
    // 1. Air    -> +3    +2
    // 2. Water  -> -5    -10
    // 3. Fire   -> -20   +5
    while(t--){
        int h,a;
        cin>>h>>a;

        // memoization gives inconsistent answer don't know why
//         int ans = memoization(h,a);
        int ans = greedy(h,a);
        
        cout<<ans<<endl;
        
    }
    return 0;
}

