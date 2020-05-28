/*
 * Post-order traversal of a a binary tree is tricky to write in
 * iterative manner. The trick is very small but doesn't really come
 * up to mind because we dont understand various behaviors of stack.
 * Last-in-first-out LIFO is the soul of stack but there are other non obvious
 * parts of it which would only be understood untill thought upon very 
 * carefully.  
 *
 * The skill of problem solving can only be improved by careful introspection of our
 * unsuccessful/half-hearted efforts in wrong direction. It won't matter how many problems
 * you solve per day if you are not analysing why specifically you weren't able to solve a problem.
 * After looking at the solution of every unsolved problem, we have to pin point the
 * wrong/narrow approach and thought and not repeat it again. 
 *
 * It is not necessary that if you have learnt a concept, you will certainly be able to
 * solve any problem related to the concept. Maybe easy ones. but not the ones which are tricky,
 * if you do not improve your ps skill. If you dont nurture your though process, no amount of
 * solved problem will improve my cognitive abilities.
 * 
 * Learn java stack
 * pop(): returns top and pops from stack. 
 * peek(): just peeks into stack top and doesnt pop.
 * push(); pushe element onto stack.
 * empty(): returns true if stack is empty
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

class GFG{
	static node root;

	static void postorder(node A){
		Stack<node> stack = new Stack<>();

		while (A!=null || !stack.empty()){

			while (A!=null){
				if (A.right !=null) {
					stack.push(A.right);
				}
				stack.push(A);
				A= A.left;
			}

			A = stack.pop();
			if (!stack.empty() && A.right == stack.peek()){
				node B = stack.pop();
				stack.push(A);
				A = B;
			}else{ 
				System.out.println(A.data);
				A=null;
			}
		}
	}

	static void postorder2(node A){
		Stack<node> stack = new Stack<>();

		while (A!=null || !stack.empty()){
			while (A!=null){
				stack.push(A);
				stack.push(A);
				A= A.left;
			}

			A = stack.pop();
			if (!stack.empty() && A == stack.peek()) A = A.right;
			else {
				System.out.println(A.data);
				A=null;
			}

		}
	}

	public static void main(String args[]){
		root = new node(15);
		root.left = new node(10);
		root.right = new node(25);

		root.left.left = new node(5);
		root.left.right = new node(12);

		root.right.left= new node(20);
		root.right.right = new node(30);

		postorder2(root);
	}
}
