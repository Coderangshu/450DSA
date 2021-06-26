// { Driver Code Starts



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Method: The concept is completely similar to the unbounded coin change problem
// here we just need to store all the possible solutions using backtracking
// and also the ordering of the answer in ascending for both the inner vectors
// and the outer vector is to be done, and also there shouldn't be any repeating
// combination in the answer

// To get the ordered and unique solution we need to process the input array of
// the given numbers, we sort them and then remove the duplicates if present
// then send for finding the suitable combinations, this gives us only the unique
// combinations and also in sorted way
// Now to sort the vectors we apply sort on the vector of vector to get so


class Solution 
{
    public:
    
    vector<vector<int>> ans;
    
    // Unbounded coin change problem with backtracking
    void combinationSumUtil(vector<int> &a, int index, vector<int> &currentArr, int b){
        
        // if sum becomes 0 then push to ans
        if(b==0){
            ans.push_back(currentArr);
            return;
        }
        
        // if index has reached end then return
        if(index>=a.size()) return;
        
        // if the number at index is greater then the sum
        // ignore and go to next index
        if(a[index]>b){
            combinationSumUtil(a,index+1,currentArr,b);
            return;
        }
        
        // else if sum is not 0 then we have 2 choices either
        // take the number or not take the number
        if(b!=0){
            // number is taken
            currentArr.push_back(a[index]);
            // function called again with the sum reduces but
            // the index isn't increased as it can be again
            // included in the combinations
            combinationSumUtil(a,index,currentArr,b-a[index]);
            // remove number from taken list
            currentArr.pop_back();
            // function called with the number not taken
            // and the index is incremented as this number
            // has been processed
            combinationSumUtil(a,index+1,currentArr,b);
            return;
        }
    }
    
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        // Your code here
        
        // sort the given vector
        sort(A.begin(),A.end());
        // remove duplicates(this can only be done in sorted array
        // thus sort array first then remove duplicate)
        A.erase(unique(A.begin(),A.end()),A.end());
        
        // currentArr to store the current combination
        vector<int> currentArr;
        // recursive funtion called with index initialized to 0
        combinationSumUtil(A,0,currentArr,B);

        // sort the vector of vector
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
