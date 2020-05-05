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


node* newNode(int data)
{
	node *head = new node;
	head->data = data;
	head->left = NULL;
	head->right = NULL;
	return head;
}

void insert(node* &root, int data)
{
    if (root==NULL) root= newNode(data);
    else
    {
	if (data > root->data)
	{
		insert(root->right,data);
	}
	else
	{
		insert(root->left, data);
	}
    }
}

void inorder(node *root)
{
	if (root == NULL) return;
	inorder(root->left);
	pl(root->data); pl("--");
	inorder(root->right);
}

int largest_subtree_bst(node *root, int& min_ref, int& max_ref, int& max_size, bool& is_bst)
{
	if (root == NULL) 
	{
		is_bst = true;
		return 0;
	}

	bool left_flag  = false, right_flag = false;

	
	max_ref = INT_MIN;

	int leftCount = largest_subtree_bst(root->left, min_ref, max_ref, max_size, is_bst);

	if (is_bst && root->data > max_ref)
	{
		left_flag = true;
	}

        int min_till_now  = min_ref;

	min_ref = INT_MAX;

	int rightCount = largest_subtree_bst(root->right, min_ref, max_ref, max_size, is_bst);

	if  (is_bst && min_ref > root->data)
	{
		right_flag = true;
	}
	
	
	if (min_till_now < min_ref) min_ref = min_till_now;

	if (root->data < min_ref) min_ref  = root->data;

	if (root->data > max_ref) max_ref = root->data;


	if (left_flag  &&  right_flag)
	{
		is_bst = true;
		if  (max_size < (leftCount+rightCount+1))
			max_size = leftCount+rightCount+1;
		return leftCount + rightCount +1;
	}
	else
	{
		is_bst = false;
		return 0;
	}

}

int main()
{

	node *root = newNode(50);
	root->left = newNode(10);
	root->right = newNode(60);
	root->left->left = newNode(5);
	root->left->right = newNode(20);
	root->right->left = newNode(55);
	root->right->left->left = newNode(45);
	root->right->right = newNode(70);
	root->right->right->left = newNode(65);
	root->right->right->right = newNode(80);
	inorder(root);

	int min_ref=INT_MAX, max_ref=INT_MIN, max_size= INT_MIN;
	bool is_bst = false;
	int ans = largest_subtree_bst(root, min_ref, max_ref, max_size, is_bst);
	nl; pl("larget-subtree-bst : "); pl(max_size);nl;nl;

	return 0;
}

