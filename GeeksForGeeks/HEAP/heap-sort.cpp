#include<iostream>

/* Heap sort :
 * Index of deepest internal node is n/2 -1;
 * Heapify can be done on nodes whose subtrees are already heapified.
 *
 * In heap sort, you make a max heap. 
 * And remove top element and put heap's last element on top and heapify  
 * and reduce size by 1. 
 *
 * This is basically make a max-heap and do extractMax till heap size is 0. 
 *
 *
 * */


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
void swaps( int &a,  int &b)
{
	int temp = a;
	a= b;
	b = temp;
}
void heapify(vector<int> &A, int size, int index)
{
	int large = index;
	int largest = A[index];

	while(1)
	{
		int left  = 2*index+1;
		int right = 2*index+2;

		if (left < size && A[left] >  A[large])
		{
			large =  left;
			largest  =A[left];
		}
		
		if (right<size && A[right]> largest)
		{
			largest = A[right];
			large = right;
		}

		if (large  == index)
		{
			break;
		}

		swaps(A[index], A[large]);
		index =  large;
	}
}

int main()
{
	int n; cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++)cin>>A[i];


	for(int i=n/2 -1; i>=0;i--)
	{
		heapify(A,n,i);
	}

	
	for(int i=n-1;i>0;i--)
	{
		swaps(A[i],A[0]);
		heapify(A,i,0);
	}

	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<A[i] << " ";
	}
	cout<<endl;

}

