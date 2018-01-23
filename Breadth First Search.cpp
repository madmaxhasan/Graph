#include<bits/stdc++.h>
#define MAX 6000

using namespace std;

vector <int> G[MAX];
vector <int> visited(MAX, false);
queue <int> Q;

void BFS(int s)
{
    Q.push(s);
    visited[s] = true;
    while(!Q.empty())
    {
        int u = Q.front();
        cout << u << " ";
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int startNode;
    cin >> startNode;
    BFS(startNode);
    return 0;
}
