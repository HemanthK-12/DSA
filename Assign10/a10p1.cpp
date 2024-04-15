#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int maxD, maxNode;
void dfs(int node, int d, int parent)
{
    if(d > maxD) maxD = d, maxNode = node;
    for(auto child: adj[node])
        if(child != parent)
            dfs(child, d + 1, node);
}
int main()
{
    int edges;
    cin >> edges;
    int vertices = edges + 1;
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxD = -1;
    dfs(1, 0, -1);
    maxD = -1;
    dfs(maxNode, 0, -1);
    cout << maxD+1 << endl;
    return 0;
}