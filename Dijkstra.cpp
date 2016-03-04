#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#define NODES 9 //Total no of Nodes
#define INFINITY 10000
 
 //Dijkstra function
void dijkstra(int dist[NODES][NODES], int source_node)
{ 
            bool S[NODES], V[NODES]; /* S : Nodes covered by Spanning tree. V : Nodes not covered */
            int distS[NODES], distV[NODES];
            int dist_min;           /* dist_min: minimum of all distV for the nodes is V*/
            int parent[NODES];     /*  parent node for a particular node */

 //Intializing the distances to all nodes as infinity
            int i = 0, j=0, k=0;
            for(i=0; i<NODES; i++)
            {
                        S[i] = false;
                        V[i] = true;
                        distV[i] = INFINITY;
                        distS[i] = INFINITY;
            }
 //Setting the Starting Node to 0
            S[0] = true;
            V[0] = false;
            distS[0] = 0;
            parent[0] = 0;
 //Find the adjacent node to the nodes in S with minimum distance
            int count = 0;
            int ind;
            bool empty;
 //Loop until all nodes in V become part of S
            do
            {
                empty = false;
                        /* first calculate distV for all adjacent nodes that is in V*/
                        for (j=0 ; j<NODES ; j++)
                        {
                                     /*need not take nodes not part of V (already in S)*/
                                    if(!V[j])
                                    continue;
                                    /*calculate dist_min for particular j from all nodes in S*/
                                    dist_min = INFINITY;
                                    for (i=0 ; i<NODES ; i++)
                                    {
                                                if(!S[i])             
                                                continue;               
                                                if( (dist[i][j]!=0) && (distS[i] + dist[i][j]<dist_min) )
								                {
								                    dist_min = distS[i] + dist[i][j];
								                    parent[j] = i;
								                }
								    }
                          distV[j] = dist_min;
                        }
                         /*find the minimum of all distV to find the nearest node           */        
                        dist_min = INFINITY;              
                        for (i=0 ; i<NODES ; i++)
                        {
                            if(!V[i])
               				continue;
                                    if(distV[i]<dist_min)
						            {
						             dist_min = distV[i];
						             ind = i;
						            }
                        }
                        V[ind] = false;
                        S[ind] = true;
                        distS[ind] = distV[ind];
                        for(k=0 ; k<NODES ; k++)
            			empty = empty || V[k];
            }while(empty);
// Print the path value & Path from the source node
    int path[NODES];
    std::cout<<"\n Node A : Path Value = 0 ";
    for(i=1 ; i<NODES ; i++)
    {       
        k = 0;
        path[0] = parent[i];
        while(path[k]!=0)
        {
            k++;
            path[k] = parent[path[k-1]];
        }
        std::cout<<"\n\n Destination Node "<<char(65+i)<<": Path Value ="<<distS[i]<<",   Path is "<<char(65);
		while(k>0)
        {
            k--;
            std::cout<<" -> "<<char(path[k]+65);
        }
        std::cout<<" -> "<<char(65+i);
    }
}
 
int main()
{
            int graph[NODES][NODES] = { 
			{0,  22, 9, 12,  0,  0,  0,  0,  0},
            {22, 0, 35,  0,  0, 36,  0, 34,  0},
            {9,  35, 0,  4,  65, 42, 0,  0,  0},
            {12, 0,  4,  0,  33, 0,  0,  0, 30},
            {0,  0, 65, 33,  0,  18, 23, 0,  0},
            {0,  36, 42, 0,  18, 0,  39, 24, 0},
            {0,  0,  0,  0,  23, 39, 0,  25, 21},
            {0,  34, 0,  0,  0,  24, 25, 0,  19},
            {0,  0,  0,  30, 0,  0,  21, 19, 0} };
 			//Call dijkstra function 
            dijkstra(graph, 0);
            std::cout<<"\n\n";
            return 0;
}
