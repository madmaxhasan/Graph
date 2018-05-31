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

vector <vi> AdjList;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	REP(i, AdjList[u].size())
	{
		int v = AdjList[u][i];
		if(!dfs_num[v])
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u])
	{
		printf("SCC %d:", ++numSCC);
		while(true)
		{
    		int v = S.back();
    		S.pop_back();
    		visited[v] = 0;
    		printf(" %d", v);
			if(u == v)break;
    	}
		printf("\n");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	FileIn("in");
	FileOut("out");
#endif //ONLINE_JUDGE

	int V, E, x, y;
	scanf("%d %d",&V,&E);
	AdjList.assign(V, vi());
	REP(i, E)
	{
		scanf("%d %d", &x, &y);
		--x, --y;
		AdjList[x].push_back(y);
	}
	dfsNumberCounter = numSCC = 0;
	dfs_num.assign(V, 0);
	dfs_low.assign(V, 0);
	visited.assign(V, 0);
	REP(i, V)
	{
		if(dfs_num[i] == 0)
		{
			tarjanSCC(i);
		}
	}
	return 0;
}