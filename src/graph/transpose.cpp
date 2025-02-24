#include "../template.cpp"

vivi get_transposed(vivi &adj) // O(v+e)
{
    ll n = adj.size();
    vivi transposed(n);
    rep(0, n) for (auto v : adj[i]) transposed[v].push_back(i);
    return transposed;
}