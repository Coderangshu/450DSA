// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    // function to check if the max allowed # of pages to a student leads to assigning
    // all the books to all the students
    bool allStudentGetsBook(int arr[], int n, int allowedMaxPages, int noOfStu){
        // assign 1st book to 1st student
        int sumOfPages = arr[0], stuGotBooks = 1;
        for(int i=1;i<n;i++){
            // if no of pages assigned to current student + the new book's pages
            // is less than the allowed max then assign book to this student
            if(arr[i]+sumOfPages<=allowedMaxPages) sumOfPages += arr[i];
            // else assign book to the next student
            else{
                // assigned to next student thus # of student assigned book
                // incremented
                stuGotBooks++;
                // sum of pages for this current student is this book only
                // thus sumOfPages is reset to this books # of pages
                sumOfPages = arr[i];
            }
            // if at any point the no of students assigned books becomes more than
            // the # of students at total thus this allowed # of max pages isn't
            // possible thus return false
            if(stuGotBooks>noOfStu) return false;
        }
        // if reached here then all students assigned all books 
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        // if students are more than books than atleast one
        // student has to be allocated 0 books that violates a
        // condition
        if(m>n) return -1;
        // the search space consist of the max pages that can be allocated to
        // a student, atleast one book is to be allocated to a student, thus
        // the max paged book is the minimum max pages that can be allocated,
        // an at max all books can be given thus the sum of all pages is the
        // max pages that can be allocated to a student(if only one student is there)
        int low = *max_element(arr,arr+n), high = accumulate(arr,arr+n,0);
        
        // now we need to find the minimum of the max allocated pages to a student
        // thus we search for the min no of pages from the max allowed pages search
        // space, we use binary search
        int ans = -1;
        while(low<=high){
            int mid = (low+high)>>1;
            // if all students get allocated all the books then mid
            // is a possible solution but we don't stop searching here
            // as we need the minimum value that satifies all the given
            // conditions thus we search in the lower half
            if(allStudentGetsBook(arr,n,mid,m)){
                ans = mid;
                high = mid-1;
                
            }
            // if not satisfying the condition then we need to increase
            // the allowed maximum pages to a student thus search in upper
            // half
            else low = mid+1; 
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
