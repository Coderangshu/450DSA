# Question Link : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15
# Given the string s, return the size of the longest substring
# containing each vowel an even number of times.
# That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

# we keep track of odd or even count for each of the 5 vowel in a single bitmask
# for each substring we want the bitmask to be 00000 because it means all vowel count is even
# we will have 2^5 = 32 states to store atmost in a map to denote which vowels are present odd times
# so to keep the state of each required substring (00000), the start and end state of each substring
# should be same so that on substracting we get get 00000, meaning all vowels are even times from start to end
# and also we just store each state once and only the first occurence of it because we need the longest substring
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        vowel = "aeiou"
        firstOccurenceOfBitmask = dict({0:-1})
        bitMask = 0
        ans = 0
        for i,c in enumerate(s):
            if c in vowel:
                mask = ord(c)-ord('a')+1
                bitMask ^= mask
            if bitMask in firstOccurenceOfBitmask:
                ans = max(ans,i-firstOccurenceOfBitmask[bitMask])
            else:
                firstOccurenceOfBitmask[bitMask] = i
        return ans
