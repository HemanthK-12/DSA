#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
vector<int> tree[MAXN];
int subtree_size[MAXN];
int n;
void dfs(int node, int parent)
{
    subtree_size[node] = 1;
    for(auto& child : tree[node])
        if(child != parent)
        {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
}
int find_centroid(int node, int parent)
{
    for(auto& child : tree[node])
        if(child != parent && subtree_size[child] > n/2)
            return find_centroid(child, node);
    return node;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, -1);
    int centroid = find_centroid(1, -1);
    cout << centroid << endl;
    return 0;
}