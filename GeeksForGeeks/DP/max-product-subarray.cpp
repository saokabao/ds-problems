/*
 * Given an array of integers, find a subarray whose product is maximum and return the product.
 *
 *
 * Eg. 2,5,-4,6 = 10
 * -2,5,-3, -4, 6 = 48
 *  -4 5, 0 3, 4 = 12
 *  -2 = -2
 *  0 ,-2 = 0
 * 
 *  For each position i in the array,
 *  maintain maxP and maxN. 
 *  maxP: maximum poduct of subarray ending at A[i] or starting at A[i].
 *  maxN: minimum product of subarray ending at A[i] or starting at A[i].
 *
 *  maintain ans variable and at each i, save maxP to ans if maxP>ans.
 *
 *  if A[i] >= 0 , maxP = max(maxP.A[i], A[i])
 *                 maxN = min(maxN.A[i], A[i]);
 *  if A[i] < 0    maxN = min(maxP.A[i],A[i])
 *                 maxP = max(maxN.A[i],A[i]);
 *
 *  maxP = max(maxN.A[i], maxP.A[i],A[i])
 *  maxN = min(maxP.A[i], A[i], maxN.A[i])
 *
 *  There are three possible candidate for maxP, maxP.A[i], A[i], maxN.A[i]
 *  three candidates for maxN, A[i], maxP.A[i], maxN.A[i]
 *  
 *  One more way to think about this problem is prefix and suffix products.
 *  Lets look at few examples :
 *
 *  -2 -5 6 8     = [-2,-5,6,8]
 *  -2 3 -4 4 -6  = [3 -4  4 -6]
 *  -4              = [-4]
 *  -2 0 3 4  0   = [3,4]
 *  -2 -3 -4 -5 -3 = [ -3 -4 -5 -3]
 *
 *  if we compute prefix and suffix products at  every index, maximum of these products is our answer.
 *  Handle 0 such that at every 0, we restart the prefix/suffix product computation  from the next index.
 *
 *
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
   int n; cin>>n;
   vi A(n); cout<<"Input array: \n";
   fu(i,0,n-1)cin>>A[i];


   int maxP = INT_MIN, maxN = INT_MAX, ans =  INT_MIN, O_maxP;

   maxP = A[0];
   maxN = A[0];
   ans  = A[0];
   fu(i,1,n-1)
   {
	   O_maxP = maxP;
	   maxP = max(max(A[i], maxP*A[i]),maxN*A[i]);
	   maxN = min(min(O_maxP*A[i], A[i]),maxN*A[i]);
	   ans = max(ans, maxP);	
   }

   cout<<"ans :"<<ans<<endl;
   return 0;
}

