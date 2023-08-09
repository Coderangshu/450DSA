# Question : https://leetcode.com/problems/number-of-music-playlists/description/

class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        @cache
        def recursion(usedSongs, songListLen):
            if songListLen==goal:
                # return 1 if all songs have been used
                # else return 0
                return usedSongs==n
            # pick usedSong only if k songs have already been used
            ans = recursion(usedSongs,songListLen+1)*max(0,usedSongs-k)
            # pick new song
            ans += recursion(usedSongs+1,songListLen+1)*(n-usedSongs)
            return ans
        return recursion(0,0)%(10**9+7)