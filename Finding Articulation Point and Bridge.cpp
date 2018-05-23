/* ====================================================== */
#include <bits/stdc++.h>
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define Fill(arr, val) memset(arr, val, sizeof arr)
#define All(arr) arr.begin(), arr.end()
#define PI 3.1415926535897932385
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mkp make_pair
#define MAX 505
#define INF 500000000
#define debug cout << "DEBUG" << endl;
using namespace std;
typedef   pair <int, int>  ii;
typedef   pair <char, int> ci;
typedef   pair <int, char> ic;
typedef vector <ii>       vii;
typedef vector <ci>       vci;
typedef vector <ic>       vic;
typedef vector <int>       vi;
typedef vector <bool>      vb;
/* ====================================================== */
bool sortbyFrst(const ii &a, const ii &b){return (a.first > b.first);}
bool sortbyScnd(const ii &a, const ii &b){return (a.second < b.second);}
bool perfectDec(const ic &a, const ic &b){return ((a.first != b.first) ? a.first > b.first : a.second < b.second);}
int drX[] = {1, 1, 0, -1, -1, -1, 0, 1};
int drY[] = {0, 1, 1, 1, 0, -1, -1, -1};
/* ====================================================== */

vector <vi> Graph;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
int counterArray[100];

void articulationPointAndBridge(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int i = 0; i < Graph[u].size(); ++i)
	{
		int v = Graph[u][i];
		if(!dfs_num[v])
		{
			dfs_parent[v] = u;
			if(u == dfsRoot)
				rootChildren++;
			articulationPointAndBridge(v);
			if(dfs_low[v] >= dfs_num[u])
			{
				articulation_vertex[u] = true;
				counterArray[u]++;
			}
			if(dfs_low[v] > dfs_num[u])
				printf(" Edge (%d, %d) is a bridge\n", u, v);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	FileIn("in");
	FileOut("out");
#endif //ONLINE_JUDGE

	int V, E, total_neighbors, x, y;
	scanf("%d %d",&V,&E);
	Graph.assign(V, vi());
	Fill(counterArray, 0);
	REP(i, E)
	{
		scanf("%d %d", &x, &y);
		Graph[x].pb(y);
		Graph[y].pb(x);
	}
	dfsNumberCounter = 0;
	dfs_num.assign(V, 0);
	dfs_low.assign(V, 0);
	dfs_parent.assign(V, 0);
	articulation_vertex.assign(V, 0);
	printf("Bridges:\n");
	for(int i=0; i<V; i++)
	{
		if(!dfs_num[i])
		{
			dfsRoot = i;
			rootChildren = 0;
			articulationPointAndBridge(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
	}
	printf("Articulation Points:\n");
	for(int i=0; i<V; i++)
		if(articulation_vertex[i])
			printf(" Vertex %d\n", i);
	REP(i, V)cout << counterArray[i] << " ";
	printf("\n");
	return 0;
}
