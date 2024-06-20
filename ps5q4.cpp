#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    int total = (n * (1 + n)) / 2;
    if (total % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    ll MOD = 1e9 + 7;
    int half = total / 2;
    vector<ll> dp(half + 1);
    dp[0] = 1;
    for (int coin = 1; coin <= n; coin++)
    {
        for (int i = half; i >= coin; i--)
        {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    ll modInverseOfTwo = 500000004;
    cout << (dp[half] * modInverseOfTwo) % MOD;

    return 0;
}