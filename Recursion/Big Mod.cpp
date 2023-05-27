#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll bigmod_iterative(ll x, ll y,ll modd)
{
    ll res = 1;
    while(y>0)
    {
        if(y&1)
            res = (res*x)%modd;
        y=y>>1;
        x= (x*x)%modd;
    }
    return res;
}
int bigmod_recursive(long long base,long long power,long long mod,long long ans){
    if(power==0) return 1;
    if(power==1)return base;
    if(power%2 == 0){
        // even
        ans = (ans * bigmod_recursive(base,power/2,mod,ans)) % mod;
        ans = (ans * ans)%mod;
        return ans;
    }
    else{
        // odd
        ans = (base * ans * bigmod_recursive(base,power-1,mod,ans)) % mod;
        return ans;
    }
}
int main(){
    ll base,power;
    cin>>base>>power;
    ll mod = 1000000007;
    ll Bmod = bigmod_recursive(base,power,mod,1);
    cout<<Bmod;
}
