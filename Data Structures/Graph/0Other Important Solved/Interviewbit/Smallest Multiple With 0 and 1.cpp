// Question : https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

// build the multiple starting from 1 and add either 1 or 0
// if a certain remainder already obtained we do not continue 
// in this path as same remainder with larger multiple will be
// of no use, thus atmost we need to traverse for n states to get
// to the answer using BFS

class Solution{
    multiple(int A) {
        if(A==1) return "1";
        queue<pair<string,int>> q;
        q.push({"1",1});
        vector<bool> visited(A,false);
        visited[1] = true;
        while(!q.empty()){
            auto [s,r] = q.front();
            q.pop();
            int r0 = (10*r)%A, r1 = (10*r+1)%A;
            if(r0==0) return s+"0";
            if(!visited[r0]){
                visited[r0] = true;
                q.push({s+"0",r0});
            }
            if(r1==0) return s+"1";
            if(!visited[r1]){
                visited[r1];
                q.push({s+"1",r1});
            }
        }
        return "";
    }
};
