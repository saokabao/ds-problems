
/*
 *  In a matrix of all 0 and 1, find the area of maximum sized square formed using 1.
 *
 *
 *
 *   1 1 1      1 1      1 1 1 1
 *   1 1 1      1        1 1 1 1
 *   1 1                 1 1 1 1
 *                       1 1 1 
 *
 *                 
 *   S[i][j] : represents side of the maximum sized squre ending at i,j as bottom right cell.
 *
 *   if A[i][j] == 1 
 *      S[i][j] = min (S[i-1][j-1], S[i-1][j], S[i][j-1]) + 1
 *
 *   Take the max of all S[i][j] and return its square to get the maximum area
 * 
 *    https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/
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

int main()
{

}

