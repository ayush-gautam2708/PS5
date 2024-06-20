#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num[5]={1,3,6,10,15};
        int n=5;
        int x;
        cin>>x;
        vector<vector<int> > dp(n,vector<int>(x+1,-1));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=x;i++)
        {
            if(i%num[0]==0)
            {
                dp[0][i]=i/num[0];
            }
            else dp[0][i]=1e8;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<x+1;target++)
            {
                int pick=1e8;
                if(num[ind]<=target) pick=1+dp[ind][target-num[ind]];
                int notpick=dp[ind-1][target];
                dp[ind][target]=min(pick,notpick); 
            }
        }
        int ans=dp[n-1][x]==1e8?-1:dp[n-1][x];
        cout<<ans<<endl;
        }
    
}