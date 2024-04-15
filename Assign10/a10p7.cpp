#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
const long long INF = 1e18;
vector<pair<int, int>> adj[MAXN];
long long dist[MAXN];
void dijkstra(int src)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dist, dist + MAXN, INF);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty())
    {
        int node = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(d != dist[node]) continue;
        for(auto& edge : adj[node])
        {
            int next_node = edge.first;
            long long cost = edge.second;
            if(dist[node] + cost < dist[next_node])
            {
                dist[next_node] = dist[node] + cost;
                pq.push({dist[next_node], next_node});
            }
        }
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
    dijkstra(1);
    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}