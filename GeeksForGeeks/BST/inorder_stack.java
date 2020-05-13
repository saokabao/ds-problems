import java.lang.*;
import java.util.*;


class Node{
	int data;
	Node left,right;

	Node(int num){
		data = num;
		left=right=null;
	}
}

class inorder{
	static Node root;

	static void InorderUtil(){
		Stack<Node> st = new Stack<Node> ();

		st.push(root);
		while (st.isEmpty() == false){
			
			while (st.peek().left != null){
				st.push(st.peek().left);
			}

			while(!st.isEmpty()){
				Node top = st.pop();
				System.out.println(top.data);
				if (top.right != null){
					st.push(top.right);
					break;
				}
			}
		}
	}

	public static void main(String args[]){
		root = new Node(15);
		root.left  = new Node(10);
		root.right  = new Node(25);
		root.left.right =  new Node(12);
		root.left.left = new Node(5);
		root.right.right = new Node(30);
		root.right.left  =new Node(20); 

		InorderUtil();
	}
}
