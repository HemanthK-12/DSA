#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int depth[10001];
int sum[10001];
void dfs(int node, int d, int parent) 
{
    depth[node] = d;
    sum[node] = d;
    for(auto child: adj[node])
        if(child != parent)
        {
            dfs(child, d + 1, node);
            sum[node] += sum[child];
        }
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
    dfs(1, 0, -1);
    int total=0;
    for(int i = 1; i <= vertices; i++)
        total+=sum[i];
    cout<<total/2<<endl;
    return 0;
}