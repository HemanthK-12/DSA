#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2500+5;
const long long INF = 1e18;
vector<pair<int, int>> adj[MAXN];
long long dist[MAXN];
int parent[MAXN];
void bellman_ford(int src, int n)
{
    fill(dist, dist + MAXN, INF);
    dist[src] = 0;
    int x;
    for(int i = 0; i < n; i++)
    {
        x = -1;
        for(int j = 1; j <= n; j++)
            for(auto& edge : adj[j])
            {
                int next_node = edge.first;
                long long cost = edge.second;
                if(dist[j] + cost < dist[next_node])
                {
                    dist[next_node] = dist[j] + cost;
                    parent[next_node] = j;
                    x = next_node;
                }
            }
    }
    if(x == -1)
        cout << "NO" << endl;
    else
    {
        for(int i = 1; i <= n; i++)
            x = parent[x];
        vector<int> cycle;
        for(int v = x;; v = parent[v])
        {
            cycle.push_back(v);
            if(v == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for(int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    bellman_ford(1, n);
    return 0;
}