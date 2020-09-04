/*
 * Palindromic partitionin of the string: 
 * Given a string , return the minimum number of cuts to the string such that
 * each partitioned string is a palindrome.
 *
 * Idea is similar to following problem:
 * Given  sentence and dictionary, and we need to figure out whether any arrangement in the words of the dictionary could
 * form the input sentence. or in other words input string can be segmented into words from dictionary. 
 *
 * eg: myinterviewtrainer
 * dict = ["trainer", "inter","view","my"]
 *
 * my solution: for every substring, find whether it could be formed from dict.
 * DP[0,N-1] = true if there exists a K, DP[0,K] &&  DP[K+1,N-1]
 * to iterate all the substring: N^2,
 * to  make a substring: N
 * to check a substring is present in dict: Log(M)*L
 *
 * total complexity: N^3.O(1)
 *  
 *  N = 6.10^3
 *  M = 10^4
 *  L = 20
 *
 *   >=10^9
 *
 *  if we use  trie:
 *  to get all the substring: N^3.20   ===  216.10^9.20 == 10^12
 *
 *  What is better for searching string in a dict? A trie or a unordered_set<string> (hashmap)  
 *
 *  GFG solution:
 *  Maintain dp[i] : is true if A.substr[0,i] is present in the dict.
 *  matched_index[k] : list of indexes in A, such that A[0,k] exists in the dict.
 *
 *  for every i [0,n-1], iterate all k in matched[] and see if A[k+1, i] exists in dict.
 *  if A[k+1,i]exists in dict, then dp[i] is true.
 *
 *  This solution passes if you do second iteration from end of the matched array instead of beginning
 *  of the matched array.
 *
 *  It  is because of a test case outlier because of which above trick passes.
 *  Time complexity and contants are same in both ways.
 *  There is no other parameter for which one way could be better than the other.
 *
 *  
 *
 *
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

class TrieNode
{
	vector<TrieNode*> links;
	int R=26;
	bool isEnd = false;

	public:
	TrieNode()
	{
		links.resize(26,NULL);
	}

	void put(char x)
	{
		links[x-'a']= new TrieNode();
	}

	TrieNode* get(char x)
	{
		return links[x-'a'];
	}

	bool has(char x)
	{
		return NULL!=links[x-'a'];
	}

	bool getIsEnd() {return isEnd;}
	void setIsEnd(bool X){isEnd = X;}

};

class Trie
{
      TrieNode *root;

	public:

      Trie()
      {
	      root = new TrieNode();
      }

      void insert(string A)
      {
	      TrieNode *node = root;
	      for(int i=0;i<A.size();i++)
	      {
			if (!node->has(A[i]))
			{
				node->put(A[i]);
			}
			node = node->get(A[i]);
	      }
	      node->setIsEnd(true);
      }

      bool search(string A)
      {
           TrieNode *node = root;
	   for(int i=0;i<A.size();i++)
	   {
		   if (!node->has(A[i])) return false;
		   node = node->get(A[i]);
	   }

	   return node->getIsEnd();	
      }

};

int main()
{
        string A="saokabao";
        Trie trie;
	trie.insert("sao");
	trie.insert("ka");
	trie.insert("bao");
	
        int n = A.size();


	vector<bool> dp(n,false);
	vi matched;
	matched.pb(-1);

	for(int i=0;i<n;i++)
	{
		int m = matched.size();
		for(int j=m-1;j>=0;j--)
		{
			if (trie.search(A.substr(matched[j]+1, i-matched[j])))
			{
				dp[i]=true;
				matched.pb(i);
				break;
			}
		}
	}
	if (dp[n-1])cout<<"Yes\n";
	else cout<<"No\n";

}

