/*
 *  This is a nice interesting question.
 *   Input is complete binary tree BST and we need to  convert it to follow
 *   the properties of min-heap in  the same input tree.
 *
 *   Also make  sure all nodes  in the left-subtree should be
 *   less than all nodes in the  right-subtree.
 *
 *          4
 *        /  \
 *       2    6
 *      /\    /\ 
 *     1  3  5  7
 *
 *    Solution 1: Run heapify from the right most deepest internal node. O(nlogn)
 *
 *    Solution2:
 *    1. Traverse inorder and keep the output sorted elements in an array A[].
 *    2. Now traverse the bst in preorder and at each node copy one element from A[].
 *
 *    time: O(n)
 *    space: O(n)
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

struct node
{
	int data;
	node *right, *left;

	node(int val)
	{
		data=val;
		left=right=NULL;
	}
};

node* insert(node* root, int k)
{
	if (root==NULL)  return new node(k);
	else
	{
		if (k < root->data)
		{
			root->left = insert(root->left,k);
		}
		else
		{
			root->right =  insert(root->right,k);
		}
	}
	return root;
}


void inorder(node *root, vector<int>&A)
{
	while (root!=NULL)
	{
		if (root->left!=NULL)
		{
		        node* rightMost = root->left;
			while(rightMost->right!=NULL && rightMost->right != root)
			{
				rightMost = rightMost->right;
			}
			if (rightMost->right  == NULL)
			{
				rightMost->right  = root;
				root = root->left;
			}
			else if  (rightMost->right ==  root)
			{
				A.push_back(root->data);
				cout<<root->data<<" ";
				rightMost->right = NULL;
				root = root->right;
			}
		}
		else
		{
			A.push_back(root->data);
			cout<<root->data<<" ";
			root = root->right;
		}
	}
}


void preorder(node *root, vector<int>&A)
{
        stack<node*>st;

	st.push(root);
	int i=0;
	while(!st.empty())
	{
		node* X= st.top();
		st.pop();
		cout<<  "X: "<<X->data<<", A[i]: "<<A[i]<<"\n";
		X->data = A[i];
		
		i++;
		if  (X->left != NULL && X->right !=NULL)
		{
			st.push(X->right);
			st.push(X->left);
		}
	}
}

// 1 2 3 4 5 6 7
// 1

int main()
{
	node*  root  = new node(4);
	root->left  =  new node(2);
	root->right = new node(6);
	root->left->left = new node(1);
	root->left->right = new node(3);

	root->right->left = new node(5);
	root->right->right = new node(7);	

	vector<int>A;
	inorder(root,A);
	cout<<"\n\n\n";


	preorder(root,A);
	inorder(root,A);
	cout<<"\n\n\n";

	return  0;
}

























