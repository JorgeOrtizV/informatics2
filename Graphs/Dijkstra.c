// Implementation of Dijkstra's algo

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

// Adj matrix
int graph [MAX_VERTICES][MAX_VERTICES];

void Dijkstra(int num_vertices){
    // Ideally we would need to use a min priority queue. 
    int visited[MAX_VERTICES]; // Nodes' parent
    int dists[MAX_VERTICES]; // Nodes' key

    // Set the dist of all nodes to inf
    for(int i=0; i<MAX_VERTICES; i++){
        dists[i] = INT_MAX;
        visited[i] = 0;
    }

    dists[0] = 0;

    for(int iter=0; iter<num_vertices; iter++){
        int u;
        int minDist = INT_MAX;

        // Find lowest key not in MST
        for(int v=0; v<num_vertices; v++){
            if(dists[v]<=minDist && visited[v]==0){
                minDist = dists[v];
                u = v;
            }
        }

        // unable to reach
        if (dists[u] == INT_MAX || u == -1) {
            continue;
        }

        visited[u] = 1;

        // update dists for adj nodes
        for(int v=0;v<num_vertices;v++){
            if(v==u || visited[v]==1 || graph[u][v]==INT_MAX)
                continue;

            int w = graph[u][v];
            if(dists[v]>w+dists[u])
                dists[v]=w+dists[u];
        }   
    }

    for(int i=0; i<num_vertices; i++){
        if(dists[i] != INT_MAX){
            printf("Vertex %d: %d\n", i, dists[i]);
        }
    }
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
5, 10
0, 1, 10
0, 2, 5
1, 2, 2
1, 3, 1
2, 1, 3
2, 3, 9
2, 4, 2
3, 4, 4
4, 0, 7
4, 3, 6
*/
/* Answer
Shortest distances from vertex 0:
Vertex 0: 0
Vertex 1: 8
Vertex 2: 5
Vertex 3: 9
Vertex 4: 7
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

    Dijkstra(num_vertices);

    return 0;

}