#include "../template.cpp"

vi get_connected_components(vivi &adj) // O(v+e)
{
    ll n = adj.size(), current = 0;
    vi cc(n, -1);
    vb seen(n, 0);

    function<void(ll)> dfs = [&](ll u)
    {
        seen[u] = 1, cc[u] = current;
        for (auto v : adj[u])
            if (!seen[v])
                dfs(v);
    };

    rep(0, n) if (!seen[i]) dfs(i), current++;
    return cc;
}