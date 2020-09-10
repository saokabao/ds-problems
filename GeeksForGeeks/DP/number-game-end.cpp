/*
 * Input is interger array . Two players you and computer are playing.
 * Both players are going to play optimally.
 *
 * Game is to pick up number from either end one by one and add to their existing sum.
 * Player with biggest sum wins. Return the maximum sum obtained by  you.
 * You get to pick the first number.
 *
 *  1 2 3 4
 *  ans: 6
 *
 *  5,4,8,10
 *  ans: 15
 *
 *  User1 has two ways to  select a  number. Either one of could
 *  result in a optimal answer. 
 *  let f(i,j) represents user1 maximum sum obtained by user1 from indexes i to j.
 *  f(i,j) = max(A[i] + min(f(i+2,j), f(i+1,j-1)),  i+1, j  i+2,j   i+1,j-1
 *               A[j] + min(f(i+1,j-1),f(i,j-2)));       i,j-1  i+1,j-1.  i,j-2
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
  //write code
}

