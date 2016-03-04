#include <stdio.h>
#define V 9
 
void kruskal(int costM[V][V]);
// An edge will have the properties v1, v2 which will be the verticesof the edge and Evalue which will be the length of the edge
struct Edge
{
    int v1;
    int v2;
    int Edgeval;
};
// A disjoined set will have an element denoted by parentVertex. 
struct Disjoint
{
    int parentVertex;
    int disjointID;
};
 
int main()
{
    int graph[V][V] = {  
	{0,  22, 9, 12,  0,  0,  0,  0,  0},
    {22, 0, 35,  0,  0, 36,  0, 34,  0},
    {9,  35, 0,  4,  65, 42, 0,  0,  0},
    {12, 0,  4,  0,  33, 0,  0,  0, 30},
    {0,  0, 65, 33,  0,  18, 23, 0,  0},
    {0,  36, 42, 0,  18, 0,  39, 24, 0},
    {0,  0,  0,  0,  23, 39, 0,  25, 21},
    {0,  34, 0,  0,  0,  24, 25, 0,  19},
    {0,  0,  0,  30, 0,  0,  21, 19, 0} };
    kruskal(graph);
    return 0;
}
// Kruskal function calculates the MST and prints out the edge set, node set and weight of the MST
void kruskal(int cost[V][V])
{
     int parent[V];
    // Count number of edges
    int edgecount = 0;
    for(int i=0;i<V;i++)
    {
        for(int j=i;j<V;j++)
        {
            if(cost[i][j]!=0)
                edgecount++;
        }
    }
    struct Edge edgeset[edgecount];
    // defining the edges
    int k = 0;
    for(int i=0;i<V;i++)
    {
        for(int j=i;j<V;j++)
        {
            if(cost[i][j]!=0)
            {
                edgeset[k].v1 = i;
                edgeset[k].v2 = j;
                edgeset[k].Edgeval = cost[i][j];
                k++;
            }
        }
    }
    // defining disjoint sets for each of the vertices
    struct Disjoint DisjointSet[V];
    for(k=0;k<V;k++)
    {
        DisjointSet[k].parentVertex = k;
        DisjointSet[k].disjointID = k;
    }
    // Go through the edges in ascending order of their weights
    int min,MST=0;
    int ind;
    int AA, BB, CC;
    printf("Edge Set = { ");
    // to find an MST for V vertices, V-1 iterations must be performed
    for(int i=0;i<V-1;i++)
    {
        min = 999;
        // Finding the least weight edges
        for(int j=0;j<edgecount;j++)
        {
            if(edgeset[j].Edgeval<min)
            {
                min = edgeset[j].Edgeval;
                ind = j;
            }
        }
        if( DisjointSet[edgeset[ind].v1].disjointID != DisjointSet[edgeset[ind].v2].disjointID )
        {
            for(k=0;k<V;k++)
            {
                if(k==edgeset[ind].v2)
                    continue;
                AA = DisjointSet[k].disjointID;
                BB = DisjointSet[edgeset[ind].v1].disjointID;
                CC = DisjointSet[edgeset[ind].v2].disjointID;
                if(DisjointSet[k].disjointID==DisjointSet[edgeset[ind].v2].disjointID)
                   DisjointSet[k].disjointID = DisjointSet[edgeset[ind].v1].disjointID;
            }
            DisjointSet[edgeset[ind].v2].disjointID = DisjointSet[edgeset[ind].v1].disjointID;
            // Display the MST edges
            printf("%c-%c, ",(edgeset[ind].v1)+65,(edgeset[ind].v2)+65);
            // Add the cost of the edges of the MST
            MST = MST + cost[edgeset[ind].v1][edgeset[ind].v2];
        }
        else
            i--;
        edgeset[ind].Edgeval = 1000;
    }
    
    printf("\b\b }");
    printf("\n\nMinimum spanning tree: Total weights on MST edges = %d\n\n",MST);
	
	// Print the nodes set
	printf("Node set = {");
    for(int i=0;i<V;i++)
    {
        if(DisjointSet[i].disjointID==DisjointSet[0].disjointID)
            printf("%c, ",i+65);
    }
    printf("\b\b }");
}
