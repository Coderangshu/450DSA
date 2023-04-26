// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	
	int mx[5] = {0,-1,0,1, 0};
	int my[5] = {0, 0,1,0,-1};
	
	long long memo[10][26];
	long long getCountUtil(vector<vector<char>> &keypad,int i,int j,int n){
	    
	    int number = keypad[i][j]-'0';
	    
	    // if length required <=0
	    if(n<=0) return memo[number][0] = 0;
	    // if length is 1, only one possible
	    // that button itself
	    if(n==1) return memo[number][1] = 1;
	    
	    if(memo[number][n]!=-1) return memo[number][n];
	    
	    long long totCount = 0;
	    for(int move=0;move<5;move++){
	        int nx = i+mx[move];
	        int ny = j+my[move];
	        if(nx>=0 and ny>=0 and nx<4 and ny<3 and keypad[nx][ny]!='*' and keypad[nx][ny]!='#'){
	            totCount += getCountUtil(keypad,nx,ny,n-1);
	        }
	    }
	    return memo[number][n] = totCount;
	}
	
	long long getCount(int N){
		// Your code goes here
		vector<vector<char>> keypad = {{'1','2','3'},
                                       {'4','5','6'},
                                       {'7','8','9'},
                                       {'*','0','#'}};
        
        memset(memo,-1,sizeof(memo));
        long long totCount = 0;
        // Loop on keypad row
        for (int i=0; i<4; i++){
            // Loop on keypad column
            for (int j=0; j<3; j++){
                if(keypad[i][j]!='*' and keypad[i][j]!='#')
                    totCount += getCountUtil(keypad,i,j,N);
            }
        }
        return totCount;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
