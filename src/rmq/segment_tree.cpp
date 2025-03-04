#include "../template.cpp"

ll _tree[tow_power_1e6];

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        _tree[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        _tree[v] = _tree[v * 2] + _tree[v * 2 + 1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return _tree[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        _tree[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        _tree[v] = _tree[v * 2] + _tree[v * 2 + 1];
    }
}

void use()
{
    ll a[16];
    rep(0, 16) a[i] = i + 1;
    build(a, 1, 0, 15);
    rep(0, 32) cout << _tree[i] << " ";
    NEW_LINE;
    print(sum(1, 0, 15, 8, 10));
    update(1, 0, 15, 8, 10);
    rep(0, 32) cout << _tree[i] << " ";
    NEW_LINE;
    print(sum(1, 0, 15, 8, 10));
}
