// Question
// Link : https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/
// Given an array of integers and a number k, write a function that returns true if given array 
// can be divided into pairs such that sum of every pair is divisible by k.
  

// Brute force : Try all possible pairs and check if their sum.
// Time complexity : O(n^2)

// Using unordered map to store the count of each number's remainder.
// For each remainder we have 3 choices:
// remainder == 0 -> check if this remainder's frequency is even.
// remainder == k/2 -> check if this remainder's frequency is even.
// rest of the remainder -> check if this remainder's frequency and (k-remainder) frequency is same.

// Time complexity : O(n)
// Space complexity : O(n)
class Solution{
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n%2!=0) return false;
        unordered_map<int,int> um;
        for(auto &e:nums) um[e%k]++;
        for(auto &e:nums){
            int rem = e%k;
            if(rem==0 or 2*rem==k){
                if(um[rem]%2!=0) return false;
            }
            else{
                if(um[rem]!=um[k-rem]) return false;
            }
        }
        return true;
    }
};