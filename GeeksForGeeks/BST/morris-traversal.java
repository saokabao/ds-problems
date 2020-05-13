
import java.lang.*;

class Node{
	int data;
	Node left,right;

	Node(int num){
		data=num;
		left=right=null;
	}
}

class morris{

	static Node root;

	public static void inorder(){
		Node curr = root;

		while  (curr != null){
			if (curr.left == null){
				System.out.println(curr.data);
				curr = curr.right;
			}
			else{
				Node leftS = curr.left;
				while (leftS.right != null && leftS.right != curr){
					leftS = leftS.right;
				}

				if (leftS.right == null){
					leftS.right =  curr;
					curr = curr.left;
				}
				else{
					leftS.right =  null;
					System.out.println(curr.data);
					curr = curr.right;
				}
			}
		}
	}
	public static void main(String args[]){
		root = new Node(15);
		root.left = new Node(10);
		root.right = new Node(25);
		root.left.right = new Node(12);
		root.left.left = new Node(5);
		root.right.left = new  Node(17);
		root.right.right =  new Node(30);

		inorder();

	}
		
}


