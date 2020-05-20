

/* This  is the 2nd method in GFG to convert bst to dll.
 * This  is in contrast with  morris traversal!  
 *  In first  step, we fix left pointers by tracking  last visited node. (static node)
 *  The last visited node  here will be the left pointer for current node.
 *
 *  Once left pointers are fixed, fix all the right motherfucking pointers.
 * 
 *   morris traversal doesnt fixes inorder successor of every  node.
 *  It just modified inorder successor of leaf nodes.
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

struct node
{
	int data;
	node *left,*right;

	node  (int num)
	{
		data = num;
		left=right=NULL;
	}
};

void inorder(node *root) //morris
{
	while (root != NULL)
	{
		if (root->left != NULL)
		{
			node *rightMost  = root->left;

			while (rightMost->right != NULL && rightMost->right  != root)
				rightMost = rightMost->right;

			if (rightMost->right == NULL)
			{
				rightMost->right = root;
				root = root->left;
			}
			else if (rightMost->right == root)
			{
				rightMost->right = NULL;
				cout<<root->data<<"--";
			       root = root->right;	
			}
		}
		else
		{
			cout<<root->data  << "--";
			root = root->right;
		}
	}
}



void printRight(node *root)
{
	if (root == NULL) return;
	cout <<root->data<<"--";
       printRight(root->right);	
}

void printLeft(node *tail)
{
	if (tail == NULL) return;
	cout<<tail->data<<"--";
	printLeft(tail->left);
}

//recursive
void fixLeftPtr(node *root)
{
	static node *predecessor = NULL;
	if (root == NULL) return;

	fixLeftPtr(root->left);

	root->left = predecessor;
	predecessor = root;

	fixLeftPtr(root->right);
}



node * bstToDll(node *root)
{
	if (root == NULL) return NULL;

	fixLeftPtr(root);

	while(root->right != NULL) root = root->right;


	while (root->left !=NULL)
	{
		node *tmp = root->left;
		tmp->right = root;
		root = root->left;
	}

	return root;
}


int main()
{
	node *root = new node(15);
	root->left = new node(10);
	root->right = new node (25);
	root->left->left = new node(5);
	root->left->right = new node(12);
	root->right->right = new node(30);
	root->right->left = new node(25);

	cout<<"Inorder:\n\n";
       inorder(root);	

       root = bstToDll(root);

       cout<< "\n PrintRight";
       printRight(root);

       cout<<"\n\n";

       while (root->right!=NULL) root = root->right;
	cout<<"\n\n printleft\n\n";
	printLeft(root);

       cout<<"\n\n";
       return 0;
}

