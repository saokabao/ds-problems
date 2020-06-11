/*
 * Sort an array of integers which is already partially sorted in order K.
 * Any integer  is at most  K distance away from  its position in the fully
 * sorted array.
 *
 * Solution is sliding window  with  a priority  queue. Priority  queue can be
 * implemented using self balancing BST or  Heap.
 *
 * 1. We maintain a window  of K elements and put all of it into PQ. O(K)
 * 2. Extract  minimum from PQ and put it into start index of window. O(logK)
 * 3. Slide window by one position  by adding a new element from array  to PQ.
 * 4. steps  2 and 3, slides window by one position.
 * 5. Do this  untill window can be  slided anymore. 
 * 6. Then put elements from PQ one by one onto array.
 * 7. 
 *
 * Java priority queue:
 * 1. add : adds element onto PQ.
 * 2. peek(): Returns but not removes highest priority  element.
 * 3. poll(): Returns and removes highest priority element.
 * 4. size(): Returns size of the queue.
 * */




import java.util.*;

class GFG{
	public static void main(String args[]){
		int arr[] = {10, 9, 8, 7, 4, 70, 60, 50};
		int n = arr.length;
		int k = 4;

		PriorityQueue<Integer> queue  = new PriorityQueue<>();
		//assume k<n
		for(int  i=0;i<k+1;i++){
			queue.add(arr[i]);
		}

		//0 , k 
		//1, k+1
		//2, k+2
		//
		//n-k-2   
		//n-k-1   n-1
		
		for(int  i=k+1;i<n;i++){
			arr[i-k-1] = queue.poll();
			queue.add(arr[i]);
		}
		
		for(int i=n-k-1; i<n;i++){
			arr[i] = queue.poll();
		}

		for(int i=0;i<n;i++){
			System.out.println("--" +arr[i]);
		}


	}

}
