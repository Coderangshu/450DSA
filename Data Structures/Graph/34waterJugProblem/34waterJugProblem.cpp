#include<bits/stdc++.h>
using namespace std;






// The method is to traverse to the next Possible states from the current
// state, the same can be done either using recursion or DFS or BFS
// BFS is preferred as it provides the fastest answer
// There are 3 possible states from current state:
// (I)    Fill either of the jug completely
// (II)   Empty either of the jugs
// (III)  Fill either of them using the other until the other is completely
//        empty or until the one being filled is full

// The above methodology is executed below using memoization and BFS 


// DFS isn't used because it might come up with a solution that might not
// be the shortest path, or in any of the branch it goes on computing endlessly
// thus might give TLE, BFS looks through all the possibilities at every level






// Using memoization
struct jugTarget{
    int jug1,jug2,target;
    jugTarget(int a, int b, int c){
        this->jug1 = a;
        this->jug2 = b;
        this->target = c;
    }
};

bool visited[1001][1001];

bool waterJugSolver(int amt1, int amt2, jugTarget *jt){
    int j1 = jt->jug1;
    int j2 = jt->jug2;
    int target = jt->target;
    
    // if either of (target,0) or (0,target) is reached we stop
    if((amt1==target and amt2==0) or (amt2==0 and amt1==target)){
        cout<<amt1<<" "<<amt2<<endl;
        return true;
    }
    
    else{
        if(!visited[amt1][amt2]){
            cout<<amt1<<" "<<amt2<<endl;
            visited[amt1][amt2] = true;
            // checking all the reachable states from the current state
            return  waterJugSolver(j1,amt2,jt) or 
                    waterJugSolver(amt1,j2,jt) or
                    waterJugSolver(0,amt2,jt) or 
                    waterJugSolver(amt1,0,jt) or
                    waterJugSolver(amt1+min(amt2,j1-amt1),amt2-min(amt2,j1-amt1),jt) or
                    waterJugSolver(amt1-min(amt1,j2-amt2),amt2+min(amt1,j2-amt2),jt);
        }
        // if all above conditions return false then we reach here
        else return false;
    }
}






// Using BFS

void printPath(pair<int,int> tp, map<pair<int,int>,pair<int,int>> parent){
    if(tp.first==0 and tp.second==0) cout<<tp.first<<" "<<tp.second<<endl;
    else{
        printPath(parent[tp],parent);
        cout<<tp.first<<" "<<tp.second<<endl;
    }
}

void waterJugSolverBFS(int j1, int j2, int amt1, int amt2, int target){
    
    map<pair<int,int>,bool> visited;
    map<pair<int,int>,pair<int,int>> parent;
    
    pair<int,int> target_pair = {0,0};
    
    queue<pair<int,int>> q;
    q.push({amt1,amt2});
    while(!q.empty()){
        auto[a1,a2] = q.front();
        q.pop();
        
        // if either of (target,0) or (0,target) is reached we stop
        if((a1==target and a2==0) or (a1==0 and a2==target)){
            target_pair = make_pair(a1,a2);
            break;
        }
        // if current is not visited we go on searching through its
        // neighbours
        else if(visited.find({a1,a2})==visited.end()){
            visited[{a1,a2}] = true;
            
            // Going through all the 3 possible states
            // 2 of each making total 6 neighbours for each
            // node
            
            if(visited.find({j1,a2})==visited.end()){
                parent[{j1,a2}] = {a1,a2};
                q.push({j1,a2});
            }
            
            if(visited.find({a1,j2})==visited.end()){
                parent[{a1,j2}] = {a1,a2};
                q.push({a1,j2});
            }
            
            if(visited.find({0,a2})==visited.end()){
                parent[{0,a2}] = {a1,a2};
                q.push({0,a2});
            }
            
            if(visited.find({a1,0})==visited.end()){
                parent[{a1,0}] = {a1,a2};
                q.push({a1,0});
            }
            
            if(visited.find({(a1+min(a2,j1-a1)),(a2-min(a2,j1-a1))})==visited.end()){
                parent[{(a1+min(a2,j1-a1)),(a2-min(a2,j1-a1))}] = {a1,a2};
                q.push({(a1+min(a2,j1-a1)),(a2-min(a2,j1-a1))});
            }
            
            if(visited.find({(a1-min(a1,j2-a2)),(a2+min(a1,j2-a2))})==visited.end()){
                parent[{(a1-min(a1,j2-a2)),(a2+min(a1,j2-a2))}] = {a1,a2};
                q.push({(a1-min(a1,j2-a2)),(a2+min(a1,j2-a2))});
            }
        }
    }
    if(target_pair.first==0 and target_pair.second==0) cout<<"Not Possible"<<endl;
    printPath(target_pair,parent);
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // memoization
//     memset(visited,false,sizeof(visited));
//     jugTarget *jt = new jugTarget(4,3,2);
//     waterJugSolver(0,0,jt);
    
    // BFS 
    waterJugSolverBFS(4,3,0,0,2);
    return 0;
}
