#include <bits/stdc++.h>
using namespace std;

const long long N = 1e3 + 5, inf = 1e18, mod = 1e9 + 7;

long long H, W;
vector<vector<long long>> dp(N, vector<long long>(N, -1));
char mat[N][N];

bool inside(long long x, long long y)
{
    return x >= 1 && y >= 1 && x <= H && y <= W;
}

long long go(long long x, long long y)
{
    if (!inside(x, y))
        return 0;
    if (mat[x][y] == '#')
        return 0;
    if (x == H && y == W)
        return 1;
    long long &ans = dp[x][y];
    if (~ans)
        return ans;
    ans = 0;
    ans = (ans + go(x + 1, y)) % mod;
    ans = (ans + go(x, y + 1)) % mod;
    return ans;
}
int main()
{
    cin >> H >> W;
    for (long long i = 1; i <= H; i++)
        for (long long j = 1; j <= W; j++)
            cin >> mat[i][j];
    cout << go(1, 1);
}