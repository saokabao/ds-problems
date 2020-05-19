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

	node (int num)
	{
		data  = num;
		left=right=NULL;
	}
};


void inorder(node  *root) //  without  stack and without recursion
{
	if (root == NULL) return;
	while (root != NULL)
	{
		if (root->left != NULL)
		{
			node *rightMost = (root)->left;
			node *tmp = (rightMost->right);

			while (tmp != NULL && tmp != root)
			{
				rightMost = tmp;
				tmp = tmp->right;
			}

			if (tmp == root)
			{
				rightMost->right = NULL;
				cout  << root->data << " ";
				root = root->right;
			}
			else
			{
				rightMost->right = root;
				root  = root->left;
			}
		
		}
		else
		{
			cout << root->data <<" ";
			root = root->right;
		}
	}
}


void bstToDll(node  *root, node  **head, node **tail)
{
	if  (root  == NULL)  return;

	bstToDll(root->left,  head, tail);

	if (*head == NULL)
	{
		cout << "\nroot = "<<root->data;
		*head = root;
		*tail = root;
	}
	else
	{
		cout  <<"\nroot = " <<root->data<<"\n"; 
		(*tail)->right = root;
		cout<<"tail->right = "<<(*tail)->right->data<<"\n";
		 root->left  = *tail;
		 *tail  = root;
	}

	bstToDll(root->right, head, tail);
}


void  printDll(node *root)
{
	if (root == NULL) return;
	cout<<root->data<<"--";
	printDll(root->right);
}


void printDllReverse( node *tail)
{
	if (tail ==  NULL)  return ;
	cout << tail->data << "--";
	printDllReverse(tail->left);
}

int main()
{
	node *root = new node(15);
	root->left = new node(10);
	root->right = new node(25);

	root->left->right = new node(12);
	root->left->left = new node(5);

	root->right->right = new node(30);
	root->right->left  = new node(20);


	inorder(root);

	cout<<"\n\n";

	node *head=NULL , *tail=NULL;
        bstToDll(root, &head, &tail);

	cout<<"DLL ::\n";
	printDll(head);
	
	cout<<"\n\n reverse  DLL: \n";
	printDllReverse(tail);

   	cout << "\n\n";

	return 0;

}

