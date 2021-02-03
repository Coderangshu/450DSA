    

    

// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}// } Driver Code Ends


// This function returns true if str1 and str2 are ismorphic
// else returns false
bool areIsomorphic(string str1, string str2)
{
    // Your code here
    int m = str1.length(), n = str2.length(); 
  
    // Length of both strings must be same for one to one 
    // corresponance 
    if (m != n) 
      return false; 
  
    // To mark visited characters in str2 
    bool marked[256] = {false}; 
  
    // To store mapping of every character from str1 to 
    // that of str2. Initialize all entries of map as -1. 
    int map[256]; 
    memset(map, -1, sizeof(map)); 
  
    // Process all characters one by on 
    for (int i = 0; i < n; i++) 
    { 
        // If current character of str1 is seen first 
        // time in it. 
        if (map[str1[i]] == -1) 
        { 
            // If current character of str2 is already 
            // seen, one to one mapping not possible 
            if (marked[str2[i]] == true) 
                return false; 
  
            // Mark current character of str2 as visited 
            marked[str2[i]] = true; 
  
            // Store mapping of current characters 
            map[str1[i]] = str2[i]; 
        } 
  
        // If this is not first appearance of current 
        // character in str1, then check if previous 
        // appearance mapped to same character of str2 
        else if (map[str1[i]] != str2[i]) 
            return false; 
    } 
  
    return true; 
}
