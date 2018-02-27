#include<bits/stdc++.h>
#define MAX 5000
#define pb push_back

using namespace std;

typedef vector <int> vi;

int node, edge;
vector <vi> Graph;
bool visited[MAX];

void clr()
{
    Graph.assign(node, vi());
    memset(visited, false, sizeof visited);
}

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for(int i=0; i<Graph[u].size(); i++)
    {
        int v = Graph[u][i];
        if(!visited[v])dfs(v);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> node >> edge;
    clr();
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin >> x >> y;
        Graph[x].pb(y);
        Graph[y].pb(x); // Undirected Graph
    }
    int numCC = 0;
    for(int i=0; i<node; i++)
    {
        if(!visited[i])printf("CC %d: ",++numCC), dfs(i), puts("");
    }
    return 0;
}
