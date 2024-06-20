#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

ll f(ll ind, ll k, vector<ll> &v, ll n, vector<vector<ll>> &dp)
{
    if (ind >= n || k == 0)
    {
        return 0;
    }
    ll &x = dp[ind][k];
    if (x != (1))
    {
        return x;
    }
    ll ans = 0;
    ll sm = 0;
    ll mn = 1e18;
    for (ll i = ind; i <= min(n - 1, ind + k); i++)
    {
        mn = min(mn, v[i]);
        sm += v[i];
        ll len = (i - ind + 1);
        ans = min(ans, ((len * mn) - sm) + f(i + 1, k - (len - 1), v, n, dp));
    }

    x = ans;
    return x;
}

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll sm = 0;
    vector<ll> v(n);
    k = min(k, n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sm += v[i];
    }
    ll ans = sm;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1));
    ll get_ans = f(0, k, v, n, dp);
    ans += get_ans;
    cout << ans << endl;
}

int main()
{
    ll tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}