#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1 << 30; // inf > 10^9

vector<int> calc_lis(const vector<int> &x)
{
    const int n = (int)x.size();
    vector<int> dp(n, inf), ret(n);
    for (int i = 0; i < n; ++i)
    {
        auto itr = lower_bound(dp.begin(), dp.end(), x[i]);
        *itr = x[i];
        ret[i] = itr - dp.begin() + 1;
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a)
    {
        cin >> e;
    }
    auto l_lis = calc_lis(a);
    reverse(a.begin(), a.end());
    for (auto &e : a)
    {
        e = inf - e;
    }
    auto r_lis = calc_lis(a);
    reverse(a.begin(), a.end());
    for (auto &e : a)
    {
        e = inf - e;
    }
    reverse(r_lis.begin(), r_lis.end());

    const int L = *max_element(l_lis.begin(), l_lis.end());
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (l_lis[i] + r_lis[i] - 1 == L)
        {
            ans.push_back(i);
        }
    }
    const int m = (int)ans.size();
    cout << m << '\n';
    for (int i = 0; i < m; ++i)
    {
        cout << ans[i] + 1 << (i == m - 1 ? '\n' : ' ');
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
