#include<bits/stdc++.h>
using namespace std ;
typedef long long int ll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string s; cin>>s;
        ll dp[n]={0},p[n]={0},arr[n];
        p[0]=arr[0];
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='1') arr[i]=1;
            else arr[i]=0;
        }
        for(ll i=1;i<n;i++)
        {
            p[i]=p[i-1]+arr[i];
        }
        vector<ll>v;
        for(ll j=n-1;j>=0;j--)
        {
            if(arr[j]==1)
            {   //converted everything to zero bryond this index.
                if(j+k<=n-1)
                    dp[j]=min(1+p[n-1]-p[j],dp[j+k]+p[j+k-1]-p[j]);
                else
                    dp[j]=1+p[n-1]-p[j];
            }
            else
            {
                if(j+k<=n-1)
                    dp[j]=min(p[n-1]-p[j],1+dp[j+k]+p[j+k-1]-p[j]);
                else
                    dp[j]=p[n-1]-p[j];
            }
            v.push_back(dp[j]);
        }
        reverse(v.begin(),v.end());
        for(auto c:v)
            cout<<c<<" ";
        cout<<endl;
        ll mi=INF;
        for(ll i=0;i<n;i++)
        {
            dp[i]+=p[i]-p[0];
            if(dp[i]<mi)
                mi=dp[i];
        }
        cout<<mi<<endl;
    }
    return 0;
}
