/*
Code : Is Connected ?

Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/
#include <iostream>
#include<queue>
using namespace std;

void BFS(int**graph ,int v , int sv,bool* visited)
{
  
    queue<int> pn;
    pn.push(sv);
    visited[sv]=true;

    while(!pn.empty())
    {
        int t= pn.front();
        
        pn.pop();
       

        for(int i=0 ; i<v ;i++)
        {
            if(graph[t][i]==1 && !visited[i])
            { 
                pn.push(i);
                visited[i]=true;
            }
        }
    }   

   

}
int main() {
    int V, E;
    cin >> V >> E;

    
     int** graph = new int * [V];
    for( int i=0 ;i<V ;i++)
    {
        graph[i]= new int[V];
        for( int j=0 ;j<V ;j++)
            graph[i][j]=0;

    }
    for (int i=0 ;i<E ;i++)
    {
		int x ,y ;
        cin>>x>>y ;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    bool * visited = new bool[V];
    for ( int i=0 ;i<V ;i++)
        visited[i]=false;
 
    
    BFS(graph ,V, 0 , visited);
    
    
    int i=0;
   for(i =0 ; i<V ;i++)
   {    if( !visited[i])
   {cout<<"false";
            break;}
   }
    if(i==V)
        cout<< "true";
    
for(int i=0 ;i<V ;i++)
{
    delete [] graph[i];
}
    delete [] graph;
    
    delete [] visited;
    

  

  return 0;
}