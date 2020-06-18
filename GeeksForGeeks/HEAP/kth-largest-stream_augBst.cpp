/*
 *  
 *  BST solution  to get the  kth largest  element  in a stream.
 *  We maintain a  BST  of size K, maintain max element and min  element.
 *  if bst size  is less  than K, simply  add the  element in bst.
 *  else if N > minBst, deleteKey and insertKey.
 *  
 *  Delete would be simpler than  a  regular  delete because
 *  we have to delete the minimum bst which is gauranteed to be a node
 *  with a single child or no child.
 *  
 *
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
	node *left, *right;

	node (int val)
	{
		data = val;
		left=right=NULL;

	}
};

node* insert(node *root, int key)
{
	if (root==NULL) return new node(key);
	else 
	{
		if (key < root->data)
		{
			root->left = insert(root->left, key);
		}
		else 
		{
			root->right = insert(root->right, key);
		}
	}
	return root;
}


int getMin(node *root)
{
	while(root->left != NULL)
	{
		root =  root->left;
	}
	return root->data;
}


int deleteMin(node **root)
{
	node* leftMost = (*root)->left;
	
	int min ;
	if (leftMost == NULL)
	{
		free(*root);
		*root = (*root)->right;
		if (*root != NULL)
		{
			min = getMin(*root);
		}
		else
		{
			min = INT_MAX;
		}
	}
	else
	{
		while(leftMost->left!=NULL)
		{
			root = &leftMost;
			leftMost = leftMost->left;
		}
		(*root)->left = leftMost->right;
		if (leftMost->right != NULL)
		{
			min = getMin(leftMost->right);
		}
		else
		{
			min  = (*root)->data;
		}		
		
	}
	return min;
}


int main()
{
	int k; cin>>k;
	int size =0, kth = INT_MAX;

	node  * root = NULL;
	while(1)
	{
		int t; cin>>t;
		if (size<k) 
		{
			kth   = min(kth,  t);
			root = insert(root,t);
			size++;
		}
		else
		{
			if (t > kth)
			{
				kth = deleteMin(&root);
				kth  = min(kth, t);
				root=insert(root,t);
			}
		}
		cout<<"kth  largest : " <<kth<<"\n";
	}
}

