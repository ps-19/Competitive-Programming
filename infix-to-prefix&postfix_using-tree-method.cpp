#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//  order_of_key (k) : Number of items strictly smaller than k .
//  find_by_order(k) : K-th element in a set (counting from zero).

const ll mod     = 1000*1000*1000+7;
const ll inf     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll mod2    = 998244353;
const ll N       = 1000 * 1000 + 10;
const ld pi      = 3.141592653589793;
ll power(ll x,ll y,ll p = LLONG_MAX ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll ncr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}

struct Node{
	char val;
	Node *l,*r;
	Node(){
		l=NULL;
		r=NULL;
	}
	Node(char x){
		this->val=x;
		l=NULL;
		r=NULL;
	}
};
void f(Node *u){
	if(u==NULL) return;
	cout<<u->val;
	f(u->l);
	f(u->r);
	return;
}
void f2(Node *u){
	if(u==NULL) return;
	f2(u->l);
	f2(u->r);
	cout<<u->val;
	return;
}
void solve(){
	string s="(a^b^(c/d/e-f)^(x*y-m*n))";
	// s+=")";
	// s="("+s;
    stack<char> c;
    stack<Node*> p;
    map<char,ll> mp;
    mp['+']=1;
    mp['-']=1;
    mp['*']=2;
    mp['/']=2;
    mp['^']=3;
    mp[')']=0;
    for(ll i=0;i<s.length();i++){
    	if(s[i]=='(') c.push(s[i]);
    	else if(isalpha(s[i])){
    		Node* u=new Node(s[i]);
    		p.push(u);
    	}
    	else if(mp[s[i]]>0){
    		while(c.size()>0 && c.top()!='(' && ((s[i]=='^' && mp[c.top()] > mp[s[i]]) || (s[i]!='^' && mp[c.top()] >= mp[s[i]]))){
    			Node *u=new Node(c.top());
    			c.pop();
    			Node *t1=p.top();
    			p.pop();
    			Node *t2=p.top();
    			p.pop();
    			u->l=t2;
    			u->r=t1;
    			p.push(u);
    		}
    		c.push(s[i]);
    	}
    	else if(s[i]==')'){
    		while(c.size()>0 && c.top()!='('){
    			Node *u=new Node(c.top());
    			c.pop();
    			Node *t1=p.top();
    			p.pop();
    			Node *t2=p.top();
    			p.pop();
    			u->l=t2;
    			u->r=t1;
    			p.push(u);
    		}
    		c.pop();
    	}
    }
    f(p.top());
    cout<<endl;
    f2(p.top());
    return;
}

signed main(){
    fastio();
    // test
    solve();
    return 0;
}
