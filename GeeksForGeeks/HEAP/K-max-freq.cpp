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
#include<unordered_map>
#include<unordered_set>

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


struct compare
{

	bool operator () (pair<int,int>p1, pair<int,int>p2)
	{
		if (p1.second == p2.second)
		{
			return p1.first < p2.first;
		}

		return p1.second < p2.second;
	}
};


int main()
{
	int k,n;
	cout<<"Enter array: ";

	k=2;
	
	vector<int> A= {3, 1, 4, 4, 5, 2, 6, 1};


	 n = A.size();

	unordered_map<int,int> hashmap;
	map<int,int> bst;

	for(int i=0;i<n;i++)
	{
		hashmap[A[i]]++;
		bst[A[i]]++;
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, compare > PQ;
	for(const auto &it : hashmap)
	{
		cout<< it.first <<" : "<< it.second<<"\n";  
		PQ.push(make_pair(it.first,it.second));		
	}

	cout<<"\n BST: \n";
	for( auto &it : bst)
	{
		cout<<it.first<<" : " <<it.second<<"\n";
		it.second++;
	}

	cout<<"\n\n after editing\n";

        for(const auto &it : bst)
	{
		cout<<it.first<<" : " << it.second<<"\n";
	}

	cout<<"output: \n\n";
	int d=0;
	while(d<k)
	{
		pair<int,int> X = PQ.top();
		PQ.pop();
		cout<<X.first<<" : "<<X.second<<"\n\n";
		d++;
	}
	return 0;
}




