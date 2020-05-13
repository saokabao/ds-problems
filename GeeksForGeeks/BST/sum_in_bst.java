import java.util.*;

class sumBst{

	static class Node{
		int data;
		Node left, right;
	}

	static Node newNode (int num){
		Node head = new Node();
		head.data = num;
		head.left=head.right=null;
		return  head;
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
			Node right = insert(head.right,num);
			head.right = right;
		}
		return head;
	}

	static boolean findPairUtil(Node root, HashSet<Integer> lSet, int sum){
		if (root == null){
			return false;
		}

		if (findPairUtil(root.left, lSet,sum)){
			return true;
		}

		if (lSet.contains(sum-root.data)){
			int a = sum - root.data;
			System.out.println("Found pair: "+ a + " , " + root.data );
			return true;
		}else{
			lSet.add(root.data);
		}
		
		if (findPairUtil(root.right, lSet, sum)){
			return true;
		}
		return false;
	}

	static void findPair(Node root, int sum){
		HashSet<Integer> lSet = new HashSet<Integer>();

		if (findPairUtil(root, lSet, sum) == false){
			System.out.println("Sum-pair not found");
		}
	}

	public static void main(String args[]){
		Node root = newNode(15);
		root = insert(root,10);
		root = insert(root,20);
		root = insert(root,8);
		root = insert(root,12);
		root = insert(root,16);
		root = insert(root,25);

		int sum =28;
		findPair(root,sum);
	}

}
