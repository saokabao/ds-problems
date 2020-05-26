/*
 * Find the dead-end in a BST.
* A dead end is a node (leaf/non-leaf) in bst under which you cant add
 * further node.   Assume only positive nodes can be added onto the tree.
 * A node.data>=1;
 *
 * */


class node{
	int  data;
	node left,right;

	node(int num){
		data =num;
		left=right=null;
	}
}


class GFG{
	static node root;

	static boolean isDeadEndPresent(node A , int left, int right){
		if (A==null){
//		       	if (left>=right) return true; uncomment this if you want non leaf  one side dead-ends.
			return false;
		}

		if (left  == right){
			System.out.println("Dead-end : " + A.data);
		       	return true;
		}

		return  (isDeadEndPresent(A.left, left, A.data-1) ||
			 isDeadEndPresent(A.right, A.data+1, right));

	}

	public static void main(String args[]){
		root= new node(4);
		root.left = new node(3);
		root.left.left = new node(2);
		root.left.left.left = new node(1);
		

		if(isDeadEndPresent(root,1,Integer.MAX_VALUE)){
			System.out.println("It contains dead-end");
		}else{
			System.out.println("No dead-ends");
		}
	}
}
