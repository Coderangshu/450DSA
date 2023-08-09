# Question : https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

# until sum/n < largest battery
# these large batteries can be used to power
# a single machine until end
# thus we remove those batteries and each computer
# untill sum/n > largest battery in remaining pile
# all these remaining batteries will power the rest
# of the machine untill all of these small batteries
# drys out
# NOTE: the largest batteries remove from the pile at the
# beginning wil still contain some juice in them after ending

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        batteries.sort(reverse=True)
        sm = sum(batteries)
        print(batteries)
        i = 0
        while batteries[i]>sm/n:
            sm -= batteries[i]
            i += 1
            n -= 1
        return sm//n