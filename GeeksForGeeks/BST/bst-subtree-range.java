import java.lang.*;

class node{
	int data;
	node left,right;

	node(int  num){
		data  =  num;
		left=right=null;
	}
}

class Value{
	int leftMost,rightMost;
	int ans;

	Value(){
		leftMost  = Integer.MAX_VALUE;
		rightMost = Integer.MIN_VALUE;
		ans  =0;
	}
}

class subtreeRange{
	static  node root;
	static Value value  =  new Value();

	static node insert(node A, int num){
		if  (A ==null) return new node(num);

		if (num < A.data){
			A.left = insert(A.left, num);
		}else{
			A.right = insert(A.right,num);
		}
		return A;
	}


	static  int subtreeCount(node A, Value value, int L,  int R){
		if (A == null) return  0;

		int leftCount = subtreeCount(A.left, value, L,R);

		value.leftMost = Math.min(A.data,value.leftMost);

		int temp_min = value.leftMost;

		value.leftMost = Integer.MAX_VALUE;

		int rightCount = subtreeCount(A.right, value,L,R);

		value.rightMost = Math.max(A.data, value.rightMost);

		value.leftMost = temp_min;
		
		if  (value.leftMost >= L && value.rightMost <=  R){
			System.out.println("BST root : " + A.data);
			return leftCount+rightCount+1;
		}

		return leftCount+rightCount;
	}

	static boolean subtreeCountOpt (node A, int L, int R, Value value){
		if (A== null)  return true;
		
		boolean leftSubtree  = subtreeCountOpt(A.left, L, R, value);
		boolean rightSubtree = subtreeCountOpt(A.right,L,R,value);
		if (leftSubtree && rightSubtree && A.data>=L && A.data<=R){
			System.out.println("BST Root opt: " + A.data);
			value.ans++;
			return true;
		}
		return false;
	}

	static void  inorder(node A){
		if (A==null) return;
		inorder(A.left);
		System.out.println(A.data + "--");
		inorder(A.right);
	}

	public static void main(String args[]){
		root = new node(15);
		root = insert(root,10);
		root =  insert(root,25);
		root = insert(root,5);
		root = insert(root,12);
		root = insert(root,20);
		root = insert(root,30);

		System.out.println("Inorder: ");
		inorder(root);

		 subtreeCountOpt(root, 20,30, value);

		System.out.println("total number of subtrees  under given range: " + value.ans);

	}
}
