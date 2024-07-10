// Implementation of Prim's algo

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

// Adj matrix
int graph [MAX_VERTICES][MAX_VERTICES];

int primMST(int num_vertices){
    // Ideally we would need to use a min priority queue. 
    int parent[MAX_VERTICES]; // Nodes' parent
    int dists[MAX_VERTICES]; // Nodes' key
    int inMST[MAX_VERTICES]; // If node in the MST

    // Set the dist of all nodes to inf
    for(int i=0; i<MAX_VERTICES; i++){
        dists[i] = INT_MAX;
        inMST[i] = 0;
    }

    dists[0] = 0;
    parent[0] = -1;

    int totalWeight = 0;

    for(int iter=0; iter<num_vertices; iter++){
        int u;
        int minDist = INT_MAX;

        // Find lowest key not in MST
        for(int v=0; v<num_vertices; v++){
            if(dists[v]<minDist && inMST[v]==0){
                minDist = dists[v];
                u = v;
            }
        }

        inMST[u] = 1;
        totalWeight += dists[u];
        // update dists for adj nodes
        for(int v=0;v<MAX_VERTICES;v++){
            if(v==u || inMST[v]==1 || graph[u][v]==INT_MAX)
                continue;

            int w = graph[u][v];
            if(dists[v]>w)
                dists[v]=w;
                parent[v] = u;
        }   
    }

    return totalWeight;
}

void printAdj(){
    for(int i=0; i<MAX_VERTICES; i++){
        for(int j=0; j<MAX_VERTICES; j++){
            if(graph[i][j] == INT_MAX)
                printf("%c ", 'x');
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}


/* Input
9, 14
0, 1, 4
0, 7, 8
1, 2, 8
1, 7, 11
2, 3, 7
2, 5, 4
2, 8, 2
3, 4, 9
3, 5, 14
4, 5, 10
5, 6, 2
6, 7, 1
6, 8, 6
7, 8, 7
*/
/* Answer
The total weight of the MST is 37.
*/

int main(){
    // Obtain number of vertices and number of edges
    int num_vertices, num_edges;
    scanf("%d, %d", &num_vertices, &num_edges);

    // Set all initial values to infinity
    for(int i=0; i<MAX_VERTICES;i++){
        for(int j=0; j<MAX_VERTICES; j++){
            if(i==j)
                graph[i][j] = 0;
            else
                graph[i][j] = INT_MAX;
        }
    }

    for(int i=0; i<num_edges; i++){
        int s, t, w;
        // read an edge: start, end, weight
        scanf("%d, %d, %d", &s, &t, &w);
        graph[s][t] = w;
        graph[t][s] = w;
    }

    // print adj matrix
    //printAdj();

    int res = primMST(num_vertices);
    printf("The total weight is %d\n", res);

    return 0;

}