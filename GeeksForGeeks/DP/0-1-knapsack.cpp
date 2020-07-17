/*
 *  0-1 knapsack problem.
 *
 *  A[] = {values}
 *  B[] = {weights}
 *
 *  Capacity  : C
 *
 *  find optimal combination of wieghts from B[] such that total weights
 *  is less than / equal to C and total value (A[]) is maximised.
 *
 *  
 *
 *
 *  w(i,j) = max(w(i-B[j],j-1) + A[j], w(i,j-1));
 *
 *  This solution takes space complexity of Capacity*(N+1).
 *
 *  Space complexity can be optimized by using a single array of Size 'Capacity'.
 *  ans[capacity+1] : maximum value for capcity i is represented by ans[i].
 *  
 *
 *
 *  https://www.interviewbit.com/problems/0-1-knapsack/
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
    #define in(a) cin>>a
    #define nl cout<<endl
    #define present(container,element) container.find(element)!=container.end()
    #define cpresent(container,element) find(all(container),element)!=container.end()


 ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	cout<<"n: \n";
	int n;
	in(n);

	cout<<"\n values: \n";
	vi A(n);

	fu(i,0,n-1) in(A[i]);

	cout<<"\n weights: \n";
	vi B(n); fu(i,0,n-1) in(B[i]);

	pl("capacity: ");
	ll C; in(C);
	
	vvi dp(C+1, vi(n,0));


	fu(i,0,C)
	{
		fu(j,0,n-1)
		{
			if (i==0 && j==0)
			{
				if (B[0] == 0) dp[0][0] = A[0];
			}
                        else if (i==0)
			{
				if (B[j] == 0) dp[i][j] = dp[i][j-1] + A[j];
			}
			else if (j==0)
			{
				if  (i <= B[j])
				{
					dp[i][j] = A[j];
				}
			}
			else
			{
				if (B[j] <= i)
				{
					dp[i][j] = max(dp[i-B[j]][j-1]+ A[j], dp[i][j-1]);
				}
				else dp[i][j] = dp[i][j-1];
			}
		}
	}

	pl("ans: ");
	pl(dp[C][n-1]);nl;nl;



}

