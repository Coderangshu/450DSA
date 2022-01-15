// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

const int no_of_chars = 256;

string findSubString(string str);

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;

        cout << findSubString(str).size() << endl;
    }
    return 0;
}
// } Driver Code Ends




string findSubString(string str)
{
    // Your code goes here 
    int len = str.length();
    int distinctCount = 0;
    bool visited[256] = {false};
    // We count the number of distinct characters in the
    // complete string, and also make the visited characters
    // set to true.
    // See 37SmallestWindowInStringContainingAllCharactersOfAnotherString.cpp
    // for explanation.
    for(int i=0;i<len;i++){
        if(visited[str[i]]==false){
            visited[str[i]] = true;
            distinctCount++;
        }
    }
    int char_count[256] = {0};
    int start = 0,count = 0,minLen = INT_MAX,start_index = 0;
    for(int i=0;i<len;i++){
        char_count[str[i]]++;
        if(char_count[str[i]]==1) count++;
        if(count==distinctCount){
            while(char_count[str[start]]>1){
                if(char_count[str[start]]>1) char_count[str[start]]--;
                start++;
            }
            int winLen = i-start+1;
            if(minLen>winLen){
                minLen = winLen;
                start_index = start;
            }
        }
    }
    return str.substr(start_index,minLen);
}
