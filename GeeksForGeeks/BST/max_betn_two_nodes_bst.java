class solution{
	static class Node{
		int  data;
		Node left,right;
	}

	static Node newNode (int num){
		Node head = new Node ();
		head.data = num;
		head.left = head.right = null;
		return head;
	}

	static void insert(Node head, int num){
		Node p  = head, q = null;

		while (p!=null){
			q=p;
			if (num < p.data) p  =  p.left;
			else p = p.right;
		}

		if (q==null){
			head  = newNode(num);
		}
		else{
			if (num < q.data){
				Node left = newNode (num);
				q.left = left;
			} else{
				Node right = newNode (num);
				q.right = right;
			}
		}
	}

	static int maxelPath(Node head, int a){
		int ans  = a;

		while(head.data != a){
			ans = Math.max(head.data,a);
			if (a < head.data) head = head.left;
			else head =  head.right;
		}
		return ans;
	}

	static int maxElement(Node head, int a, int b){
		Node p = head;

		while ((a < p.data && b < p.data ) ||
			(a>p.data && b > p.data)){

			if (a < p.data && b < p.data){
				 p = p.left;
			}
			else if ((a>p.data && b > p.data)){
				 p = p.right;
			}
		}

		return  Math.max(maxelPath(p,a), maxelPath(p,b));

	}
	public static void main(String args[]){
		int arr[] = {18,36,9,6,12,10,1,8};
		int n = arr.length;

		Node head = newNode (18);

		for(int i=1;i<n;i++){
			insert(head, arr[i]);
		}

		System.out.println("\n Maximum element betn nodes is: " + maxElement(head, 36,18));

	}

}
