
/*
 *  We are starting our study  of  heaps with  Binary heaps.
 *  Other heaps (bionomial,Fibonacci) will be dealt later.
 *
 *  Binary Heaps are of two types: max-heap and min-heap.
 *  Max-heap is a complete binary tree where each child is stricly less
 *  than parent. 
 *  Min-heap is a complete binary tree where each child is stricly greater 
 *  than parent.
 *
 *  Complete binary tree can be represented using array, hence max-heap and
 *  min-heap can and is represented using array. 
 *
 *  A[0] is the root of the heap. 
 *  For i, A[2*i+1], A[2*i+2] are its children.
 *  For i, A[(i-1)/2] is its parent.
 *
 *  Applications of heap: 
 *  1. Heap sort: Sorting can be done using heap called heap sort in O(nlogn)
 *  2. Priority-Queue: Priority-queue can be efficiently implemented using binary heap.
 *     insert(), delete(), extractMax(), extractMin(),  decreaseKey()?  is O(logn).
 *  3. Dijkstra and Prim's minimum spanning tree uses priority-queue.
 *   
 *   Problems solved using binary heaps:
 *   1. Kth largest element in an array.
 *   2. Sort an almost sorted  array.
 *   3. Merge K sorted Arrays.
 *
 *   Operations on Min-heap:
 *   1. Insert(int val): O(logn) : Make input as the  last element and bubble it up.
 *   2. decreaseKey(int i, int target): replace A[i] to target and bubble it up. target is
 *      always  <  A[i]. O(logn)
 *   3. extractMin():  read the A[0], A[0]= A[last]. Heapify(0)
 *   4. delete(int index): decreaseKey of A[i] to -INF. Then  do extractMin.
 *
 *   Suppose you have an array of integers. To make an binary heap out of this
 *   would take O(n) operations, not O(nlogn) operations as it might seem to you.
 *   Is it inplace? 
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

class minheap{
	int C;
	int last;
	vector<int> array;

	int parent(int i) {return (i-1)/2;}
	int left(int i) {return 2*i+1;}
	int right(int i) {return 2*i+2;}

	public: 
	minheap(int C){
		array.resize(C,-1);
		last=0;
	}

	void swap(int &a, int &b)
	{
		int temp = a;
		a=b;
		b=temp;
	}

	void  insert(int data){
		if (last == C-1)
		{
			pl("minHeap full, cant insert");nl;
			return;
		}
		
		array[last] = data;
		last++;
		int child = last-1;
		int pi = parent(child);
		while (pi>=0 && array[child] < array[pi])
		{
			swap(array[pi], array[child]);
			child = pi;
			pi = parent(pi);
		}
	}

	void heapify(int i)
	{
		int smallest=i;
		while (smallest < last)
		{
			int lefti = left(i);
			int righti = right(i);

			if (lefti<last && array[lefti] < array[i])
			{
				smallest = lefti;
			} 
			if (righti<last && array[righti] < array[i])
			{
				smallest = righti;
			}
			if (smallest == i) return;
			swap(array[smallest], array[i]);
			i = smallest;
		}
	}

	int extractMin()
	{
		if (last==0)
		{
			pl("empty queue");nl;nl;
			return INT_MAX;
		}
		int heapmin = array[0];

		array[0] = array[last-1];
		last--;

		heapify(0);
		return heapmin;
	}

	void decreaseKey(int i, int target)
	{
		array[i] = target;
		while(parent(i)>=0 && array[parent(i)] > array[i])
		{
			swap(array[parent(i)], array[i]);
			i  = parent(i);
		}
	}

	void deleteKey(int i)
	{
		decreaseKey(i, INT_MIN);
		extractMin();
	}
};




int main()
{
    minheap heap(20);
    heap.insert(2);
    heap.insert(1);
    heap.insert(4);
    heap.insert(5);
    heap.insert(-3);
    heap.insert(7);


    pl("min:\n\n");
    pl(heap.extractMin()); nl;nl;
    
    heap.deleteKey(0);
     pl("min:\n\n");
      pl(heap.extractMin()); nl;nl;

       heap.decreaseKey(2,-5);
       pl("min:\n\n");
       pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;
      pl(heap.extractMin()); nl;nl;


    return 0;

}

