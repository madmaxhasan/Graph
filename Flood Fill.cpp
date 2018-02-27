#include<bits/stdc++.h>

using namespace std;

vector <string> grid;

int N, M;
int X[] = {  1,  1,  0, -1, -1, -1,  0,  1  };  // S. SE, E, NE, N, NW, W, SW
int Y[] = {  0,  1,  1,  1,  0, -1, -1, -1  };  // S. SE, E, NE, N, NW, W, SW

void printGrid()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout << grid[i][j];
        }
        puts("");
    }
    puts("");
}

bool isFalse(int x, int y)
{
    return (x < 0 || x >= N || y < 0 || y >= M);
}

int Flood_fill(int x, int y, char c1, char c2)
{
    if(isFalse(x, y) || grid[x][y] != c1)return 0;
    grid[x][y] = c2;
    int ans = 1;
    for(int i=0; i<8; i++)
    {
        int moveX = x + X[i], moveY = y + Y[i];
        ans += Flood_fill(moveX, moveY, c1, c2);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int line;
    cin >> line >> ws;
    grid.clear();
    for(int i=0; i<line; i++)
    {
        string str;
        getline(cin, str);
        grid.push_back(str);
    }
    N = grid.size(), M = grid[0].size();
    printf("Input Grid\n\n");
    printGrid();
    Flood_fill(2, 1, 'W', '.');
    printf("After FloodFill\n\n");
    printGrid();
    return 0;
}

/*

    Input

    9
    LLLLLLLLL
    LLWWLLWLL
    LWWLLLLLL
    LWWWLWWLL
    LLLWWWLLL
    LLLLLLLLL
    LLLWWLLWL
    LLWLWLLLL
    LLLLLLLLL

*/
