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
	node *left, *right;
};


node * newNode(int data)
{
	node *head = new node;
	head->data = data;
	head->left = NULL;
	head->right = NULL;

	return head;
}

void inorder(node *root)
{
	if (root==NULL) return;
	inorder(root->left);
        pl(root->data); pl (" ");
	inorder(root->right);
}

void   findSandP(node *root, int A,  node* &succ, node* &pre)
{
	if (root == NULL) return;
	
	if (root->data == A)
	{

		node *minRight, *maxLeft;

		findMin(root->right, minRight);

		findMax(root->left, maxLeft);

		
		
	}
	else
	{
		if (root->data > A)
		{
			succ = root;
			findSandP(root->left, A, succ, pre);
		}
		else
		{
			pre = root;
			findSandP(root->right, A, succ, pre);
		}
	}
}

int closestNode (node *root, int A)
{
	node *succ, *pre;

	findSandP(root,A, succ, pre);

	int ans = INT_MAX, diff1 = INT_MAX, diff2 = INT_MAX;

        if (pre !=  NULL)
	{
		diff1 = abs (pre->data - A);
		ans = pre->data;
	}
	if (succ != NULL)
	{
	     diff2  = abs(succ->data - A);
	     if (diff2<diff1) ans = succ->data;
	}
	return ans;
}

int main()
{
      node *root = newNode(9);

      root->left = newNode(4);
      root->right = newNode(17);
      root->left->left = newNode(3);
      root->left->right = newNode(6);
      root->right->right = newNode (22);
      root->right->right->left  = newNode (20);
      root->left->right->left = newNode (5);
      root->left->right->right = newNode (7);

      inorder(root);

      int k; cin>>k;
      while(k--)
      {
	      int B ; cin>>B;
	      int ans =  closestNode(root,B);

	      pl("closes node : "); pl(ans); nl;nl;

      }

      return 0;
}

