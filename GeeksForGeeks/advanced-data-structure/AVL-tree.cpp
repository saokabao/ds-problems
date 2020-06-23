
/*  CKMKC
 *  AVL Tree: Self balancing binary search tree
 *  It's a regular simple BST with augmented methods (insertion and deletion)
 *  and augmented nodes. (with height)
 *
 *  Insertion:
 *   Let's assume we are inserting W. On ancestral path of W,
 *   Z got imbalanced. 
 *   Y is child of Z on the path to W.
 *   X is  grandchild of Z on the path to W.
 *
 *             Z                                           Y
 *           /   \       				 /   \
 *         Y      T1      Right Rotate 		        X     Z
 *        / \             ============>>>              / \   /  \
 *       X   T2					      T3 T4  T2  T1
 *      / \
 *     T3 T4 
 *
 *   Case 1. LEFT/LEFT : Right Rotate, child(Y) becomes local root.
 *   Y and X are  both left child.
 *
 *   T3 > X >T4 > Y >T2 > Z > T1   ==>  T3 > X > T4 > Y > T2 > Z > T1
 *
 *   
 *   Case 2. LEFT/RIGHT: X becomes local root.
 *   Y is left child. X is right child. 
 *
 *      Z						Z   				      X
 *    /  \					      /   \	                            /   \    
 *   Y   T1              LEFT rotate                 X     T1				   Y     Z	
 *  / \                  ============>             /  \		    RIGHT Rotate          /\ 	/  \
 * T2  X 					  Y    T4            ===========>        T2 T3  T4  T1
 *    / \					 / \
 *   T3  T4 					T2  T3
 *
 * T2 > Y > T3 > X >  T4 > Z > T1        ====>   T2 > Y > T3 > X > T4 > Z > T1
 *
 *
 *   Case 3: RIGHT RIGHT: LEFT ROTATE: Y becomes local root.          
 *  
 *     Z		     LEFT Rotate              Y	
 *   /   \                   ============>          /   \
 *  T1    Y 					   Z 	 X
 *       / \					 /  \	/ \
 *      T2  X					T1  T2	T3 T4
 *         / \
 *        T3  T4  
 *
 * T1 > Z > T2 > Y > T3 > X > T4          ======>      T1 > Z > T2 > Y > T3 > X > T4
 *
 *
 *   Case 4: RIGHT LEFT: X becomes local root.
 *    
 *     Z 					Z 						X
 *   /  \          Right Rotation              /  \      Left Rotation            	      /   \	
 *  T1   Y         ==============>	      T1   X	 ==================>                 Z     Y
 *      / \     				  / \					    / \   / \
 *     X   T2					 T3  Y					  T1  T3 T4  T2	 	
 *    / \  					    / \	
 *   T3 T4  					   T4  T2	
 *
 *
 * T1 > Z > T3 > X > T4 > Y  > T2         ===================>     T1 >  Z > T3 > X > T4 > Y > T2
 *
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

class node
{
	public:
	int key;
	int height;
	node *left, *right;

	node(int val)
	{
		key =val;
		height =1;
		left=right=NULL;
	}

};

	int  getHeight(node *A)
	{
		if (A==NULL) return 0;
		else return A->height;
	}

       
        int getBalance(node *A)
	{
		if (A == NULL) return 0;
		else return getHeight(A->left) - getHeight(A->right);
	}

	node* leftRotate(node *Y)
	{
		/*
		 *          Z				Z
		 *         / \ 			       / \
		 *        Y   T1		      T1  Y	
		 *       / \             or              / \
		 *	T2  X 			        T2  X
		 *	   / \				   / \	
		 *	  T3  T4			  T3  T4
		 * */

		node *X = Y->right;
		node *T3 = X->left;

		X->left = Y;
		Y->right = T3;

		Y->height =  max(getHeight(Y->left), getHeight(Y->right)) +1 ;
                X->height  = max(getHeight(X->left), getHeight(X->right)) +1 ;
		return X;
	}

	node* rightRotate(node *Y)
	{
		/*
		 *        Z 				   Z
		 *       / \				 /   \
		 *      T1  Y                 or        Y     T1
		 *         / \                         / \ 
		 *        X   T2 		      X   T2
		 *       / \                         / \
		 *      T3 T4                       T3  T4
		 *
		 * */
		node  *X = Y->left;
		node *T4 = X->right;

		X->right = Y;
		Y->left = T4;

		Y->height =  max(getHeight(Y->left), getHeight(Y->right)) +1 ;
                X->height  = max(getHeight(X->left), getHeight(X->right)) +1 ;
		return X;
	}


	node* insert(node *A,int key)
	{

		if  (A==NULL) return  new  node(key);
		else if (key < A->key)
		{
			A->left = insert(A->left, key);
		}
		else
		{
			A->right = insert(A->right, key);
		}
	
	        A->height = 1 + max (getHeight(A->left), getHeight(A->right));
		int balance = getBalance(A);
 
		//left left
//	        cout<<"node: "<<A->key<<" , balance: "<< balance<<endl;
		if (balance > 1 && key < A->left->key )
		{
			return  rightRotate(A);
		}
		//left right
		else if (balance > 1 && key > A->left->key)
		{
			A->left  = leftRotate(A->left);
			return rightRotate(A);
		}
		//right left
		else if (balance < -1 && key < A->right->key)
		{
			A->right = rightRotate(A->right);
			return leftRotate(A);
		}
		//right right
		else if (balance < -1 && key > A->right->key)
		{
			return leftRotate(A);
		}

		return A;
	}

        node* getMin(node *root)
	{
		while(root->left!=NULL) root = root->left;
		return root;
	}

	node* remove(node* root, int key)
        {
		if (root == NULL) return NULL;
		else
		{
			if (key < root->key)
			{
				root->left = remove(root->left,key);
			}
			else if (key > root->key)
			{
				root->right = remove(root->right, key);
			}
			else
			{
				node *temp  = root;
				if (root->left == NULL)
				{
					root = root->right;
					delete temp;
				}
				else if (root->right == NULL)
				{
					root = root->left;
					delete temp;
				}
				else
				{
					node* succ = getMin(root->right);
					root->key = succ->key;

					root->right = remove(root->right, succ->key);
				}

			}
			if (root == NULL) return NULL;

			root->height = max(getHeight(root->left) , getHeight(root->right)) + 1;

			int balance = getBalance(root);
		
		        // left left	
			if (balance > 1 && getBalance(root->left) >= 0)
			{
                               return leftRotate(root);								
			}

			// left right
			if (balance > 1 && getBalance(root->left) < 0)
			{
				root->left  = leftRotate(root->left);
				return rightRotate(root);
			}

			//right right
			if (balance < -1 && getBalance(root->right) < 0 )
			{
				return leftRotate(root);
			}

			//right left
			if (balance < -1 && getBalance(root->right) >= 0)
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);

			}
			return root;
		}
	}


int main()
{
	node *root = new node(15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,30);
	root = insert(root,40);
	
	cout<<"root after 40: " << root->key<<"\n";
	root = insert(root,50); 


	cout<< "root after 50: " << root->key<<"\n";
	root = remove(root,15);
	cout<< "root after remove 15: " << root->key<<"\n";
	return 0;
}

