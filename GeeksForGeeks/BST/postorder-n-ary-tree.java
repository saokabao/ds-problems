/*
 * To print postorder traversal of n-ary tree where each node
 * can have any number of nodes. 
 *
 * The algorithm to solve is similar to postorder-single-stack solution 
 * of binary tree. Except here, we will push a pair (node, index) onto stack
 * and will check whether stack.popped is a parent of stack.top using stack.top's
 * index. 
 *
 * Pushing logic is to push all children but one in reverse order onto stack.
 * Then push A node. and make A=A.children[0].
 *
 * */

import java.util.*;

class node{
	int data;
	ArrayList<node> children;

	node (int num){
		data =num;
		children = new ArrayList<>();
	}
}

class pair{
	node first;
	int second;

	pair(node A, int index){
		first=A;
		second=index;
	}
}

class GFG{
	static node root;

	static void postorder(pair A){
		Stack<pair> stack = new Stack<>();
	
		while (A!=null || !stack.isEmpty()){
			while (A!=null){
				int n = A.first.children.size()-1;
				for (int i=n;i>0;i--){
					stack.push(new  pair(A.first.children.get(i), i));
				}
				stack.push(new pair(A.first,0));
				if (n>0){
					A = new pair(A.first.children.get(0),0);
				}else{
					A = null;
				}
			}

			A = stack.pop();
			int m = A.first.children.size()-1;

			if (!stack.isEmpty() && 
			    stack.peek().second <= m &&
			    A.first.children.get(stack.peek().second) == stack.peek().first){
				pair B = stack.pop();
				stack.push(A);
				A = B;		
			    }
			else{
				System.out.println(A.first.data);
				A =  null;
			}
		}
	}

	public static void main(String args[]){
             root = new node(15);
	     root.children.add(new node(4));
	     root.children.add(new node(5));
	     root.children.add(new node(6));

	     root.children.get(0).children.add(new node(1));
	     root.children.get(0).children.add(new node(2));
	     root.children.get(0).children.add(new node(3));

	     root.children.get(2).children.add(new node(11));
	     root.children.get(2).children.add(new node(35));

	     postorder(new pair(root,0));
	}
}













