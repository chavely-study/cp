#include "../template.cpp"

deque<ll> q;
ll seen[not_so_big_number];
ll depth[not_so_big_number];
ll father[not_so_big_number];
vivi adj;

void bfs(ll u)
{
    depth[u] = 0;
    q.clear();
    q.push_back(u);
    while (!q.empty())
    {
        seen[u] = 1;
        u = q.front(), q.pop_front();
        for (auto v : adj[u])
        {
            if (seen[v])
                continue;
            q.push_back(v);
            father[v] = u;
            depth[v] = depth[u] + 1;
        }
    }
}