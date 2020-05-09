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

	node (int val):data(val),left(NULL),right(NULL){}
};


void inorder(node *root)
{
	if (root == NULL)
	{
		return ;
	}

	inorder(root->left);
	pl(root->data); pl(" ");
	inorder(root->right);
}


void insert(node*  &head, int data)
{
	if (head  ==   NULL)
	{
		head = new node(data);
		return;
	}
	if (data < head->data) insert(head->left, data);
	else insert(head->right, data);
}

void BstToArray(node *first, vector<int> &A)
{
	if (first == NULL) return;
	BstToArray(first->left,A);
	A.push_back(first->data);
	BstToArray(first->right,A);
}

void pairsInBst(node *first, node *second, int sum)
{

	vector<int> A, B;
	BstToArray(first,A);
	BstToArray(second,B);

	int n = A.size();
	int m = B.size();

	int left = 0 , right = m-1;
	while(left < n && right>=0)
	{
		if (A[left]  + B[right] == sum)
		{
			pl(A[left]); pl(" "); pl(B[right]); pl("\n");
			left++; right--;
		}
		else if (A[left]+ B[right] < sum)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
}

int main()
{
      node *first = new node(8);
      insert(first, 10);
      insert(first, 3); 
      insert(first, 6);     
      insert(first, 1);
      insert(first, 5);
      insert(first, 7);
      insert(first, 14);
      insert(first, 13);

	      ;
      node *second = new node(5);

      insert(second, 18);
      insert(second, 2);
      insert(second, 1);
      insert(second, 3);
      insert(second, 4);

      inorder(first);
      nl;nl;
      inorder(second);
      nl;nl;

      int sum; cin>>sum;
      pairsInBst(first, second,  sum);

      return 0;
}

