#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long int ll;
const ll INF = 1ll<<60;
const ll MOD = 1e9 + 7;
//************************************************************************************************************
//a^b modulo m (for normal power raise m=MOD)
ll pow_mod(ll a, ll b, ll m)
{
    ll res=1;
    a=a%m;
    if(a==0) return 0;

    while (b>0)
    {
        if (b&1) res=(res*a)%m;
        b=b>>1;
        a=(a*a)%m;
    }
    return res;
}
//************************************************************************************************************
//binary_search
ll BINARY_SEARCH(ll arr[],ll n,ll a)
{
    ll k=0;
    for (ll b=n/2;b>=1;b/=2)
        while(k+b<n && array[k+b]<=a) k+=b;
    //Returns the "Previous" Index if the element is not found
    return k;
}
//************************************************************************************************************
void SUBSETS(ll k,ll n)
{
    static vector<ll>subsets_array;
    if(k==n)
    {
        //Process Subset
    }
    else
    {
        SUBSETS(k+1,n);
        subsets_array.push_back(k);
        SUBSETS(k+1,n);
        subsets_array.pop_back();
    }
}
//************************************************************************************************************
//Euler toitent Function
ll phi(ll x)
{
    ll res=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            while(x%i==0) x/=i;
            res-=res/i;
        }
    }
    if(x>1) res-=res/x;
    return res;
}
//************************************************************************************************************
//modular multiplicative inverse
ll mod_inv(ll a,ll m)
{
    return pow_mod(a,phi(m)-1,m);
}
