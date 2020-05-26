
class node{
	int data;
	node left,right;

	node(int num){
		data = num;
		left=right=null;
	}
}

class removeKeys{
	static node root;

	static void inorder(node A){
		while(A!=null){
			if (A.left!=null){
				node rightMost = A.left;
				while(rightMost.right != null && rightMost.right != A) rightMost = rightMost.right;

				if (rightMost.right == null){
					rightMost.right = A;
					A= A.left;
				}else if (rightMost.right == A){
					rightMost.right = null;
					System.out.println(A.data);
					A = A.right;
				}
			}else{
				System.out.println(A.data);
				A = A.right;
			}
		}
	}

	static node remove(node A,int L, int R){
		if (A== null) return null;

		A.left = remove(A.left, L,R);
		A.right = remove(A.right, L,R);

		if (A.data <L){
			return A.right;
			
		}else if (A.data>R){
			return A.left;
		}

		return  A;
	}

	static node insert(node A, int num){
		if (A==null) return new node(num);

		if (num < A.data){
			A.left = insert(A.left,num);
		}
		else A.right = insert(A.right, num);

		return A;
	}

	public static void main(String args[]){
		root = new node(15);
		int[] a = {10,25,5,12,20,2,7,11,14,18,22};
		for(int i=0;i<a.length;i++){
			root = insert(root,a[i]);
		}

		System.out.println("Inorder: ");
		inorder(root);

		root = remove(root, 7,15);

		System.out.println("New Inorder: ");

		inorder(root);


	}
}





























