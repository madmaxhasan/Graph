#include<bits/stdc++.h>
#define MAX 500

using namespace std;

vector < int > Graph[MAX];
vector < bool > visited(MAX, false);

void DFS(int u)
{
    visited[u] = true;
    cout << u << " ";
    for(int i=0; i<Graph[u].size(); i++)
    {
        if(visited[Graph[u][i]] == false)DFS(Graph[u][i]);
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    DFS(3);
    return 0;
}
