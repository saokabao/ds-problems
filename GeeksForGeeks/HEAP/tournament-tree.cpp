/*
 *   Tournament tree is used to find kth smallest number in an unsorted array of size N.
 *
 *   This  comes  in  handy for the following problem:
 *   Select smallest 1 million out of 1 billion records when you can only 1 million records in memory at a time.
 *  
 *   In brute force solution, each time we need to M comparisons if we operate on lists.
 *   Using winner tree, each  time we need to do logM comparisons. 
 *
 *   Brute force complexity: m*M , where mth number is the median.
 *   Winner tree complexity is: m*LogM 
 *
 *   total complexity in  biilicon record question = time to sort 1000 1M records  + winner tree construction + tournaments.
 *   
 *
 *   Input: Unsorted arrays of size N. 
 *   To make the tournament tree , height of binary tree needed: ciel(LogN)
 *   Sentinel nodes will be marekd as NULL or INF.
 *
 *
 *   eg 1,3,4,5,6,9,13
 *
 *                                    13
 *                                   /  \
 *                            5                13
 *                           / \             /   \     
 *                        3       5        9       13
 *                      /  \     / \       /\     / \
 *                     1   3     4  5     6   9   13  I     
 *
 *  Winner is 13. Now second winner will lie on first winner's path. 
 *   Second winner will lie on  13th's path. That path is LogN. 
 *   Hence to find next set of winnners, each  iteration will take LogN.
 *
 *
 *   For M list of sizes L1,L2,L3 ...Lm 
 *   merge complexity  : O((L1+L2+L3..Lm)*LogM) ????
 *   To find the median: O(m*(LogM)) where M is the total number of lists
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

}

