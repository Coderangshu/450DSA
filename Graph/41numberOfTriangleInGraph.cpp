// C++ program to count triangles
// in a graph. The program is for
// adjacency matrix representation
// of the graph.
#include<bits/stdc++.h>

// Number of vertices in the graph
#define V 4

using namespace std;







// Method 1: count all triplets which form a triangle
//           T(n) = O(n^3) 




// function to calculate the
// number of triangles in a
// simple directed/undirected
// graph. isDirected is true if
// the graph is directed, its
// false otherwise
int countTriangle(int graph[V][V], bool isDirected){
	// Initialize result
	int count_Triangle = 0;

	// Consider every possible triplet of edges in graph
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			for (int k = 0; k < V; k++){
			// Check the triplet if it satisfies the condition
			if (graph[i][j] && graph[j][k]&& graph[k][i])
				count_Triangle++;
			}
		}
	}

	// If graph is directed, division is done by 3,
	// else division by 6 is done
	// as in undirected graph each triablge is counted 6 times
	// as the triplet for each triangle is considered 6 times
	// and for directed the direction matters thus each is
	// counted 3 times thus dividing by 3
	isDirected? count_Triangle /= 3:count_Triangle /= 6;

	return count_Triangle;
}

//driver function to check the program
int main()
{
	// Create adjacency matrix of an undirected graph
	int graph[][V] = {{0, 1, 1, 0},
					  {1, 0, 1, 1},
					  {1, 1, 0, 1},
					  {0, 1, 1, 0}
                     };

	// Create adjacency matrix of a directed graph
	int digraph[][V] = {{0, 0, 1, 0},
						{1, 0, 0, 1},
						{0, 1, 0, 0},
						{0, 0, 1, 0}
                       };

	cout << "The Number of triangles in undirected graph : "
		<< countTriangle(graph, false);
	cout << "\n\nThe Number of triangles in directed graph : "
		<< countTriangle(digraph, true);

	return 0;
}






// Method 2: Find A^3 if graph's adjacency matrix is A
//           then trace(A^3)/6 gives the no. of triangles
//           ONLY FOR UNDIRECTED GRAPH
//           T(n) = O(n^3) (can be reduced to O(n^2.8074) is
//           using Strassen Matrix multiplication) 


//  Utility function for matrix multiplication
void multiply(int A[][V], int B[][V], int C[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < V; k++)
                C[i][j] += A[i][k]*B[k][j];
        }
    }
}
 
// Utility function to calculate trace of a matrix (sum of
// diagnonal elements)
int getTrace(int graph[][V])
{
    int trace = 0;
    for (int i = 0; i < V; i++)
        trace += graph[i][i];
    return trace;
}
 
//  Utility function for calculating number of triangles in graph
int triangleInGraph(int graph[][V])
{
    // To Store graph^2
    int aux2[V][V];
 
    // To Store graph^3
    int aux3[V][V];
 
    //  Initialising aux matrices with 0
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            aux2[i][j] = aux3[i][j] = 0;
 
    // aux2 is graph^2 now  printMatrix(aux2);
    multiply(graph, graph, aux2);
 
    // after this multiplication aux3 is graph^3 printMatrix(aux3);
    multiply(graph, aux2, aux3);
 
    int trace = getTrace(aux3);
    return trace / 6;
}

// driver code
int main()
{
 
    int graph[V][V] = {{0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                      };
 
    printf("Total number of Triangle in Graph : %d\n",
            triangleInGraph(graph));
    return 0;
}
