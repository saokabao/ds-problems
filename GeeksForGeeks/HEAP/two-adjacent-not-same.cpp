/*
 *  Given a string, arrange characters in the string such that no two
 *  adjacent characters are same. If not possible , print "NO".
 *
 *  This needs to be done greedily. The character with  highest frequency,
 *  needs to be catered after first. Otherwise they will only cause duplication in adjacent.
 *
 *  Freq of highest freq char should be <= total other characters.   if true, it should be possible.
 *
 *  put all char with frquencey  into PQ. if top of PQ is not equal to last char, pop PQ , put char on ans string
 *  , decrease frequency  and push back. if top of PQ is equal  to  last char, pop and save, then pop another, append to
 *  string, decrease frequency and then push both back again.
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
#include<unordered_map>

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

struct key
{
	int freq;
	char ch;
	
	key(int f, char c)
	{
		freq = f;
		ch =c;
	}

	bool operator <(const key &k) const
	{
		return freq<k.freq;
	}

};


void populateFreqMap(string &A,  unordered_map<char, int> &maps)
{
	for(int  i=0;i<A.size();i++)
	{
		auto it = maps.find(A[i]);
		if (it  == maps.end())
		{
			maps.insert(make_pair(A[i],1));
		}
		else
		{
			it->second = it->second + 1;
		}
	}
}

void pushMapOnPQ(priority_queue<key> &PQ, unordered_map<char, int> &maps)
{
	for(auto it = maps.begin(); it!=maps.end();it++)
	{
		key *k = new key(it->second, it->first);
		PQ.push(*k);
	}
}


int main()
{
	while(1)
	{
		string A; cin>>A;
		string ans="";
		
		 priority_queue<key> PQ;

		 unordered_map<char, int> maps;
		 populateFreqMap(A,maps);
		 pushMapOnPQ(PQ,maps);

		 char lastChar = '#';
		 bool noans =false;
		
		 while (PQ.empty() == false)
		 {
			key k1 = PQ.top();
			if (k1.ch == lastChar)
			{
				PQ.pop();
				if (PQ.empty() == false)
				{
					key k2 = PQ.top();
					PQ.pop();
					ans+=k2.ch;
					lastChar = k2.ch;
					k2.freq--;
					if (k2.freq != 0)
					{
						PQ.push(k2);
					}
					PQ.push(k1);
				}
				else
				{
					noans = true;
					cout<<"No Solution exists\n";
					break;
				}
			}
			else
			{
				PQ.pop();
				ans+=k1.ch;
				k1.freq--;
				lastChar =  k1.ch;
				if (k1.freq != 0)
				{
					PQ.push(k1);
				}
			}
		 }
		 if (!noans)
		 {
			 cout<< "ans: "<<ans<<"\n";
		 }
	}
	return 0;

}

