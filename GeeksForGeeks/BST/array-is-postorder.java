/* My dear brain,
 *
 * In this problem , we have been given an array of integers.
 * We have to determine whether this array of integer can be a
 * level-order-traversal of a bst. 
 *
 * Inorder traversal of a BST: should be completely sorted.
 * Postorder traversal: kya pta?
 * Pre order traversal : kya pta?
 * Level order traversal: Queue! Queue! Queue!
 *
 * Solution approach:
 * How do you create level order traversal from a bst?
 * Using a queue, right? And in a bst each element belongs in a range. 
 * The root element can be in the range -INF to +INF. As we go down the tree,
 * the range of elements become finer and narrow. If range length is 0, that'd mean
 * you have hit a dead-end. 
 *
 *
 * First element of the array is pushed to Queue.
 * The arrayPointer points second array element. 
 * We check if ptr could be left child of, Q.top. If yes, we push ptr to Queue.
 * if not if ptr could be right child of Q.top, If yes, we push ptr to Queue.
 * Else pop Queue, and repeat.
 *
 * If we are able to consume all array elements, that means this is a valid
 * level order traversal, else not. 
 *
 * I dont know any other way to solve this problem.
 *
 * This is a read and implement.
 *
 *
 * */


import java.util.*;


class node{
	int data;
	int left, right;

	node(int num){
		data =num;
		left=Integer.MIN_VALUE;
		right = Integer.MAX_VALUE;
	}

	node(int num, int _left, int _right){
		data = num;
		left=_left;
		right = _right;
	}
}

class GFG{
	
	static boolean isBst(int A[]){
		int n = A.length;

		if (n==0) return true;

		Queue<node> Q = new LinkedList<node>();
		Q.add(new node(A[0]));

		int i=1;
		while (i<n){
			node top = Q.peek();
			Q.remove();

			if (A[i] >= top.left && A[i] <top.data){
				Q.add(new node(A[i],top.left, top.data-1));
				i++;
			}
			
			if  (i==n) return true;

			if (A[i] > top.data && A[i] <=top.right){
				Q.add(new node(A[i],top.data+1, top.right));
				i++;
			}
			
			if (i==n) return  true;
			if (Q.size() == 0){
				return false;
			}
	
		}
		
		return true;
	}

	public static void main(String args[]){
		int[] a = {15,10,25,5,12,20,30,2,7,11,22};

		if (isBst(a)){
			System.out.println("It is level order traversal of BST");
		}
		else{
			System.out.println("It's not level order traversal of BST");
		}
	}
}






























