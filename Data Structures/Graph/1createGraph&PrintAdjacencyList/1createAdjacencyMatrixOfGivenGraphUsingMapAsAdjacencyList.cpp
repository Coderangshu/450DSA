#include<bits/stdc++.h>
using namespace std;

// template helps us to generalize the datatype of anything
// T is replaced with the required datatype in the functions
// implemented under the template
template<typename T>
class Graph{
private:
    // List is similar to vector, list uses dynamic memory
    // allocation vector uses contiguous memory allocation
    // thus vector elements can be accessed randomly
    // but list cannot be accessed randomly as it has to
    // go through double link list to get to certain element
    map<T,list<pair<T,int>>> adjacencyList;
public:
    void addEdge(T u, T v, int weight, bool bidirectional=true){
        adjacencyList[u].push_back(make_pair(v,weight));
        if(bidirectional)
        adjacencyList[v].push_back(make_pair(u,weight));
    }
    
    void printAdjacencyList(){
        cout<<"Node 1"<<"  "<<"Node 2   Weight"<<endl;
        for(auto e:adjacencyList){
            cout<<e.first<<": "<<endl;
            for(auto f:e.second)
                cout<<"          "<<f.first<<"         "<<f.second<<endl;
        }
    }
};

int main(){
    Graph<char> g;
    g.addEdge('0', '1',4, 0);
	g.addEdge('0', '7',8, 0);
	g.addEdge('1', '7',11, 0);
	g.addEdge('1', '2',8, 0);
	g.addEdge('7', '8',7, 0);
	g.addEdge('2', '8',2, 0);
	g.addEdge('8', '6',6, 0);
	g.addEdge('2', '5',4, 0);
	g.addEdge('6', '5',2, 0);
	g.addEdge('2', '3',7, 0);
	g.addEdge('3', '3',14, 0);
	g.addEdge('3', '4',9, 0);
	g.addEdge('5', '4',10, 0);
	g.addEdge('7', '6',1, 0);
	g.printAdjacencyList();
}
