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

struct node 
{
    int data;
    node *left;
    node *right;
    
};

void insert(node* & root, int data, int & succ)
{
	if (root == NULL)
	{
		node *newNode = new node;
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
	}
	else if (root->data > data)
	{
		succ = root->data;
		insert(root->left, data, succ);
	}
	else
	{
		insert(root->right, data,  succ);
	}
}

void replace(vector<int>  &A)
{
    node *root = NULL;
    int n = A.size();

    for (int i=n-1;i>=0;i--)
    {
  	int succ =-1;

	insert(root, A[i], succ);
	A[i] = succ;
    }
}

void printA(vector<int> &A)
{
    for (int i=0;i!=A.size();i++)
    {
	    pl(A[i]); pl(" ");
    }
    nl;
}

int main()
{
    vector<int> A = {23,56,45,25,4,34,8,36,54};
    replace (A);

    printA(A);

    return 0;

}

