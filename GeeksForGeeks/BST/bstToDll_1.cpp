
/*
 * This is the  1st method in GFG to convert bst to  dll.
 * In this algorithm, we convert left subtree  into a dll.
 * Then  attach  root to the rightMost node of this dll. 
 * Wec convert rightSubtree to a dll. Find the  leftMost node
 * of the rightSubtree-dll and attach it as the successor of the root.
 * Voila, you are done. 
 * 
 * If we maintain  a tail pointer, we wouldn't  need to find rightMost node
 * and leftMost node in left and right subtree  respectivley.
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
	int  data;
	node *left,*right;

	node(int  num)
	{
		data=num;
		left=right=NULL;

	}
};


void inorder(node *root) //morris
{
	while (root != NULL)
	{
		if (root->left != NULL)
		{
			node *leftChild = root->left;

			while(leftChild->right != NULL && leftChild->right != root)
			{
				leftChild  = leftChild->right;
			}

			if (leftChild->right == NULL)
			{
				leftChild->right = root;
				root = root->left;
			}
			else if (leftChild->right == root)
			{
				leftChild->right = NULL;
				cout << root->data << "--";
				root = root->right;
			}
		}
		else
		{
			cout<< root->data<< "--";
			root = root->right;
		}
	}
}


void printToRight(node *root)
{
	if (root==NULL) return;
	cout  << root->data <<  "--";
	printToRight(root->right);
}

void printToLeft(node *root)
{
	if (root==NULL) return;
	cout  << root->data << "--";
	printToLeft(root->left);
}


void bstToDll(node *root)
{
	if (root == NULL) return;

	bstToDll(root->left);

	node *rightMost = root->left;
	while (rightMost != NULL && rightMost->right !=  NULL)
	{
		rightMost = rightMost->right;
	}

	if  (rightMost != NULL)
	{
		rightMost->right = root;
	}

	root->left = rightMost;

	bstToDll(root->right);
	
	node  *leftMost = root->right;
	while (leftMost != NULL && leftMost->left != NULL)
	{
		leftMost = leftMost->left;
	}

	if (leftMost != NULL)
	{
		leftMost->left  = root;
	}

	root->right  = leftMost;

}

int main()
{
	node *root = new node(15);
	root->left = new node(10);
	root->right = new node (25);
	root->left->left = new node(5);
	root->left->right  = new node(12);
	root->right->left = new node(20);
	root->right->right =  new node (30);

	cout<<"INorder:\n";
	inorder(root);
	cout<<"\n\n";

        bstToDll(root);
	while (root->left != NULL)root= root->left;

	cout <<"\n PrintToRight \n";
	printToRight(root);

        while (root->right!=NULL) root = root->right;

	cout<<"\n PrintToLeft \n";
	printToLeft(root);

	cout<<"\n\n";
	return 0;
}

