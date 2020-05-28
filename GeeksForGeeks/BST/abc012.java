/* Post order iteration of tree using stack and 0,1,2.
 *
 * Algorithm:
 *
 * 1. push pair (root, 0) onto stack.
 *
 * while stack.isNotEmpty :
 *
 *   A = pop;
 *   if (A.b == 0)
 *      push (A,1)
 *      push(A.left,0)
 *
 *   if (A.b==1)
 *      push(A,2);
 *      push(A.right,0)
 *
 *   if (A,b==2)
 *       print A;
 *
 *  continue;
 *
 *
 * */

import java.util.Stack;

class node{
	int data;
	node left,right;

	node(int num){
		data=num;
		left=right=null;
	}
}

class pair {
	int second;
	node first;

	pair(node A, int B){
		first = A;
		second=B;
	}
}

class GFG{
	static node root;

	static void postorder(node A){
		Stack<pair> stack = new Stack<>();
		stack.push(new pair(A,0));

		while(!stack.empty()){

			pair curr = stack.pop();
			if (curr.second == 0){
				stack.push(new pair(curr.first,1));
				if (curr.first.left !=null) 
					stack.push(new pair(curr.first.left,0));
			}else if (curr.second ==1){
				stack.push(new pair(curr.first,2));
				if (curr.first.right!=null)
					stack.push(new pair(curr.first.right,0));
			}else if (curr.second ==2){
				System.out.println(curr.first.data);
			}
		}
	}
	public static void main(String args[]){
		root = new node (15);
		root.left= new node(10);
		root.right = new node(25);

		root.left.left = new node(5);
		root.left.right = new node(12);

		root.right.left = new node(20);
		root.right.right = new node(30);

		postorder(root);
		
	}
}



































