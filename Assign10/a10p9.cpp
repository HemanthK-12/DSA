#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500+5;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
void dfs(int x, int y)
{
    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] && !visited[nx][ny])
            dfs(nx, ny);
    }
}
int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    int count = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] && !visited[i][j])
            {
                dfs(i, j);
                count++;
            }
    cout<< count << endl;
    return 0;
}