from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bitbucket = [0 for _ in range(32)]
        # for each number store its bits into bitbucket
        # in each position i.e. 0th bit to 31st bit
        for e in nums:
            # convert -ve to 2's complement
            if e<0: e &= 2**32-1
            for i in range(32):
                bitbucket[i] += e&1
                e >>= 1
                if e==0: break
        # for each position of bitbucket remove all 3s multiple
        # if still bit is present means it is part of the element
        # appearing just once, thus add a bit to the ans in that position
        ans = 0
        for i in range(31,-1,-1):
            if bitbucket[i]%3!=0: ans |= 1<<i
        # if > 2**31 means it is negative number
        # convert to negative by subtracting 2**32
        if ans>=2**31: ans -= 2**32
        return ans