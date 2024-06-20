#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<ll> prefixSums(n);
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = nums[i];
        prefixSums[i] = nums[i];
        if (i > 0)
            prefixSums[i] += prefixSums[i - 1];
    }
    for (int size = 2; size <= n; size++)
    {
        for (int i = size - 1; i < n; i++)
        {
            ll total = i < size ? prefixSums[i] : prefixSums[i] - prefixSums[i - size];
            ll selectLast = total - dp[i - size + 1][i - 1];
            ll selectFist = total - dp[i - size + 2][i];
            dp[i - size + 1][i] = max(selectFist, selectLast);
        }
    }
    cout << dp[0][n - 1];

    return 0;
}