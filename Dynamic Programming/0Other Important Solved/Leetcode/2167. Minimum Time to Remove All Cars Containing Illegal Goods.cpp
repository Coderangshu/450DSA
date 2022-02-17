// Using DP
class Solution {
public:
    int minimumTime(string s) {
        int n = s.length(), ans = INT_MAX;
        
        // Each of the 3 vectors stores:
        // fromLeft    -> removing all elements from left(irrespective of 0 or 1)
        // fromRight   -> removing all elements from right(irrespective of 0 or 1)
        // fromBetween -> removing from between only if 1
        vector<int> fromLeft(n), fromRight(n), fromBetween(n);
        
        for(int i=n-1;i>=0;i--) fromRight[i] = (s[i]=='1')?n-i:((i==n-1)?0:fromRight[i+1]);
        
        for(int i=0;i<n;i++){
            if(i==0){
                // for fromLeft we remove cars irrespective of index of 0 or 1
                // thus taking 1 unit time
                fromLeft[i] = 1;
                // as this is the first thus 
                // if 1 then only 1 unit time will be used to remove this car
                // else 0 unit time will be used as we don't remove this car
                fromBetween[i] = (s[i]=='1')?1:0;
            }
            else{
                // for fromLeft we remove every car thus taking 1 unit time more than previous
                fromLeft[i] = fromLeft[i-1]+1;
                // for fromBetween at this car the total time upto previous would be the min
                // of fromLeft and fromBetween (as this would include all cases of either
                // removing all cars upto this index or removing some cars from between or
                // removing some of the first left cars and some from between)
                // in addition to upto the previous car if this car is 1 then another extra
                // 2 units of time would be used else 0 unit of time would be used
                fromBetween[i] = min(fromLeft[i-1],fromBetween[i-1])+((s[i]=='1')?2:0);
            }
            // the final answer upto this index would be min(fromLeft[i],fromBetween[i])+fromRight[i+1]
            // we store the min of all these in ans
            ans = min(ans,min(fromLeft[i],fromBetween[i])+((i+1<n)?fromRight[i+1]:0));
        }
        return ans;
    }
};



// Using Kadane's algorithm
class Solution {
public:
    int minimumTime(string s) {
        // Take some elements from the left
        // Take some elements from the right
        // Take the rest elements from the middle.
        // So we end up with equation : len(left) + 2* count(middle, 1) + len(right)
        // on simplyfying above len(left) + len(middle) + len(right) + 2*count(middle, 1) - len(middle)
        // on further simplyfying n + count(middle, 1) - count(middle, 0)
        
        // thus we need to minimize count(1)-count(0) in whole array
        // by replacing 0 by -1 and calculating there sum we can get the smallest
        // sum using Kadane's algorithm, thus minimizing the count(1)-count(0).
        int n = s.length();
        vector<int> arr;
        for(auto &c:s){
            if(c=='1') arr.push_back(1);
            else arr.push_back(-1);
        }
        int minSoFar = arr[0], minHere = arr[0];
        for(int i=1;i<n;i++){
            minHere = min(minHere+arr[i],arr[i]);
            minSoFar = min(minSoFar,minHere);
        }
        // if minSoFar is positive means ther's more
        // 1s then 0s thus we need to remove all which
        // can be done in 1 unit time for each index, this
        // will give the min result.
        return n+min(0,minSoFar);
    }
};