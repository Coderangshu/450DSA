// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this method*/

// The given question uses the concept from the problem
// to find the maximum rectangle area from the series
// of histograms given as input. See the problem here:
// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

int largestRectHistogram(int arr[],int n){
    // The concept used here is to store the index of the bars
    // until the height of the next bar is lesser than the
    // previous bar. As soon a a lesser height bar is obtained
    // all the previous possible rectangle areas are calculated
    // and the maximum of them is stored.
    int maxArea = INT_MIN;
    int area = 0;
    int i;
    stack<int> stk;
    for(i=0;i<n;){
	// If stack is empty or the height of the last index in stack
	// is lesser or equal than the new height's index is stored in
	// stack. 
        if(stk.empty() || arr[i]>=arr[stk.top()]) stk.push(i++);
        else{
	    // When the last index's height is greater than current 
	    // index's height we pop the last index from the stack
	    // and calculate all the possible areas possible using it.
            int top = stk.top();
            stk.pop();
	    // If stack is empty after the last popping then it means
	    // that this is the index with the smallest height so far,
	    // so area calculated is 
	    // (height of this bar)*(number of bars searched through so far).
            if(stk.empty()) area = arr[top]*i;
	    // Else we take the area as
	    // (height of bar)*(number of bars searched through so far - last index in stack)
	    // above the last index is subtracted because that bar has the height just less
	    // than the height of the popped bar's height, so the rectangle cannot extend
	    // horizonatally left beyond that index.
            else area = arr[top]*(i-(stk.top()+1));
            maxArea = (area>maxArea)?area:maxArea;
        }
    }
    // This loop is runned to check if there are further indexes stored in the stack,
    // if so then the same above two steps are followed to find and check if the area found
    // is maximum or not.
    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        if(stk.empty()) area = arr[top]*i;
        else area = arr[top]*((i-1)-stk.top());
        maxArea = (area>maxArea)?area:maxArea;   
    }
    return maxArea;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    // Here for this problem we use the above concept for each row
    // Lets consider an example question:
    // Let given matrix be:
    // 0 1 1 0
    // 1 1 1 1
    // 1 1 1 1
    // 1 1 0 0
    // we calculate for the first row, which is<t_ýb>
    // 0 1 1 0
    int maxArea = largestRectHistogram(M[0],m);
    // maxArea now is 2.
    for(int i=1;i<n;i++){
	// Now for the next rows we update the rows to stack the above ones
	// into them.
	// Example: 1 1 1 1  gets updated to 1 2 2 1
	// If 0 is encountered as any of the element in the current row
	// than there is no change
	// Example:1 1 0 0 gets updated to 3 4 0 0
	// Thus the complete modified matrix looks like this now,
	// 0 1 1 0
	// 1 2 2 1
	// 2 3 3 2
	// 3 4 0 0
	// for each row the maximum rectangle area in histogram approach is used
	// individually.
        for(int j=0;j<m;j++) if(M[i][j]) M[i][j] += M[i-1][j];
        maxArea = max(maxArea,largestRectHistogram(M[i],m));
    }
    return maxArea;
}
// For better understanding the logic of the histogram problem see this:
// https://www.youtube.com/watch?v=ZmnqCZp9bBs
// For better understanding the logic of the row update and the calculation of
// the max areas of each row refer this:
// https://www.youtube.com/watch?v=dAVF2NpC3j4
