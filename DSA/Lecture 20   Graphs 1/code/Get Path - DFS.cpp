/*
Code : Get Path - DFS

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1:
3 0 1
Sample Input 2:
6 3
5 3
0 1
3 4
0 3
Sample Output 2:
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int v, int sv, int ev, vector<int> &path)
{
    if (sv == ev)
    {
        path.push_back(sv);
        return;
    }

    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && graph[sv][i])
        {
            dfs(graph, visited, v, i, ev, path);
            if (!path.empty())
            {
                path.push_back(sv);
                return;
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    vector<bool> visited(V);
    int s, e;
    cin >> s >> e;

    vector<int> path;
    dfs(graph, visited, V, s, e, path);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";

    return 0;
}
