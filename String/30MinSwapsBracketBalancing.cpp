#include<bits/stdc++.h>
using namespace std;

long swapCount(string s) 
{
     
    // Stores total number of Left brackets
    // encountered
    long countLeft = 0;
     
    // swap stores the number of swaps 
    // required, imbalance maintains 
    // the number of imbalance pair
    long swap = 0 , imbalance = 0; 
      
    for(int i = 0; i < s.length(); i++) {
        if(s[i]=='['){
            if(i<s.length()-1 and s[i+1] == ']'){
                i++;
                continue;
            }
            if(imbalance>0){
                imbalance--;
                swap++;
                continue;
            }
            countLeft++;
        }
        else{
            if(countLeft>0){
                if(countLeft>=imbalance){
                    countLeft = countLeft-imbalance;
                    imbalance = 0;
                    continue;
                }
                countLeft = imbalance-countLeft;
                imbalance = imbalance-countLeft;
                continue;
            }
            imbalance++;
        }
    }
    return swap;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    string s;
	    cin>>n>>s;
	    cout<<swapCount(s)<<endl;
	}
	return 0;
}
