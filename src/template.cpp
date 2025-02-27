#pragma region macros

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vivi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define SPEED                \
    ios::sync_with_stdio(0); \
    cin.tie(0)

#define print(x) cout << x << '\n'

#define all(v) v.begin(), v.end()

#define mod(x) x %= (int)(1e9 + 7)

#define reverse(x) reverse(all(x))

#define unique(x) unique(all(x))

#define sort(x) sort(all(x))

#define rep(a, b) for (int i = a; i < b; i++)
#define per(a, b) for (int i = b - 1; i >= a; i--)
#define repi(i, a, b) for (int i = a; i < b; i++)
#define peri(i, a, b) for (int i = b - 1; i >= a; i--)

#define NO cout << "NO\n"
#define YES cout << "YES\n"
#define NEW_LINE cout << '\n'

#define dx {+1, +0, -1, +0, +1, +1, -1, -1}
#define dy {+0, +1, +0, -1, +1, -1, +1, -1}

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define alphabet "abcdefghijklmnopqrstuvwxyz"
#define decimal_digits "0123456789"

#pragma endregion

// void solve() {}

// int main()
// {
//     SPEED;

//     int tests = 1;
//     cin >> tests;
//     while (tests--)
//     {
//         solve();
//     }

//     return 0;
// }