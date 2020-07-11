
/*
 *    #1 https://leetcode.com/problems/domino-and-tromino-tiling/
 *    
 *    #2 https://www.interviewbit.com/problems/tiling-with-dominoes/
 *
 *    Two variations of tiling problem. Should be done in order. #1 and then #2.
 *
 *    #1. Area dimension is 2XN, 
 *    2D dp solution:
 *
 *    tiles sizes are:  XX  X  XX   XX   X   X
 *                          X   X   X   XX   XX
 *
 *    i : column from where tiling needs to be done in row1
 *    j : column from where tiling needs to be dine in row2.
 *
 *    fun(i,j): total  number of ways to to tile from (i,j)                        
 *    ans : fun(0,0);
 *    
 *    case 1: i==j
 *            f(i,j) = f(i+1,j+1) + f(i+2,j+2)+ f(i+2,j+1) + f(i+1,j+2);
 *    case 2: i-j == 1
 *            f(i,j) = f(i,j+2) + f(i+1,j+2);
 *    case 3: j-i == 1
 *            f(i,j) = f(i+2,j) + f(i+2,j+1)
 *    case 4: abs(i-j) >=2  return 0;
 *
 *    1D dp solution:
 *
 *    f(n) : number of ways such that grid is fully filled till column n.
 *    g(n) : number of ways such that at least one box is empty in column n.
 *
 *    XXXX    XX|   X--    XX|     X--
 *    XXXX    XX|   X--    X--     XX|
 *    f(n)  = f(n-1) + f(n-2) + g(n-1);
 *
 *   XXXX    XXX        XXXX
 *   XXXX    XXXX       XXX    
 *    g(n) = g(n-1) + 2*f(n-2);
 *
 *    fn = 2*f(n-1) + f(n-3);
 *
 *
 *
 *    #2 3XN grid with 2X1 tiles. Explained in another file.
 *
 */


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

int numTilings(int N)
    {
        long long mod = 1000000007;
        vector<int> dp(N+1,0);
        dp[0] = 1;
        dp[1] = 1;

        if (N < 2) return 1;

        dp[2] = 2;
        for(int i=3;i<=N;i++)
        {
            dp[i]  = ((dp[i-1] + dp[i-1])%mod + dp[i-3])%mod;
        }
        return dp[N];
    }

int main()
{
	int N; cin>>N;

        vector< vector<int> >dp(N+1, vector<int> (N+1,-1));

	long long mod = 1000000007;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[2][1] = 1;

	for(int i=0;i<=N;i++)
	{
		for(int j =0;j<=N;j++)
		{
			if (dp[i][j] != -1)   continue;

			long long ans = 0;
			if (i==j)
			{
				if (i-1>=0 && j-1 >=0) ans += dp[i-1][j-1] % mod;
				if (i-2>=0 && j-2 >=0) ans += dp[i-2][j-2] % mod;	
				if (i-2>=0 && j-1 >=0) ans += dp[i-2][j-1] % mod;	
				if (i-1>=0 && j-2 >=0) ans += dp[i-1][j-2] % mod;	
			}
			else if (i-j == 1)
			{
				if (i-2>=0 && j-1>=0) ans += dp[i-2][j-1] % mod;
						
				if (i-2>=0 && j>=0) ans += dp[i-2][j] % mod;	

			}
			else if (j-i == 1)
			{
				if (i-1>=0 && j-2>=0) ans += dp[i-1][j-2] % mod;
			        	
				if (i>=0 && j-2>=0) ans += dp[i][j-2] % mod;
			}
			dp[i][j] = ans;
		}
	}
	cout<< "Ans : "<< dp[N][N] <<"\n\n";

}
























