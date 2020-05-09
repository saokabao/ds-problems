
import java.lang.*;

class Node{
	int data;
	Node left, right;

	Node (int d){
		data =d;
		left = null;
		right = null;
	}
}

class Value{
	int max_size = 0;
	boolean is_bst = false;
	int min = Integer.MAX_VALUE;
	int max = Integer.MIN_VALUE;
}

class BinaryTree{

	static Node root;
	Value val = new Value();

	int largestBST(Node node){
		largestBSTUtil(node, this.val);

		return val.max_size;
	}

	int largestBSTUtil(Node node, Value val_ref){

		if (node ==null){
			val.is_bst = true;
			return 0;
		}	
		
		val_ref.max = Integer.MIN_VALUE;

		int lsize, rsize;
		boolean lstBst=false, rstBst= false;

		lsize = largestBSTUtil(node.left, val);

		if (val_ref.max < node.data && val_ref.is_bst){
			lstBst = true;
		}

		int leftMin = val_ref.min;

		val_ref.min = Integer.MAX_VALUE;

		rsize = largestBSTUtil(node.right, val_ref);

		if (val_ref.is_bst && val_ref.min > node.data){
			rstBst = true;
		}

		if (leftMin < val_ref.min) val_ref.min = leftMin;

		if (node.data < val_ref.min) val_ref.min = node.data;

		if (node.data > val_ref.max) val_ref.max = node.data;

		if (lstBst && rstBst){
			if (val_ref.max_size < (lsize + rsize +1))
				val_ref.max_size = lsize  + rsize +1;
			return lsize+rsize+1;
		}
		else{
			val_ref.is_bst = false;
			return 0;
		}
	}

	public static void main(String[] args){
		BinaryTree tree = new BinaryTree();
		BinaryTree.root = new Node(50);
		BinaryTree.root.left = new Node(10);
		BinaryTree.root.right = new Node (60);
		BinaryTree.root.left.left =  new Node (5);
		BinaryTree.root.left.right = new Node (20);
		BinaryTree.root.right.left = new Node (55);
		BinaryTree.root.right.right = new Node (70);
		BinaryTree.root.right.left.left = new Node (45);
		BinaryTree.root.right.right.left = new Node (65);
		BinaryTree.root.right.right.right = new Node (80);

		System.out.println("Largest BST subtree in the input binary tree is " + tree.largestBST(root));

	}
}
