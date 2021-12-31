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


void heap_sort(ll a[],ll n){
    
    //heap creation
    
    ll b[n],j=0;
    for(ll i=0;i<n;i++){
        b[j]=a[i];
        ll k=j;
        while(k>0){
            ll fn=b[(k-1)/2];
            if(fn<b[k]){
                swap(b[k],b[(k-1)/2]);
            }
            k=(k-1)/2;
        }
        j++;
    }
    for(ll i=0;i<n;i++) a[i]=b[i];
    // destroy heap
    ll c[n],ii=0;
    j=n-1;
    while(j>=0){
        c[ii]=a[0];
        ii++;
        swap(a[0],a[j]);
        ll i=0;
        ll child1=2*i+1;
        ll child2=2*i+2;
        while(1){
            bool ok=0;
            if(child2<j){
                if(a[child2]>a[child1]){
                    ok=1;
                    swap(a[i],a[child2]);
                    i*=2;
                    i+=2;
                }
                else{
                    ok=1;
                    swap(a[i],a[child1]);
                    i*=2;
                    i++;
                }
            }
            if(!ok && child1<j && a[child1]>a[i]){
                ok=1;
                swap(a[i],a[child1]);
                i*=2;
                i++;
            }
            if(!ok) break;
            child1=2*i+1;
            child2=2*i+2;
        }
        j--;
    }
    for(ll i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    loop(i,0,n) cin>>a[i];
    heap_sort(a,n);
}
signed main(){
    fastio();
    test
    solve();
    return 0;
}
