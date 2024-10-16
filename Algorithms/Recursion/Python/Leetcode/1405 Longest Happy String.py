'''
Question link: https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16
A string s is called happy if it satisfies the following conditions:

    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.

Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.
'''

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int, aa='a', bb='b', cc='c') -> str:
        if a<b:
            return self.longestDiverseString(b,a,c,bb,aa,cc)
        if b<c:
            return self.longestDiverseString(a,c,b,aa,cc,bb)
        if b==0:
            ause = min(a,2)
            return aa*ause
        ause = min(a,2)
        buse = 1 if a-ause>=b else 0
        return aa*ause+bb*buse+self.longestDiverseString(a-ause,b-buse,c,aa,bb,cc)
