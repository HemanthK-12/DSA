#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
vector<int> adj[MAXN];
bool visited[MAXN];
void dfs(int node)
{
    visited[node] = true;
    for(int next_node : adj[node])
        if(!visited[next_node])
            dfs(next_node);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count = 0;
    for(int i = 1; i <= n; i++)
        if(!visited[i])
        {
            dfs(i);
            count++;
        }
    cout << count << endl;
    return 0;
}