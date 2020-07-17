/*
 * Input A[] of positive integers.
 * Flip minimum number of elements such that total sum is minimum non negative.
 *
 * Make a knapsack of capacity =Sum/2 and fill the knapsack with minimum numbers 
 * such that highest capacity is obtained. 
 *
 * A[capacity+1]
 * A[i] : minimum elements required to make sum i.
 * A[i] == INF : sum i cant be made.
 *
 * A[0] = 0;
 * A[i] = if (A[i-B[j]] != INF ) A[i] = min(A[i-B[j]] + 1 , A[i]);
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
	int n; cin>>n;
	vi A(n); ll sum=0;
	rep(i,n) 
	{
		cin>>A[i];
		sum+=A[i];
	}
	
	ll C = sum/2;	
	vi ans(C+1, INT_MAX);
	ans[0] = 0;

	fu(i,0,n-1)
	{
		fu(j, A[i], C)
		{
			if (ans[j-A[i]] != INT_MAX)
			{
				ans[j] = min(ans[j-A[i]]+1, ans[j]);
			}
		}
	}

	fd(j,C,0)
	{
		if (ans[j]!=INT_MAX)
		{
			pl("cout: ");pl(ans[j]);nl;
			pl("j: ");pl(j);nl;
			cout<< "\nans: "<< sum-2*j;nl;nl;
			break;
		}
	}
	return 0;

}

