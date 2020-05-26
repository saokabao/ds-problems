/*
 * We can't do inorder traversal of a BST oone by one,
 * atleast not in a single thread. If you gots BST, inorder
 * gots to be stored, Theek hai?
 *
 *
 * */

class node{
	int data;
	node left,right;

	node(int num){
		data=num;
		left=right=null;
	}
}

class GFG{
	static node root;

	static node inorder(node A){
		while(A!=null){

		}
	}


	static boolean compareBst(node A, node B){

		node in1 = inorder(A);
		node in2 = inorder(B);
		while(in1 != null && in2 != null){
			if (in1.data != in2.data){
				return false;		
			}
			in1 = inorder(A);
			in2 = inorder(B);
		}
		return true;
	}

	public static void main(String args[]){
		//make two trees,
		//keep em same element wise, but not structure wise
		//call compare function on them
	}
}
