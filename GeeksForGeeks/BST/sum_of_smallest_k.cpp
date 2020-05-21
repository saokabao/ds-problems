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
};


//Inorder traversal can be done iteratively or recursively
//Iterative is morris.
//
void smallestK(node *root, int &sum, int K)
{
	if (root == NULL) return;
	smallestK(root->left, sum,K);
	if (K>=0)
	{
		sum+=root->data;
		K--;
	}
	smallestK(root->right, sum,K);
}

//Next idea is to store number of nodes in leftSubtree  of the node
//and sum of nodes in the leftsubtree of the node.
//if K < leftSubtreeCount , then traverse only left.
//if k == leftSubtreeCount, then return sum.
//if k > leftSubtreeCount, then traverse rightSubtree with k  = k-leftSubtreeCount


struct mnode
{
	int data,leftsum,leftcount;
	mnode *left,*right;

	mnode(int num)
	{
		data = num;
		leftsum=leftcount=0;
		left=right=NULL;
	}

};

void inorder(mnode *root)
{
	
	while (root != NULL)
	{
		if (root->left !=  NULL)
		{
			mnode *rightMost  =  root->left;
			while (rightMost->right != NULL && rightMost->right!=root)rightMost  = rightMost->right;

			if (rightMost->right == NULL)
			{
				rightMost->right = root;
				root = root->left;
			}
			else if (rightMost->right == root)
			{
				rightMost->right = NULL;
				pl(root->data); pl("--");
				root = root->right;
			}
		}
		else
		{
			pl(root->data);pl("--");
			root = root->right;
		}
	}
}


mnode* insert(mnode *root, int num)
{
	if (root == NULL) return new mnode(num);

	if (num < root->data )
	{
		root->leftcount+=1;
		root->leftsum+=num;

		root->left = insert(root->left, num);
	}
	else
	{
		root->right = insert(root->right, num);
	}

	return root;
}

void smallestKSumOpt(mnode *root, int &sum, int &K)
{
	if (root == NULL) return;
        
	if (K==0) return;

	if (root->left == NULL)
	{
		sum += root->data;
		K--;
		smallestKSumOpt(root->right, sum, K);
	}
	else
	{
		if (K < root->leftcount)
		{
			smallestKSumOpt(root->left, sum, K);
		}
		else if (K == root->leftcount)
		{
			sum += root->leftsum;
			K = K-root->leftcount;
			return;
		}
		else
		{
			sum += root->leftsum + root->data;
			K -= root->leftcount;
			K--;
			smallestKSumOpt(root->right, sum ,K);

		}
	}
}

int main()
{
	mnode *root = new mnode(15);
	root = insert(root,10);
	root = insert(root,25);
	root = insert(root,5);
	root = insert(root,12);
	root = insert(root,20);
	root = insert(root,30);

	pl("\n\nInorder:\n\n");
	inorder(root);
	nl;nl;

	int sum =0, k;

	while(1){
		sum=0;
		cin>>k;
	smallestKSumOpt(root,sum,k);

	pl("smallest k Sum is :"); pl(sum); nl;nl;
	}
	return  0;

}

































