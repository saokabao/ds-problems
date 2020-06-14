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

/*
 * Input array is k sorted array where each integer is atmost k
 * positions away from its position in a sorted  array. How would you sort this array?
 *
 * Usual sorting: quickSort  mergerSort, heapSort : O(nlogn)
 *
 *
 * */
int main()
{
    int n;
    cin>>n;
    cout<<"\nInputArray:\n";
    vector<int> A(n);
   for(int  i=0;i<n;i++) cin>>A[i];
 
   cout<<"\n enter K: ";
   int k; cin>>k;

   priority_queue<int, vector<int>, greater<int> > PQ;

   for(int  i=0;i<k+1;i++)
   {
	   PQ.push(A[i]);
   }

   // 0,1, k  k+1,
   for(int i=k+1;i<n;i++)
   {
	   int top = PQ.top();
	   PQ.pop();

	   A[i-k-1] = top;
	   PQ.push(A[i]);
   }

   for(int i= n-1-k; i<n;i++)
   {
	int top = PQ.top(); PQ.pop();
	A[i] = top;
   }

   cout<<"Sorted array: \n\n";
   for(int i=0;i<n;i++) cout<<A[i]<<" ";

   cout<<"\n\n";

   return 0;

}
































