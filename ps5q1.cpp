#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> b(n);
    vector<int> p(n);
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i <= x; i++)
    {
        if (b[0] <= i)
            dp[0][i] = p[0];
        else
            dp[0][i] = 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int i = 0; i <= x; i++)
        {
            int pick = 0;
            if (b[ind] <= i)
            {
                pick = p[ind] + dp[ind - 1][i - b[ind]];
            }
            int notpick = dp[ind - 1][i];
            dp[ind][i] = max(pick, notpick);
        }
    }
    cout << dp[n - 1][x];
}