# Question : https://leetcode.com/problems/predict-the-winner/description/
from typing import List

class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[[0]*(n+1) for _ in range(n+1)] for _ in range(2)]
        for start in range(n-1,-1,-1):
            for end in range(n):
                for player in range(2):
                    ans = 0
                    if start>end: ans = -1
                    elif start==end: ans = nums[end]
                    elif player==0:
                        ans = max(nums[start]+dp[1][start+1][end],
                        nums[end]+dp[1][start][end-1])
                    else:
                        ans = min(-nums[start]+dp[0][start+1][end],
                        -nums[end]+dp[0][start][end-1])
                    dp[player][start][end] = ans
        return dp[0][0][n-1]>=0