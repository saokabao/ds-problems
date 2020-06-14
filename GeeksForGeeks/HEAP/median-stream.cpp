/*
 * Median of a stream of integers. Stream will be in random order.
 * While considering stream of integers/array of integers,
 * check:
 * 1. if they are sorted or follow any other order.
 * 2. if  they  are all positive / all negative / zero / non zero
 * 3. product  and division problems, take care of division by zero.
 *
 * back to this problem:
 * Find median for  stream of integers.
 * 1. Insertion sort: Insertion: O(N).Median: O(1)
 * 2. Augmented BST: Insertion O(logN), Median: O(logN) if unbalanced, it could become a linkedList.
 *    It needs to be a balanced BST.
 *
 * 3. Heaps: Median is the middle number of two buckets  of  numbers.
 *   Two heaps are  maintained as the  buckets, where first heap is a
 *   maxHeap containing element less than or equal  to median.
 *   Second heap is a  minHeap containing element greater than or equal to median.
 *
 *   
 *   how to insert new element  and  retrieve median.
 *   Cases:
 *   1. if size of both heap is same
 *      E < median,  leftHeap.insert(E)
 *      E > median, rightHeap.insert(E)
 *
 *   2. if leftHeap > rightHeap
 *      E<median : put top  of leftHeap  to  rightHeap.
 *      then put E on leftHeap. 
 *      median = leftHeap.top;
 *
 *      E>median: rightHeap.insert(E)
 *      median: rightHeap.top + leftHeap.top /2;
 *
 *   3. if rightHeap > leftHeap
 *	E>median: pop  top from rightHeap and put it onto leftHeap.
 *	rightHeap.insert(E);
 *
 *	E<median: leftHeap.insert(E);
 *	median: rightHeap.top + leftHeap.top /2;
 *
 *      coding idea: Have saparate functions for AddNumber/Rebalance/getMedian.
 *      Much more clean code.
 *
 *
 *      priority_queue<HuffmanNode, std::vector<HuffmanNode>, CompareHuffmanNode> my_queue;
 *
 *      struct CompareHuffmanNode {
 		bool operator()(HuffmanNode& n1, HuffmanNode& n2)
 		{
			 return n1.getFrequency() > n2.getFrequency();
 		}

};
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



void insert(int  X, priority_queue<int> &lowerHeap, priority_queue<int, vector<int>,  greater<int> > &upperHeap)
{
	if (lowerHeap.size() == 0 || X < lowerHeap.top())
	{
		lowerHeap.push(X);
	}
	else
	{
		upperHeap.push(X);
	}			
}

void rebalance(priority_queue<int> &lowerHeap, priority_queue<int, vector<int>,  greater<int> > &upperHeap)
{
	int lowSize = lowerHeap.size();
	int  upperSize = upperHeap.size();
	if (lowSize - upperSize >= 2)
	{
		int X = lowerHeap.top();
		lowerHeap.pop();
		upperHeap.push(X);
	}
	else if (upperSize - lowSize >= 2)
	{
		int X = upperHeap.top();
		upperHeap.pop();
		lowerHeap.push(X);
	}

}


double  getMedian( priority_queue<int> &lowerHeap, priority_queue<int, vector<int>,  greater<int> > &upperHeap)
{
	int lowerSize = lowerHeap.size();
	int upperSize = upperHeap.size();

	if (lowerSize == upperSize)
	{
		return ((lowerHeap.top() + upperHeap.top())*1.0) /2;
	}
	else if (lowerSize > upperSize)
	{
		return lowerHeap.top();
	}
	else
	{
		return upperHeap.top();
	}
}

int main()
{
	priority_queue<int, vector<int>, greater<int> > upperHeap;
	priority_queue<int> lowerHeap;

	vector<int> A;
	while(1)
	{
		int t; cin>>t;
		A.push_back(t);
		cout<<"\n\n stream now: \n";
		int n = A.size();
		for(int i=0;i<n;i++) cout<<A[i]<< " ";

		cout<<endl;
		insert(t, lowerHeap, upperHeap);
		rebalance(lowerHeap, upperHeap);
		int med = getMedian(lowerHeap, upperHeap);
		cout<<"median: "<< med << "\n\n";

	}

	return  0;
}




















