/*
 * In stream questions, we have to optimize insertion
 * as well as the value to be computed. 
 *
 * Given stream of integers, find Kth largest element till any given input.
 *
 * Understand why heap formation is O(n)?
 *
 * 
 * 1. minHeap: insertion O(logK), Kth largest: O(1)
 *
 * Maintain a minHeap of K largest elements. 
 * If size of heap is less than K, simply push new element on it. 
 * else, check if Nw  > heap.top(), if true, pop and push. Kth  largest element will be top. 
 *
 *  
 *  ExtractMin  is  basic operation.
 *  decreaseKey is basic operation.
 *  
 *  deleteKey is a derived  operation from combination  of decreaseKey and extractMin.
 *
 * 2. Insertion sort:  Insert O(K) ,Kth largest: O(1).
 * 3. Augmented  BST: Each node contains total node in its left  subtree: Insert O(logK),Kth largest : O(logK)
 * 4. maxHeap: insert O(logN). Kth largest value: O((n-k+1)logN)
 * 5. 
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



class heap
{
	vector<int> A;
	int size;
	int last;

	int parent(int i){return (i-1)/2;}
	int left(int  i) {return 2*i+1;}
	int right(int i) {return 2*i+2;}

	public:
	heap(int n)
	{
		last =0;
		size = n;
		A.resize(n);
	}

	int count(){return last;}	
	void swap(int &a, int &b)
	{
		int temp = a;
		a =b;
		b = temp;
	}

	void insert(int k)
	{
		if (last == size) {cout<<"full queue\n"; return;}
		A[last] = k;
		last++;
		
		int i = last-1;
		while (parent(i)>=0 && A[parent(i)] > A[i])
		{
			swap(A[parent(i)], A[i]);
			i =  parent(i);
		}
	}

	int extractTop()
	{
		if (last ==0) 
		{
			cout<<"Empty queue.\n\n";
			return -1;
		}
		
		int temp = A[0];
		A[0] = A[last-1];
		last--;
		heapify(0);
		return temp;
	}	

	void deleteKey(int index)
	{
		decreaseKey(index, INT_MIN);
		extractTop();
	}


	void decreaseKey(int i, int target)
	{
		A[i] = target;
		while(parent(i)>=0 && A[parent(i)] > A[i])
		{
			swap(A[parent(i)], A[i]);
			i = parent(i);
		}
	}
	
	void  heapify(int i)
	{
		while(1)
		{
		        int small = i;
			int smallest  = A[i];
			if (left(i) < last && A[left(i)] < smallest)

			{
				smallest = A[left(i)];
				small = left(i);
			}
			if (right(i) <last && A[right(i)] < smallest)
			{
				smallest = A[right(i)];
				small  = right(i);
			}
			if (small == i)
			{
				return;
			}
			swap(A[i], A[small]);
			 i= small;
		}
	}

	int top()
	{
		if (last ==0) return -100;
		return A[0];
	}

};
int main()
{

	int k ; cin>>k;
	heap* PQ = new heap(k);
	vector<int> A;
	while(1)
	{
		int t; cin>>t;
		A.push_back(t);
		cout<<"\n series: \n";
		sort(A.begin(), A.end());
		for(int i=0;i<A.size();i++)cout<<A[i]<<" ";
		if (PQ->count() < k) PQ->insert(t);
		else
		{
			if (t > PQ->top())
			{
				PQ->extractTop();
				PQ->insert(t);
			}
		}
		cout<<"\n"<< k<<"th largest: "<<PQ->top()<<"\n\n";
	}

    return 0;

}

