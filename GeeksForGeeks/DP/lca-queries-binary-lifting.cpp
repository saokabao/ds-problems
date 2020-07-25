/*
 *   https://www.youtube.com/watch?v=02zM-QoKoPg
 *
 *
 * */

#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef set<ll> si;
typedef map<string,ll> msi;


    #define INF 20000000
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define sz size()
    #define ln length()
    #define rep(i,n) for(ll i=0;i<n;i++)
    #define fu(i,a,n) for(ll i=a;i<=n;i++)
    #define fd(i,n,a) for(ll i=n;i>=a;i--)
    #define all(a)  a.begin(),a.end()
    #define pl(a) cout<<a
    #define nl cout<<endl
    #define present(container,element) container.find(element)!=container.end()
    #define cpresent(container,element) find(all(container),element)!=container.end()


 ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(ll u, ll p,ll logN, vvi &dp, vvi &adj, vi &lvl)
{
	lvl[u] = lvl[p] + 1;

	dp[u][0] = p;

	fu(i, 1, logN-1)
	{
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}

	for(auto it : adj[u])
	{
		if (it != p) dfs(it, u, logN, dp, adj, lvl);
	}
}

ll lca(ll  u, ll v,ll logN,  vvi &dp, vi &lvl)
{
	if (lvl[u] < lvl[v]) swap(u,v);

	ll diff = lvl[u] - lvl[v];


	fu(i,0,logN-1)
	{
		if (diff & 1<<i) u = dp[u][i];
	}

	if ( u == v)  return u;

	
	fd(i,logN-1, 0)
	{
		if (dp[u][i] != dp[v][i])
		{
			u  = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[v][0];
}

int main()
{
	pl("edges:: ");
	ll e;  cin>>e;
	ll n  = e+1;
	vector<vector<ll>> adj(n+1);
	pl("edges:");nl;
	rep(i,e)
	{
		ll a, b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	

	ll logN = ceil(log2(n));
	pl("logN: ");pl(logN);nl;

	vector< vector<ll>> dp(n+1, vector<ll> (logN, 0));
	vi lvl(n+1,0);

	dfs(3,0, logN, dp, adj, lvl); // assuming 0 is root. 

	pl("queries: ");nl;
	ll q; cin>>q;
	rep(i,q)
	{
		ll a,b; cin>>a>>b;
		pl("ancestor: ");
		pl(lca(a,b,logN, dp, lvl));
		nl;
	}

}

