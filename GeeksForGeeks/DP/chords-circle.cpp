/*
 *  Find maximum ways in which chords can be drawn out of 2XA points in a circle
 *  such that no two chords intersect.
 *
 *  A =1 , total points = 2, ans =1;
 *  A =2 , total points = 4 ans =2;
 *  A =3 , total points =6 ans = 5;
 *
 *    X
 * X    X
 *
 * X    X
 *    X   
 *  dp[3] = dp[2].dp[0] +  dp[1].dp[1] + dp[0][2];
 *
 *  
 *      X  
 *   X      X
 *
 *   X      X
 *
 *   X      X
 *      X
 *        
 *  To compute number of ways in which we can  draw chords.
 *  Take a point, and draw  all possible chords from this point.
 *  A chord is possible, if  other chords can be drawn in non  intersecting manner.
 *
 *  For each chord of this position, count number of ways in which non intersecting chords can be drawn on remaining points.
 *  Non intersecting chords on  remaning points is a subproblem.
 *
 *
 *  for(int i=3;i<=A;i++)
 *  {
 *      for(int j=0;j<i;j++)
 *      {
 *        dp[i] += dp[j].dp[i-j-1];
 *      }
 *  }
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

int main()
{
   
    
	pl("points: "); 
	int A; cin>>A;
        vi dp(A+1,0);
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;

	for(int i=3;i<=A;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i] += dp[j]*dp[i-j-1];
		}
	}
	cout<<"ways to draw chords: "<<dp[A];
	nl;nl;
	return 0;
}

