import java.util.*;

class keyBst{
	static  class Node{
		int data;
		Node left,right;
	}

	static Node newNode(int  num){
		Node root = new Node();
		root.data = num;
		root.left = root.right=null;
		return root;
	}

	static void inorder(Node root){
		if (root==null)return;
		inorder(root.left);
		System.out.println(root.data + "-");
		inorder(root.right);
	}

	static Node insert(Node root, int num){

		if (root==null){
			root = newNode(num);
			return  root;
		}

		if (num < root.data){
			Node left = insert(root.left,num);
			root.left = left;
		}
		else{
			Node right = insert(root.right,num);
			root.right = right;
		}
		return root;
	}

	static void getKeys(Node root, int l, int r){
		if (root == null) return;

		if (l < root.data){
			getKeys(root.left, l, r);
		}

		if (root.data <= r && root.data>=l){
			System.out.println(root.data);
		}

		if (r > root.data){
			getKeys(root.right, l, r);
		}
	}


	public static void main(String args[]){
		Node root =  newNode(15);
		root =  insert(root,10);
		root = insert(root,25);
		root = insert(root,5);
		root = insert(root,12);
		root = insert(root,22);
		root =  insert(root,34);
		root = insert(root,23);
		root  = insert(root,3);
		root  = insert(root,2);
		root  = insert(root,9);

		getKeys(root, 1  ,10);

	}
}
