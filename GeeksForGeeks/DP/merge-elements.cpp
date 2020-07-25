
/*
 *  https://www.interviewbit.com/problems/merge-elements/
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


int solve(vector<int> &A)
{
    int n = A.size();

    vector<vector<int>>dp(n, vector<int>(n,INT_MAX));

    vector<int>S(n,0);

    for(int i=0;i<n;i++)dp[i][i] = 0;

    S[0] = A[0];
    for(int i=1;i<n;i++) S[i] = S[i-1]+A[i];

    for(int i= n-1;i>=0;i--)
    {
        for(int j =i;j<n;j++)
        {
            for(int k = i ; k<j;k++)
            {
                int X = dp[i][k] + dp[k+1][j] + S[k]-S[i]+A[i] + S[j]-S[k+1]+A[k+1];
                dp[i][j] = min(X, dp[i][j]);
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
 
}

