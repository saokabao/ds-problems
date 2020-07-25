/*
 *
 *  https://www.interviewbit.com/problems/max-edge-queries/
 *  Nodes 1 to N.

https://www.youtube.com/watch?v=02zM-QoKoPg
bidirectional edge with weight w1.

maximum weighted edge in a simple path from u to v.

Simple  path: path without any loops.

          1
        /   \
       2     3
     /  \    / \
    4   5   6   7


u,v, w
dp[u][i] = dp[dp[u][i-1]][i-1]
medge[u][i] = max(medge[u][i-1], medge[dp[u][i-1]][i-1]);


max_edge(int u, int v)
 lca(u,v) = x;

 diff1 = lvl[u] - lvl[x]
 diff2 = lvl[v] - lvl[x];

 diff1 && 1<<i
    ans = max(ans, maxedge[u][i])
    u = dp[u][i];

 diff2 && 1<<i
     ans = max(ans,  maxedge[v][i])

     v = dp[v][i]


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

void dfs(int u, int p, int e, vector<int> &lvl,
         vector<vector<int>>&dp,
         vector<vector<int>>&medge,
         vector<vector<pair<int,int>>> &adj)
{

    int n = lvl.size();
    n--;
    int LN = ceil(log2(n));

    lvl[u] = lvl[p] + 1;

    dp[u][0] = p;
    medge[u][0] = e;

    for(int i=1;i<LN;i++)
    {
        dp[u][i] = dp[dp[u][i-1]][i-1];
        medge[u][i] = max(medge[u][i-1], medge[dp[u][i-1]][i-1]);
    }

    for(auto it : adj[u])
    {
        if (it.first != p)
        {
            dfs(it.first, u, it.second,lvl,dp,medge,adj);
        }
    }
}


int max_edge(int u, int v, vector<int> &lvl, vector<vector<int>> &dp,
    vector<vector<int>> &medge)
{
    int n = lvl.size();
    n--;
    int LN = ceil(log2(n));

    if (lvl[u] < lvl[v]) swap(u,v);

    int ans  = INT_MIN;

    int diff =  lvl[u]  - lvl[v];



    for(int i=0;i<LN;i++)
    {
        if (diff & 1<<i)
        {
            ans = max(ans, medge[u][i]);
            u = dp[u][i];
        }
    }



    if (u == v) return ans;

    for(int i=LN-1;i>=0;i--)
    {
        if (dp[u][i] != dp[v][i])
        {
            ans = max(ans , medge[u][i]);
            ans = max(ans, medge[v][i]);
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    ans  = max(ans,medge[u][0]);
    ans = max(ans, medge[v][0]);
    return ans;
}


vector<int> solve(vector<vector<int> > &A, vector<vector<int> > &B)
{
    int e = A.size();
    int n = e+1;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<e;i++)
    {
        int u = A[i][0];
        int v = A[i][1];
        int w = A[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    int LN = ceil(log2(n));

    vector<int> lvl(n+1,0);
    vector<vector<int>>dp(n+1, vector(LN,0));
    vector<vector<int>>medge(n+1, vector(LN,0));
    vector<int> ans;

    dfs(1,0,0,lvl,dp,medge,adj);

    int q=B.size();
    for(int i=0;i<q;i++)
    {
        int u = B[i][0], v= B[i][1];
        ans.push_back(max_edge(u,v, lvl, dp, medge));
    }

    return ans;
}

int main()
{
	return 0;
}

