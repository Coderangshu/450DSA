#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int boardLen = board.size();
        
        // Converting 2D into 1D
        vector<int> OneD;
        for(int i=boardLen-1;i>=0;i--){
            if((boardLen-i)%2!=0)
                for(int j=0;j<boardLen;j++)
                    OneD.push_back(board[i][j]);
            else
                for(int j=boardLen-1;j>=0;j--)
                    OneD.push_back(board[i][j]);
        }
        
        // Normal BFS
        // queue stores the node number and steps travelled so far
        queue<pair<int,int>> q;
        q.push({0,0});
        
        // maintaining visited to keep track of already visited nodes
        vector<bool> visited(boardLen*boardLen,false);
        // marking first node as visited
        visited[0] = true;
        
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            int cn = n.first, steps = n.second;
            if(cn==boardLen*boardLen-1) return steps;
            
            // Traversing the adjacent nodes
            // here the six steps from the dice
            for(int i=1;i<=6 and cn+i<OneD.size();i++){
                int nn = (OneD[cn+i]==-1)?cn+i:(OneD[cn+i]-1);
                if(!visited[nn]){
                    visited[nn] = true;
                    q.push({nn,steps+1});
                }
            }
        }
        // If no path exist than code reaches here and returns -1
        return -1;
    }
};
