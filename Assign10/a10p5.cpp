#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
bool visited[100001];
vector<int> result;
bool possible = true;
int color[100001];
void dfs(int node)
{
    color[node] = 1;
    for(int child : adj[node])
        if(color[child] == 0)
            dfs(child);
        else if(color[child] == 1)
            possible = false;
    color[node] = 2;
    result.push_back(node);
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
    }
    for(int i = 1; i <= n; i++)
        if(color[i] == 0)
            dfs(i);
    if(!possible)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        reverse(result.begin(), result.end());
        for(int node : result)
            cout << node << " ";
        cout << endl;
    }
    return 0;
}