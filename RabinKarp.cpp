#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll  long long
#define int long long
#define ld  long double
#define endl "\n"
#define pb  push_back
#define fill(a,val) memset(a,val,sizeof(a))
#define ff  first
#define ss  second
#define test  ll t; cin>>t; while(t--)
#define loop(i,a,b)  for(ll i=a;i<b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<ll,ll>
#define all(v) v.begin(),v.end()
const ll mod     = 1000*1000*1000+7;
const ll inf     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll mod2    = 998244353;
const ll N       = 1000 * 1000 + 10;
const ld pi      = 3.141592653589793;
ll power(ll x,ll y,ll p = LLONG_MAX ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll ncr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}

void pre(map<char,ll> &mp){
    for(char i='a';i<='z';i++){
        mp[i]=i-'a'+1;
    }
}
ll rabin_karp(string s,string p){
    map<char,ll> mp;
    pre(mp);
    ll n=s.length(), m=p.length();
    ll hashcode=0,cnt=0;
    for(ll i=0;i<m;i++){
        hashcode=(hashcode%mod + (mp[p[i]]%mod*power(26,m-i,mod)%mod)%mod)%mod;
        hashcode%=mod;
    }
    ll value=0;
    for(ll i=0;i<m-1;i++){
        value=value%mod+(mp[s[i]]*power(26,m-i,mod)%mod)%mod;
        value%=mod;
    }
    for(ll i=m-1;i<n;i++){
        value=(value%mod+mp[s[i]]*26)%mod;
        value%=mod;
        if(value==hashcode){
            cnt++;
            cout<<"occured here between: "<<i-m+1<<" "<<i<<endl;
        }
        value=(value-(mp[s[i-m+1]]*power(26,m,mod)%mod)%mod+mod)%mod;
        value%=mod;
        value=(value%mod*26)%mod;
        value%=mod;
    }
    return cnt;
}
void solve(){
    string s,p;
    cin>>s>>p;
    cout<<rabin_karp(s,p)<<endl;
}
signed main(){
    fastio();
    // test
    solve();
    return 0;
}
