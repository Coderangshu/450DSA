// Question : https://leetcode.com/problems/reverse-pairs/
// Solved for arrays with +ve values only (yet)

// BIT stores the frequency of each element in running order
// for each element first check total frequencies of elements
// greater than 2 * element, add that to answer than update
// BIT with the element, i.e. increase its count by 1

// Example dry run :
// array = [2,4,3,5,1]
// initially : frequency array = [0,0,0,0,0] -> 1 indexed (not actual BIT array, this is the overall visualization of it)

// i = 0 : total frequency of all elements greater than 2*array[i](=4) already found in array = 0 (see previous state of frequency array)
//         after updating frequency array = [0,1,0,0,0]
// i = 1 : total frequency of all elements greater than 2*array[i](=8) already found in array = 0 (see previous state of frequency array)
//         after updating frequency array = [0,1,0,1,0]
// i = 2 : total frequency of all elements greater than 2*array[i](=6) already found in array = 0 (see previous state of frequency array)
//         after updating frequency array = [0,1,1,1,0]
// i = 3 : total frequency of all elements greater than 2*array[i](=10) already found in array = 0 (see previous state of frequency array)
//         after updating frequency array = [0,1,1,1,1]
// i = 4 : total frequency of all elements greater than 2*array[i](=2) already found in array = 3 (see previous state of frequency array)
//         after updating frequency array = [1,1,1,1,1]

// thus answer is 3

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getSumBIT(int *bit, int n, int i)
    {
        int ans = 0;
        if (i >= n)
            i = n - 1;
        for (; i > 0; i -= i & -i)
            ans += bit[i];
        return ans;
    }

    void updateBIT(int *bit, int n, int i)
    {
        for (; i < n; i += i & -i)
            bit[i] += 1;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int n = (*max_element(nums.begin(), nums.end())) + 1;
        int *BIT = new int[n];
        for (int i = 0; i < n; i++)
            BIT[i] = 0;
        int ans = 0;
        for (auto &e : nums)
        {
            ans += getSumBIT(BIT, n, n - 1) - getSumBIT(BIT, n, 2 * e);
            updateBIT(BIT, n, e);
        }
        return ans;
    }
};