/*
 * K largest element in an array of integers.
 * If sorted, print element from index n-1 to n-k
 *  
 *  Smallest indexs in a sorted array:
 *  Index of Kth smallest element: k-1.
 *  Distance of Kth smallest element from 0th element: k-1
 *  total elements between 0th and kth indexed smallest element: k+1.  
 *  Print first K element: 0 k-1
 *
 *  Largest indexs in a sorted array:
 *  Index of the Kth larget element: n-k. 
 *  Ditance of Kth largest element and last element: n-1 - n +k = k-1;
 *  total elements between last element and Kth largest element: k.
 *  print k largest elements: n-1 to n-k
 *
 *  
 *  Max Heap: O(n) + O(kLogn). 
 *  Sorting O(nlogn)
 *  
 *  Bubble sort: O(n*k)
 *
 *  Min heap: O(k + (n-K)logK + klogk) = O(K + nLogK)
 *
 *  Order statistic: if unsorted output: O(n), else O(n+klogk)
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


void useMaxHeap(vector<int> &A,int k) //O(N + kLogN)
{
	cout<< "Use max heap: \n\n";
	priority_queue<int> PQ;
	int n = A.size();
	for(int i=0;i<n;i++)
	{
		PQ.push(A[i]);
	}

	 n =0;
	while(n<k)
	{
		cout<<PQ.top() << " ";
		PQ.pop();
		n++;
	}
	cout<<"\n\n";

}


void useMinHeap(vector<int> &A, int k) 
{
	cout<< "use min heap:\n";
	priority_queue<int, vector<int>, greater<int> >PQ;
	for(int i=0;i<k;i++)PQ.push(A[i]);

	int n = A.size();
	int x = PQ.top();
	for(int j=k;j<n;j++)
	{
		if (A[j] > x)
		{
			PQ.pop();
			PQ.push(A[j]);
		}
	}

	while(PQ.size() !=0)
	{
		cout << PQ.top() << " ";
		PQ.pop();
	}
	cout<<"\n\n";
}


int main()
{
	int n; cin>>n;
	vector<int> A(n);
        for(int i =0;i<n;i++)
	{
		cin>>A[i];
	}
	int k;
	cout<<"\nK: "; cin>>k;
	useMaxHeap(A,k);
	useMinHeap(A,k);

//	useOrderStatistics(A,k);

	return 0;	
}

































