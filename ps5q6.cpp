#include <bits/stdc++.h>
using namespace std;
double f(vector<double> p,int ind,int n,int c,vector<vector<double> > &dp)
{
    if(ind==n)
    {
        if(c > n/2)
        {
            return 1.0;
        }
        return 0.0;
    }
    if(dp[ind][c]!=-1.0)
    {
        return dp[ind][c];
    }
    double head = p[ind] * f(p,ind+1,n,c+1,dp);
    double tail = (1.0-p[ind]) * f(p,ind+1,n,c,dp);
    return dp[ind][c]=head+tail;
}
int main()
{
    int n;
    cin>>n;
    vector<double> p(n);
    vector<vector<double> > dp(n,vector<double>(n+1,-1.0));
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    double ans=f(p,0,n,0,dp);
    cout<<fixed<<setprecision(9)<<ans;
}