#include "../template.cpp"

deque<ll> get_topological_sort(vivi &adj) // O(v+e)
{
    deque<ll> stk;
    vb done(adj.size());
    vi finished(adj.size());

    function<void(ll)> dfs = [&](ll u)
    {
        done[u] = 1;
        for (auto v : adj[u])
            if (!done[v])
                dfs(v);
        stk.push_front(u);
    };

    rep(0, adj.size()) if (!done[i]) dfs(i);
    return stk;
}