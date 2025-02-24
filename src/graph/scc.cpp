#include "../template.cpp"

vivi get_scc(vivi &adj) // O(v+e)
{
    ll time = 0, n = adj.size();
    vivi scc(0);
    vb done(n, 0);
    vi stk(0), low(n, 0), discover_time(n, 0);

    function<void(ll)> dfs = [&](ll u)
    {
        ll current;
        stk.push_back(u), discover_time[u] = low[u] = ++time;
        for (auto v : adj[u])
        {
            if (!discover_time[v])
                dfs(v), current = low[v];
            else if (!done[v])
                current = discover_time[v];
            else
                current = low[u];
            low[u] = min(low[u], current);
        }
        if (low[u] == discover_time[u])
        {
            scc.push_back(vi(0));
            while (!done[u])
            {
                scc.back().push_back(stk.back());
                done[stk.back()] = 1;
                stk.pop_back();
            }
        }
    };

    rep(0, n) if (!done[i]) dfs(i);

    return scc;
}

vivi compress_graph(vivi &adj, vivi &scc) // O(v+e)
{
    ll n = adj.size(), m = scc.size();
    vi scc_map(n);
    vivi graph(m);
    rep(0, m) repi(j, 0, scc[i].size()) scc_map[scc[i][j]] = i;

    rep(0, m) repi(j, 0, scc[i].size()) for (auto v : adj[scc[i][j]]) if (scc_map[v] != i) graph[i].push_back(scc_map[v]);
    rep(0, m) sort(graph[i]), unique(graph[i]);
    return graph;
}