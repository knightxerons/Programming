#include<bits/stdc++.h>
using namespace std ;
typedef long long int ll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;
const string ttt= "Test";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--)
    {
        string w1="Ashishgup";
        string w2="FastestFinger";
        ll n,m=0,k=0;
        cin>>n;
        if(n==1) cout<<w2<<endl;
        else if(n%2==1) cout<<w1<<endl;
        else
        {
            while(n%2==0) {n/=2;k++;}
            if(n==1)
            {
                if(k>1)
                cout<<w2<<endl;
                else cout<<w1<<endl;
                continue;
            }
            for(ll i=3;i*i<=n;i++)
            {
                if(i*i==n&&n%i==0) m++;
                else if(n%i==0) m+=2;
            }
            if(m==0) m++;
            if(m%2==0)
            {
                if(k>1) cout<<w2;
                else cout<<w1;
            }
            else
            {
                if(k>1) cout<<w1;
                else cout<<w2;
            }
            cout<<endl;
         }
    }
    return 0;
}
