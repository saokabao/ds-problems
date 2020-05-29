
class node{
	int data; int leftCount;
	node left,right;

	node(int num){
		data =num;
		leftCount=0;
		left=right=null;
	}
}


class GFG{
	static node root;

	static node insert (node A, int num){
		if (A==null) return new node(num);

		if  (A.data == num){
			A.leftCount++;
		}
		else if (num <  A.data){
			A.leftCount++;
			A.left = insert(A.left,num);
		} else{
			A.right = insert(A.right,num);
		}
		return A;
	}

	static int rank(int X, node B){
			if (X == B.data){
				return B.leftCount;
			}else if (X > B.data){
				return B.leftCount + rank(X,B.right) + 1;
			} else{
				return rank(X,B.left);
			}
	}

	public static void main(String args[]){
		int[] A = {3,4,2,2,5,13,2,9,8,10};

		root  =  new node(3);

		for(int  i=1;i<A.length;i++){
			root = insert(root,A[i]);
		}
		System.out.println("Rank of 9 :" + rank(9,root));
	}

}
