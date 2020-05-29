/*
 * Given an input array of integers, compute whether
 * it can represent a preorder traversal of a BST.
 *
 * Next Greater element using stack:
 * Push A[i] onto stack if Stack.top > A[i]
 * if A[i] > Stack.top, pop() till A[i] < Stack.top and then push A[i]
 * All the popped element's NGE will be A[i]. 
 *
 * Algorithm to determine whether an  array  represents preorder og BST:
 *
 * root = -INF;
 *  1.if A[i] > root, return false. It aint no preorder of BST.
 *
 *  2. Pop stack while( A[i] > stack.top () &&  stack.empty()==false)
 *
 *  3. last popped element becomes root.
 *
 *  4. push  A[i] onto stack.
 *
 *  If false is not reuturned on step1, it is a preorder of a fockin BST.
 *
 * I have no fockin idea as to why it works, who the fock can come up   with this
 * during an  interview. The world is screwed up if we ask this in an  interview.
 *
 * */

import java.util.Stack;


class GFG{

	static boolean  isBST(int[] A){
		int n   = A.length;
		if (n==0 || n==1 || n==2) return true;

		Stack<Integer> stack = new  Stack<>();

		stack.push(A[0]);
		int root = Integer.MIN_VALUE;

		int i=1;
		while(i<n){
			if (A[i] < root) return false;

			while (!stack.isEmpty() && A[i] > stack.peek()){
				root = stack.pop();
			}
			stack.push(A[i]);
			i++;
		}

		return true;
	}

	public static void main(String args[]){
		int[] A = {18,12,2,13,24,13,26};

		if (isBST(A)){
			System.out.println("Its a focking BST");
		} else{
			System.out.println("It aint no focking BST");
		}
	}
}


























