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

/**
 * How to decreseKey or changeKey in a BST.
 * It cant be done inplace like heaps. 
 * One needs to do first delete the element and insert new element.
 * Deleting code is tricky. 
 *   You reach the node A whose value needs to be deleted.
 *   if A has only rightChild,  then  A->right is returned and A is freed.
 *   if A has only left child, them A->left is returned and A is freed.
 *   else A's inorder successor value is retrieved and put to A's place and
 *   recursively delete is called on A->right subtree with successor's value.
 *   meaning recursivley inorder successor of A is deleted.
 *
 * */
struct node
{
	int data;
	node *left,*right;

	node(int val)
	{
		data = val;
		left=right=NULL;
	}
};

node* insert(node *root, int val)
{
	if (root==NULL) return new node(val);
	if (val < root->data)
	{
		root->left = insert(root->left, val);
	}
	else
	{
		root->right = insert(root->right, val);
	}
	return root;
}


void inorder(node *A)
{
     while (A != NULL)
     {
		if (A->left != NULL)
		{
			node *rightMost  =  A->left;
			while (rightMost->right != NULL && rightMost->right!=A) rightMost = rightMost->right;

			if (rightMost->right == NULL)
			{
				rightMost->right =A;
				A = A->left;
			}
			else if (rightMost->right == A)
			{
				rightMost->right = NULL;
				cout<<A->data<< " ";
				A = A->right;
			}
		}
		else
		{
			cout<<A->data<<" " ;
			A = A->right;
		}
     }
}


int minRightVal(node *root)
{
	while (root->left!=NULL) root = root->left;

	return root->left->data;
}

node* deleteNode(node *root, int old)
{
	if (root == NULL) return NULL;
	else
	{
		if (old < root->data)
		{
			root->left = deleteNode(root->left, old);
			return root;
		}
		else if (old> root->data)
		{
			root->right = deleteNode(root->right, old);
			return  root;
		}
		else
		{
			if (root->left == NULL)
			{
				node *temp = root->right;
				free(root);
				return temp;
			}
			else if  (root->right == NULL)
			{
				node *temp = root->left;
				free(root);
				return temp;
			}
			else
			{
				int minRight = minRightVal(root->right);
				
				root->data = minRight;

				root->right = deleteNode(root->right, minRight);

				return root;
			}
		}
	}
}

node *changeValue(node *root, int old, int nw)
{
	root = deleteNode(root, old);
	root = insert(root, nw);

	return root;
}

void inorderR(node *A)
{
	if (A==NULL) return;
	inorderR(A->left);
	cout<<A->data<<" ";
	inorderR(A->right);
}

int main()
{
    node *root = new node(15);

    root->left = new node(10);
    root->right = new node(25);

    root->left->left = new node(5);
    root->left->right = new node(12);

    root->right->left = new node(20);
    root->right->right = new node(30);


    cout<<"INorder:\n\n";
    inorder(root);
    nl;nl;

    root = changeValue(root,20,13);

    cout<<"changed:\n\n";

    inorder(root);
    nl;nl;
    return 0;
}

