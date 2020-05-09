import java.util.*;

class solution{
	static class Node{
		int data;
		Node left, right;
	}

	static Node newNode(int num){
		Node temp = new Node();
		temp.data = num;
		temp.left = temp.right = null;
		return temp;
	}

	static Node insert(Node head, int num){
		if (head == null){
			head = newNode(num);
			return head;
		}
		if (num < head.data){
		       	Node left = insert(head.left,num);
			head.left = left;
		}
		else{
			Node right = insert(head.right, num);
			head.right = right;
		}
		return head;
	}

	static void inorder(Node head){
		if (head == null) return;
		inorder(head.left);
		System.out.println(head.data + " -->");
		inorder(head.right);
	}

	static void bstToVector(Node head, Vector<Integer> A){
		if (head == null) return;
		bstToVector(head.left,A);
		A.add(head.data);
		bstToVector(head.right,A);
	}

	static void pairSum(Node first, Node second, int sum){
		Vector<Integer> A = new Vector<Integer> ();
		Vector<Integer> B = new Vector<Integer> ();

		bstToVector(first,A);
		bstToVector(second,B);

		int n  = A.size();
		int m = B.size();

		int left =0, right = m-1;
		while (left < n && right>=0){
			if (A.get(left) + B.get(right) == sum){
				System.out.println(" sum pair: " + A.get(left)  +" , " +B.get(right) + "\n");
				left++;
				right--;
			}
			else if (A.get(left) + B.get(right) < sum){
				left++;
			}
			else{
				right --;
			}
		}

	}

	public static void main(String args[]){
		Node first = newNode(8);
		first = insert(first,10);
		 first = insert(first,3);
		  first = insert(first,6);
		   first = insert(first,1);
		    first = insert(first,5);
		     first = insert(first,7);
		      first = insert(first,14);
		       first = insert(first,13);

	inorder(first);
	System.out.println("\n\n\n");



	Node second = newNode (5);	 
  	second = insert(second,18);
        second = insert(second,2);
	second = insert(second,1);
        second = insert(second,3);
 	second = insert(second,4);

	 inorder(second);
	 System.out.println("\n\n\n");

	int sum =10;
	pairSum(first,second, sum);	

	}
}
