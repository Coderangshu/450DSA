// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    // Your code here
    // Two extra arrays were used thus O(n) auxillary space.
    // Three times traversal occurs through the whole array 
    // thus O(n) time complexity.
    int water = 0;
    int max_level = INT_MIN;
    int rl[n];
    int lr[n];
    for(int i=0;i<n;i++){
        max_level = max(arr[i],max_level);
        lr[i] = max_level;
    }
    max_level = INT_MIN;
    for(int i=n-1;i>=0;i--){
        max_level = max(arr[i],max_level);
        rl[i] = max_level;
    }
    for(int i=0;i<n;i++) water += min(lr[i],rl[i])-arr[i];
    return water;
}

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
