// Problem: LCM Challenge
// Contest: HackerRank - CODEX 15.0
// URL: https://www.hackerrank.com/contests/codex-15-0/challenges/lcm-challenge/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Author: Priyansh Singh

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
const ll N       = 2000 * 1000 + 1000;
const ld pi      = 3.141592653589793;
ll power(ll x,ll y,ll p = LLONG_MAX ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll ncr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}

ll tree[N];

void build(ll node,ll start,ll end,vector<ll> &a){
   if(start==end){
     tree[node]=a[start];
   }
   else{
      ll mid=(start+end)/2;
      build(2*node,start,mid,a);
      build(2*node+1,mid+1,end,a);
      tree[node]=__gcd(tree[2*node],tree[2*node+1]);
   }
}

ll query(ll node,vector<ll> &a,ll start,ll end,ll l,ll r){
   if(start>r || l>end){
     return 1LL;
   }
   else if(start>=l && r>=end){ // imp condition
     return tree[node];
   }
   ll mid=(start+end)/2;
   return (ll)__gcd(query(2*node,a,start,mid,l,r), query(2*node+1,a,mid+1,end,l,r));
}
ll in(ll x){
	return power(x,mod-2,mod)%mod;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    vector<ll> prod(n+1);
    prod[0]=1;
    loop(i,1,n+1){
    	cin>>a[i];
    	prod[i]=(prod[i-1]%mod*a[i]%mod)%mod;
    	prod[i]%=mod;
    }
    // cout<<a.size()<<endl;
    build(1,1,n,a); // node start end array
    ll q;
    cin>>q;
    while(q--){
    	ll u,v;
    	cin>>u>>v;
    	// ll Lcm=((prod[v]%mod*in(prod[u-1])%mod)%mod* in()%mod)%mod;
    	ll Lcm=prod[v];
    	Lcm=(Lcm%mod*in(prod[u-1])%mod)%mod;
    	Lcm=(Lcm%mod*in(query(1,a,1,n,u,v))%mod)%mod;
    	Lcm%=mod;
    	cout<<Lcm<<endl;
    }
}
signed main(){
    fastio();
    // cout<<fixed<<setprecision(10);
    test
    solve();
    return 0;
}
