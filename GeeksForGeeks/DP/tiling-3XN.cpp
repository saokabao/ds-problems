
/*
 *  XXX    XXXX
 *  XXX    XXXX
 *  XXX    XXXX
 * 
 * 3XN grid to be filled with 2X1 tiles.
 * XX  X
 *     X
 * 
 *
 * f(n) : fully filled grid till column n.
 * g(n) : full filled grid till column n-1, partially filled at n.
 *
 *  XXXX
 *  XXXX
 *  XXXX
 *
 *  #1 Following recurrence is obtained with following definition of g();
 *  In this solution , g(n) : represents either empty top cell or empty bottom cell configuration.
 *  Since it represent either of the configuration, 2 is multipled to g(n-1).
 *
 *
 *  f(n) = f(n-2) + 2.g(n-1)
 *  g(n) = f(n-1) + g(n-2)
 *
 *  f(0) = 1
 *  f(1) = 0
 *
 *  g(0) = 0
 *  g(1) = 1
 *
 *  
 *  #2
 *  In this solution, g(n) : represents both empty top and empty bottom cell of column n.
 *
 *  f(n) = f(n-2) + g(n-1)
 *  g(n) = 2.f(n-1) + g(n-2)
 *
 *
 *  Both #1 and #2 recurrence result to f(n) = 4.f(n-2) - f(n-4). ---(3)
 *  but (3) doesnt give correct programmtically. Verify during  revision.
 *
 *  https://www.interviewbit.com/problems/tiling-with-dominoes/
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

}

