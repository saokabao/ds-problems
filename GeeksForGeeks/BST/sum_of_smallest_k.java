class node{
	int data, leftcount, leftsum;
	node left,right;

	node(int num){
		data = num;
		leftcount=leftsum=0;
		left=right=null;
	}
}

class  Value{
	int sum;
	int K;

	Value(int num){
		sum=0;
		K=num;
	}
}

class sumK{
	static node root;
	static Value value = new Value(3);

	static node insert(node A, int  data){
		if (A == null) return new node(data);
		if (data < A.data){
			A.leftcount++;
			A.leftsum+=data;
			A.left  = insert(A.left,data);

		}
		else{
			A.right = insert(A.right,data);
		}
		return  A;
	}

	static void inorder(node A){
		if (A==null) return;
		inorder(A.left);
		System.out.println(A.data +"--");
		inorder(A.right);
	}

	static void smallestK(node A, Value value){
		if (A==null)  return;
		if (value.K==0) return;

		if (value.K < A.leftcount){
			smallestK(A.left,value);
		}else if (value.K == A.leftcount){
			value.K =0;
			value.sum += A.leftsum;
			return;

		}else{
			value.K -= A.leftcount;
			value.sum += A.leftsum;

			value.K--;
			value.sum += A.data;

			smallestK(A.right,value);
		}

	}

	public static void main(String args[]){
		root = new node(15);
		root = insert(root,10);
		root = insert(root,25);

		System.out.println("inorder : ");
		inorder(root);

		smallestK(root, value);

		System.out.println("\n\n Sum of k is: " + value.sum);

	}

}
