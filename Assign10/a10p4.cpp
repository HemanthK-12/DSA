#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool visited[1001];
int prevNode[1001];
void bfs(int src)
{
    queue<int> q;
    visited[src] = true;
    q.push(src);
    prevNode[src] = -1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int child : adj[node])
            if(!visited[child])
            {
                q.push(child);
                visited[child] = true;
                prevNode[child] = node;
            }
    }
}
vector<int> shortest_path(int src, int dest)
{
    vector<int> path;
    for(int at = dest; at != -1; at = prevNode[at])
        path.push_back(at);
    reverse(path.begin(), path.end());
    if(path[0] == src) return path;
    return {};
}
int main()
{
    int nodes, edges,source, destination;
    cin >> nodes >> edges >> source >> destination;
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(source);
    vector<int> path = shortest_path(source, destination);
    if(path.empty())
        cout << "No path found" << endl;
    else
    {
        for(int node : path)
            cout << node << " ";
        cout << endl;
    }
    return 0;
}