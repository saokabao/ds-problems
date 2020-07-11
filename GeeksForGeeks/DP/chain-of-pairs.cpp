/*
 *  https://www.interviewbit.com/problems/chain-of-pairs/
 *
 *  LIS problem with pairs. 
 *  Input is NX2 matrix. chain is formed between i and j if  A[i][1] < A[j][0].
 *  it is given A[i][0] < A[i][1].
 *
 *  find the longest increasing chain of tuples.
 *
 *  Solution: LIS solution with only comparison modified.
 *  O(n^2)
 *
 *  ToDo: Implement O(n) LIS solution to this problem.
 *  There is beautiful LIS solution using stack with O(n) time and O(1) space complexity.
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

}

