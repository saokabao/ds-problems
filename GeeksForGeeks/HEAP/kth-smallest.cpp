
/*
 * Kth largest/smallest element in an unsorted array:
 *
 * 1. bubble up: O(nk)
 * 2. maxHeap: O(n + kLogn)
 *    Make a maxHeap of all n array element and pop k elements to get
 *    kth largest element. 
 *
 * 3. minHeap: O(k + (n-k)logk)
 *    Make minHeap of element from index 0 to k-1.
 *    from k to n-1 : 
 *    if A[i] > minHeap.top() , minHeap.top = A[i], heapify(0)
 *   
 *    after traversal pop from minHeap, it is the kth largest element.
 *
 * 4. quickSelect: find the pivot till the pivot is kth smallest element.
 *     Average  case : O(n), worst case: O(n^2)
 *
 *  gist: Make last element as the pivot. Partition the array based on this pivot.
 *       let pivot's new position is pos. 
 *
 *       if pos == k-1 return A[pos].
 *       else if pos > k-1 partition(l,pos-1,k)
 *       else if pos < k-1 parition (pos+1, r,k)
 *
 *       
 *
 * 5. quickSelect Ext1: Average case O(n), worst case: O(n^2)
 * 6. quickSelect Ext2: Worst case: O(n)
 * */

//#4 is implemented here
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

int partition(vector<int>&A, int l, int r, int k)
{
	int i = l;
	for(int  j=l;j<r;j++)
	{
		if (A[j] <= A[r])
		{
			swap(A[i],A[j]);
			i++;
		}
	}
	swap(A[i],A[r]);

	int pos = i;
	if (pos == k-1)
	{
		return A[pos];
	}
	else if (pos > k-1)
	{
		return partition(A,l,pos-1,k);
	}
	else 
	{
		return  partition(A,pos+1,r,k );
	}
}


int KthLargest(vector<int> &A, int k)
{
	int n  = A.size();
	if (k>n)return INT_MAX;

	return partition(A,0,n-1,k);
}


int main()
{
	int n; cin>>n;
	vector<int> A(n);
	cout<<"Input array: ";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	} 
	int k;
	cout<<"\n k: ";
	cin>>k;

	int x = KthLargest(A,k);
	cout<<"\n KthLargest: "<<x<<"\n";

}

